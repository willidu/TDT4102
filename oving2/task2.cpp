#include "header.hpp"
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

void sumGivenIntegers(int numInt) {
    int sum = 0;
    for (int i = 0; i < numInt; i++) {
        int temp = 0;
        cout << "Input number (" << i+1 << "/" << numInt << "): ";
        cin >> temp;
        sum += temp;
    }
    cout << "Summen er " << sum << endl;
}
void sumIntegersInput() {
    int sum = 0;
    cout << "Skriv '0' for å avslutte." << endl;

    while(1) {
        int temp = 0;
        cout << "Input number: ";
        cin >> temp;
        
        if (temp == 0)
            break;

        sum += temp;
    }

    cout << "Summen er: " << sum << endl;
}

double inputDouble() {
    double val = 0.;
    cout << "Skriv inn et tall: ";
    cin >> val;
    return val;
}

void convertNOKtoEUR() {
    double val = 0;

    while (1) {
        val = inputDouble();

        if (val > 0)
            break;
        else
            cout << "Ugyldig verdi, prøv igjen." << endl;
    }

    cout << std::fixed;
    cout << std::setprecision(2);
    cout << "Beløp: €" << val * 9.75 << endl;
}

void multTable() {
    int m = 0;
    int n = 0;
    cout << "Enter height: ";
    cin >> m;
    cout << "Enter width: ";
    cin >> n;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cout << i*j << "\t";
        }
        cout << endl;
    }
}