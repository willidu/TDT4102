#include "ContractDataBase.h"

InsuranceContract ContractDataBase::getContract(int id)
{
    // BEGIN: 1b

    for (auto& c : contracts)
    {
        if (c.getId() == id)
        {
            return c;
        }
    }

    // END: 1b

    // Returning an empty contract if no contract with the given id is found.
    return InsuranceContract{};
}

int ContractDataBase::numberOfInsuranceType(InsuranceType type)
{
    // BEGIN: 1c

    int count {0};
    for (auto& c : contracts)
    {
        if (c.getInsuranceType() == type)
        {
            count++;
        }
    }

    return count;

    // END: 1c
}

int ContractDataBase::addContract(string holderName, InsuranceType insType, int value)
{
    // BEGIN: 1d 

    int id {1};
    for (auto& c : contracts)
    {
        if (c.getId() > id)
        {
            id = c.getId() + 1;
        }
    }
    contracts.emplace_back(holderName, insType, value, id);

    return id;

    // END: 1d
}

void ContractDataBase::saveContracts(string filename)
{
    // BEGIN: 1e

    ofstream ofs {filename};
    
    if (!ofs)
    {
        cout << "Cannot open file " << filename << "!" << endl;
    }

    for (auto& c : contracts)
    {
        ofs << c.getHolder() << ',' 
            << insuranceTypeToString(c.getInsuranceType()) << ','
            << c.getValue() << ','
            << c.getId() << ','
            << c.getInsuranceText() << '\n';
    }

    // END: 1e
}

void ContractDataBase::loadContracts(string filename)
{
    ifstream inFile{filename};
    if (!inFile)
    {
        error("Couldn't open file: ", filename);
    }

    string line;
    while (getline(inFile, line))
    {
        stringstream ss{line};
        char seperator;

        string holderName;
        getline(ss, holderName, ',');

        string insType;
        getline(ss, insType, ',');

        int value;
        ss >> value;
        ss >> seperator;

        int id;
        ss >> id;
        ss >> seperator;

        string insuranceText;
        getline(ss, insuranceText, ',');

        contracts.push_back({holderName, stringToInsuranceType.at(insType), value, id, insuranceText});
    }
}
