#pragma once

#include <iostream>

class Matrix
{
private:
    unsigned nRows {0};
    unsigned nCols {0};
    double** matr;

public:
    Matrix(unsigned M, unsigned N);
    explicit Matrix(unsigned M);
    Matrix(const Matrix& rhs);
    ~Matrix();

    void setElement(unsigned m, unsigned n, double val);
    double getElement(unsigned m, unsigned n) const;
    unsigned getRows() const;
    unsigned getColumns() const;

    double* operator[] (unsigned m) const;
    friend std::ostream& operator<< (std::ostream& os, const Matrix& A);
    // Matrix& operator= (const Matrix& rhs);
    Matrix& operator= (Matrix rhs);
    Matrix& operator+= (Matrix rhs);
};

Matrix& operator+ (Matrix lhs, Matrix rhs);
