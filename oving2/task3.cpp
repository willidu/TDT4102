#include "header.hpp"
#include <math.h>
#include <iostream>

using std::cout;
using std::endl;

double discriminant(double a, double b, double c) {
    return b * b - 4. * a * c;
}

void printRealRoots(double a, double b, double c) {
    double disc = discriminant(a, b, c);

    if (disc < 0) {
        cout << "No real roots." << endl;
    } else if (abs(disc) < 1e-5) {
        cout << "One real root: " << -1. * b / (2. * a) << endl;
    } else {
        double r1 = (-1. * b + pow(disc, 0.5)) / (2. * a);
        double r2 = (-1. * b - pow(disc, 0.5)) / (2. * a);

        cout << "Two real roots: " << r1 << ", " << r2 << endl;
    }
}

void solveQuadraticEquation() {
    double a = inputDouble();
    double b = inputDouble();
    double c = inputDouble();
    printRealRoots(a, b, c);
}