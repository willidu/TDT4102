/*
Task 1e)
I chose to use inputInteger() in the function inputIntegersAndPrintSum()
since the numbers should not be printed to the terminal.

Task 2c)
In 2a we use a for loop since we know the number of iterations beforehand.
In 2b we use a while loop until the contition is no longer met (input == 0).

Task 2f)
Here we use a double as the currency conversion factor is not an integer.
Ie. we need decimal places as well.

Task 5c)
The error means that the C++ compiler does not know how to cout/print a whole vector.
It needs to be done element-wise.

Task 5d)
The error:
libc++abi: terminating with uncaught exception of type std::out_of_range: vector
The range is 1 too long. It is currently checking <= instead of <.
*/

#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "header.hpp"

int meny();

int main()
{
    int input = meny();

    switch(input) {
        case 0:
            break;

        case 1:
            inputAndPrintInteger();
            break;

        case 2: {
            int result = inputInteger();
            cout << "Du skrev: " << result << endl;
            break;
        }

        case 3:
            inputIntegerAndPrintSum();
            break;

        case 4: {
            cout << "------" << endl;
            for (int i = 0; i <= 15; i++) {
                cout << i << " er " << (isOdd(i) ? "odde" : "like") << endl;
            }
            cout << "------" << endl;
            break;
        }

        case 5: {
            int time = 0;
            cout << "Skriv inn en tid i sekunder: "; 
            cin >> time;
            printHumanReadableTime(time);
            break;
        }

        case 6: {
            int n = 0;
            cout << "Angi hvor mange tall som skal summeres: ";
            cin >> n;
            sumGivenIntegers(n);
        }

        case 7:
            sumIntegersInput();
            break;

        case 8: {
            double val = inputDouble();
            cout << "Du skrev: " << val << endl;
            break;
        }

        case 9:
            convertNOKtoEUR();
            break;

        case 10:
            multTable();
            break;
        
        case 11:
            solveQuadraticEquation();
            break;
        
        case 12:
            pythagoras();
            break;

        case 13: {
            cout << "Innskudd: ";
            int innskudd = inputInteger();
            cout << "Rente: ";
            int rente = inputInteger();
            cout << "Antall år: ";
            int antall = inputInteger();
            vector<int> saldo = calculateBalance(innskudd, rente, antall);
            printBalance(saldo);
            break;
        }

        default:
            break;
    }
}

int meny() {
    cout << "Velg funksjon:" << endl;
    cout << "0) Avslutt" << endl;
    cout << "1) Print et heltalltall" << endl;
    cout << "2) Skriv inn et heltall" << endl;
    cout << "3) Summer to heltall" << endl;
    cout << "4) Sjekk om heltallene 0 til 15 er odde" << endl;
    cout << "5) Regn tid fra sekunder" << endl;
    cout << "6) Summer gitt antall heltall" << endl;
    cout << "7) Summer uendelig antall heltall" << endl;
    cout << "8) Skriv inn et flyttall" << endl;
    cout << "9) Konverter NOK til EUR" << endl;
    cout << "10) Skriv ut gangetabellen" << endl;
    cout << "11) Løs andregradsligning" << endl;
    cout << "12) Pythagoras" << endl;
    cout << "13) Renters renter" << endl;
    cout << "Angi valg (0-13): ";

    int input = 0;
    cin >> input;
    return input;
}