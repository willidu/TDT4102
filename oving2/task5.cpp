#include <math.h>
#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

vector<int> calculateBalance(int innskudd, int rente, int antallAr) {
    vector<int> saldo (antallAr+1, 0);
    const double vekstfaktor = 1. + static_cast<double>(rente)/100.;
    saldo[0] = innskudd;

    for (int i = 1; i <= antallAr; i++) {
        double temp = static_cast<double>(saldo[i-1]) * pow(vekstfaktor, i);
        saldo[i] = static_cast<int> (temp);
    }

    return saldo;
}

void printBalance(const vector<int> &balanceValues) {
    cout << "År\tSaldo" << endl;
    for (int i = 0; i < balanceValues.size(); i++)
        cout << i << "\t" << balanceValues[i] << endl;
}
