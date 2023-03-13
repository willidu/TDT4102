#include "std_lib_facilities.h"
#include "InsuranceContract.h"
#include "ContractDataBase.h"
#include "Utilities.h"

//------------------------------------------------------------------------------'

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	ContractDataBase db{};
	db.loadContracts("DataBase.txt");
	InsuranceContract contract{"Jonas Lie", InsuranceType::Car, 1000, 1242, ""};
	//You can test your code under here

	cout << insuranceTypeToString(contract.getInsuranceType()) << endl;  // 1a ok
	cout << db.getContract(1234) << endl;  // 1b ok
	db.saveContracts("test.txt");  // 1e ok

	cout << toGreek("Alle, alle") << endl;  // 2a ok
	auto svadaVec = loadSvada();  // Funker IKKE
	cout << svadaVec.size() << ", " << svadaVec.at(0).size() << endl;  // ser greit ut det?

	cout << svadaGenerator(testSvadaGenerationVec) << endl;  // Funker

	// 2cb : Ser i test.txt at det funker sånn halvveis
	// Kanskje noe med \n eller?

	return 0;
}

//------------------------------------------------------------------------------
