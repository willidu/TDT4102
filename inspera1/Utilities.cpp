#include "Utilities.h"

string toGreek(string sentence)
{
    // BEGIN: 2a

    string result;
    for (char c : sentence)
    {
        if (isspace(c))
        {
            result += c;
        }
        else if (isalpha(c))
        {
            char newChar {static_cast<char>(static_cast<int>(c) + 2)};
            result += newChar;
        }
    }

    return result;
    
    // END: 2a
}

vector<vector<string>> loadSvada()
{
    // BEGIN: 2b

    vector<vector<string>> result (7);

    ifstream ifs {"SvadaWords.txt"};

    if (!ifs) {
        cout << "Cannot open file SvadaWords.txt" << endl;
    }

    string line;
    int group {0};

    while(getline(ifs, line))
    {
        if (line[0] == '|') { group++; }
        else
        {
            if (group > result.size())
            {
                vector<string> inner;
                result.emplace_back(inner);
            }

            result.at(group).push_back(line);
        }
    }

    return result;

    // END: 2b
}

string svadaGenerator(vector<vector<string>> svadaVec)
{
    // BEGIN: 2c1

    string result;

    for (int group {0}; group < svadaVec.size(); group++)
    {
        int wordIndex {randint(0, svadaVec.at(group).size()-1)};
        result += svadaVec.at(group).at(wordIndex);
        result += ' ';
    }

    return result;
    
    // END: 2c1
}