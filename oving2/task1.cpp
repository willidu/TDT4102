#include "header.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void inputAndPrintInteger() {
    int result;
    cout << "Skriv inn et tall: ";
    cin >> result;
    cout << "Du skrev: " << result << endl;
}

int inputInteger() {
    int result = 0;
    cout << "Skriv inn et tall: ";
    cin >> result;
    return result;
}

void inputIntegerAndPrintSum() {
    int firstNum = inputInteger();
    int secondNum = inputInteger();
    cout << "Summen av tallene: " << firstNum + secondNum << endl;
}

bool isOdd(int num) {
    return num % 2;
}

void printHumanReadableTime(int seconds) {
    int hours = seconds / 3600;
    int minutes = (seconds % 3600) / 60;
    int seconds_ = seconds - hours * 3600 - minutes * 60;
    cout << hours << " timer, "
         << minutes << " minutter, "
         << seconds_ << " sekunder" << endl;
}
