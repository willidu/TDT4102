#include "std_lib_facilities.h"

int maxOfTwo(int a, int b)
{
    if (a > b)
    {
        cout << "A is greater than B" << endl;
        return a;
    }
    else
    {
        cout << "B is greater than A" << endl;
        return b;
    }
}

int fibonacci(int n)
{
    int a = 0;
    int b = 1;
    int temp;

    cout << "Fibonacci numbers:" << endl;

    for (int x = 1; x < n + 1; x++)
    {
        cout << x << ' ' << b << endl;

        temp = b;
        b += a;
        a = temp;
    }

    cout << "-----" << endl;
    return b;
}

int squareNumberSum(int n)
{
    int totalSum = 0;
    for (int i = 1; i < n + 1; i++)
    {
        totalSum += i * i;
        cout << i * i << endl;
    }
    cout << totalSum << endl;
    return totalSum;
}

void triangleNumbersBelow(int n)
{
    int acc = 1;
    int num = 2;
    cout << "Triangle numbers below " << n << ':';

    while (acc < n)
    {
        cout << ' ' << acc;
        acc += num;
        num += 1;
    }

    cout << '\n';
}

bool isPrime(int n)
{
    for (int j = 2; j < n; j++)
        if (n % j == 0)
            return false;
    return true;
}

void nativePrimeNumberSearch(int n)
{
    for (int number = 2; number < n; number++)
        if (isPrime(number) == 1)
            cout << number << " is a prime" << endl;
}

int findGreatestDivisor(int n)
{
    for (int divisor = n - 1; n > 0; divisor--)
        if (n % divisor == 0)
            return divisor;
}

int main()
{
    cout << "Oppgave a)" << endl;
    cout << maxOfTwo(5, 3) << endl;
    
    cout << "\nOppgave c)" << endl;
    cout << fibonacci(5) << endl;

    cout << "\nOppgave d)" << endl;
    squareNumberSum(5);

    cout << "\nOppgave e)" << endl;
    triangleNumbersBelow(10);

    cout << "\nOppgave f)" << endl;
    cout << "4 is a prime number: " << isPrime(4) << endl;
    cout << "7 is a prime number: " << isPrime(7) << endl;

    cout << "\nOppgave g)" << endl;
    nativePrimeNumberSearch(10);

    cout << "\nOppgave h)" << endl;
    cout << findGreatestDivisor(14) << endl;
    cout << findGreatestDivisor(13) << endl;

    return 0;
}
