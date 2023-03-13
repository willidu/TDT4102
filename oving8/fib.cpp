#include "fib.hpp"

#include <iostream>

// Task 1
void fillFibNums(int* result, int length)
{
    result[0] = 0;
    result[1] = 1;
    
    for (int i = 2; i < length; i++)
    {
        result[i] = result[i-1] + result[i-2];
    }
}

void printArray(int* arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        std::cout << arr[i] << '\t';
    }

    std::cout << std::endl;
}

void createFib()
{
    int len {0};
    std::cout << "Input how many Fibonacci numbers you want: ";
    std::cin >> len;

    int* arr = new int[len];

    fillFibNums(arr, len);
    printArray(arr, len);

    delete[] arr;
    arr = nullptr;
}

