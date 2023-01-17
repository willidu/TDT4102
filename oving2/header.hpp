#ifndef _HEADER_
#define _HEADER_

#include <vector>

// Task 1
void inputAndPrintInteger();
int inputInteger();
void inputIntegerAndPrintSum();
bool isOdd(int num);
void printHumanReadableTime(int seconds);

// Task 2
void sumGivenIntegers(int numInt);
void sumIntegersInput();
double inputDouble();
void convertNOKtoEUR();
void multTable();

// Task 3
double discriminant(double a, double b, double c);
void printRealRoots(double a, double b, double c);
void solveQuadraticEquation();

// Task 4
void pythagoras();

// Task 5
std::vector<int> calculateBalance(int innskudd, int rente, int antallAr);
void printBalance(const std::vector<int> &balanceValues);

#endif