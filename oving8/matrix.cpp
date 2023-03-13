#include "matrix.hpp"

#include <cassert>
#include <iostream>
#include <utility>

// Task 2
Matrix::Matrix(unsigned M, unsigned N)
    : nRows{M}, nCols{N}
{
    assert(M > 0);
    assert(N > 0);

    matr = new double* [nRows];

    for (unsigned m {0}; m < nRows; m++)
    {
        matr[m] = new double[nCols];

        for (unsigned n {0}; n < nCols; n++)
        {
            matr[m][n] = 0.;
        }
    }
}

Matrix::Matrix(unsigned M) : Matrix{M, M}
{
    for (unsigned m {0}; m < M; m++)
    {
        matr[m][m] = 1.;
    }
}

Matrix::~Matrix()
{
    delete[] matr;
}

double Matrix::getElement(unsigned m, unsigned n) const
{
    return matr[m][n];
}

unsigned Matrix::getRows() const
{
    return nRows;
}

unsigned Matrix::getColumns() const
{
    return nCols;
}

void Matrix::setElement(unsigned m, unsigned n, double val)
{
    matr[m][n] = val;
}

double* Matrix::operator[] (unsigned m) const
{
    return matr[m];
}

std::ostream& operator<< (std::ostream& os, const Matrix& A)
{
    for (unsigned m {0}; m < A.getRows(); m++)
    {
        for (unsigned n {0}; n < A.getColumns(); n++)
        {
            os << A.getElement(m, n) << '\t';
        }
        os << '\n';
    }

    return os;
}

// Task 4
Matrix::Matrix(const Matrix& rhs) : matr{ nullptr }
{
    // Allocation
    this->matr = new double* [rhs.getRows()];
    
    // Copying values
    this->nRows = rhs.getRows();
    this->nCols = rhs.getColumns();

    for (unsigned m {0}; m < rhs.getRows(); m++)
    {
        // Allocation
        this->matr[m] = new double[rhs.getColumns()];

        // Copying matrix entries
        for (unsigned n {0}; n < rhs.getColumns(); n++)
        {
            this->matr[m][n] = rhs.getElement(m, n);
        }
    }
}

Matrix& Matrix::operator= (Matrix rhs)
{
    std::swap(matr, rhs.matr);
    return *this;
}

// Task 5
Matrix& Matrix::operator+= (Matrix rhs)
{
    assert(this->getRows() == rhs.getRows());
    assert(this->getColumns() == rhs.getColumns());

    for (unsigned m {0}; m < this->nRows; m++)
    {
        for (unsigned n {0}; n < this->nCols; n++)
        {
            this->matr[m][n] += rhs.getElement(m, n);
        }
    }

    return *this;
}

Matrix& operator+ (Matrix lhs, Matrix rhs)
{
    Matrix* newMatrix = new Matrix{lhs};
    (*newMatrix) += rhs;
    return *newMatrix;
}
