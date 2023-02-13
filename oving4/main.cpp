#include "tests.hpp"
#include "utils.hpp"
#include "mastermind.hpp"
#include "masterVisual.h"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int in {0};
    cout << "1: Run tests" << endl;
    cout << "2: Play Matermind game (terminal)" << endl;
    cout << "3: Play Matermind game (UI)" << endl;
    cin >> in;

    switch (in)
    {
    case 1: {
        testCallByValue();
        testCallByReference();
        testStudentStruct();
        testString();
        break;
    }
    
    case 2: {
        playMastermind();
        break;
    }

    case 3: {
        playMastermindVisual();
        break;
    }

    default:
        break;
    }
}
