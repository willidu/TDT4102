#include "fib.hpp"
#include "matrix.hpp"

#include <iostream>

void testMatrix();
void testMatrixOperators();

int main()
{
    int key {0};
    std::cout << "1: Fibonacci" << std::endl;
    std::cout << "2: Test Matrix class" << std::endl;
    std::cout << "3: Test Matrix operators" << std::endl;
    std::cin >> key;

    switch (key)
    {
    case 1:
        createFib();
        break;

    case 2:
        testMatrix();
        break;

    case 3:
        testMatrixOperators();
        break;
    
    default:
        break;
    }
}

void testMatrix()
{
    std::cout << "--------------------------------" << std::endl;
    Matrix A {3, 4};
    A.setElement(2, 3, 3.14);
    std::cout << A << std::endl;
    std::cout << A[2][3] << std::endl;
    // A.~Matrix();  // Funker ikke

    std::cout << "--------------------------------" << std::endl;
    Matrix B {2};
    std::cout << B.getRows() << " x " << B.getColumns() << std::endl;
    std::cout << B << std::endl;
    // B.~Matrix();  // Funker ikke

    // Copy constructor
    std::cout << "--------------------------------" << std::endl;
    Matrix C{A};
    A.setElement(0, 0, 1.);
    std::cout << C << std::endl;
    // Observing that C remains unchanged.

    // Operator=
    std::cout << "--------------------------------" << std::endl;
    Matrix D = B;
    std::cout << D << std::endl;
}

void testMatrixOperators()
{
    Matrix A {2, 2};
    A.setElement(0, 0, 1.);
    A.setElement(0, 1, 2.);
    A.setElement(1, 0, 3.);
    A.setElement(1, 1, 4.);

    Matrix B {2, 2};
    B.setElement(0, 0, 4.);
    B.setElement(0, 1, 3.);
    B.setElement(1, 0, 2.);
    B.setElement(1, 1, 1.);

    Matrix C {2, 2};
    C.setElement(0, 0, 1.);
    C.setElement(0, 1, 3.);
    C.setElement(1, 0, 1.5);
    C.setElement(1, 1, 2.);

    // A += B;
    // This works

    A += B + C;
    std::cout << A << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << B << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << C << std::endl;
    // Looks correct.
}
