/*
Task 1e)
I chose to use inputInteger() in the function inputIntegersAndPrintSum()
since the numbers should not be printed to the terminal.

Task 2c)
In 2a we use a for loop since we know the number of iterations beforehand.
In 2b we use a while loop until the contition is no longer met (input == 0).

Task 2f)
Here we use a double as the currency conversion factor is not an integer.
Ie. we need decimal places as well.

Task 5c)
The error means that the C++ compiler does not know how to cout/print a whole vector.
It needs to be done element-wise.

Task 5d)
The error:
libc++abi: terminating with uncaught exception of type std::out_of_range: vector
The range is 1 too long. It is currently checking <= instead of <.
*/

#include "std_lib_facilities.h"
#include "AnimationWindow.h"

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
vector<int> calculateBalance(int innskudd, int rente, int antallAr);
void printBalance(const vector<int> &balanceValues);

int main()
{
    cout << "Velg funksjon:" << endl;
    cout << "0) Avslutt" << endl;
    cout << "1) Print et heltalltall" << endl;
    cout << "2) Skriv inn et heltall" << endl;
    cout << "3) Summer to heltall" << endl;
    cout << "4) Sjekk om heltallene 0 til 15 er odde" << endl;
    cout << "5) Regn tid fra sekunder" << endl;
    cout << "6) Summer gitt antall heltall" << endl;
    cout << "7) Summer uendelig antall heltall" << endl;
    cout << "8) Skriv inn et flyttall" << endl;
    cout << "9) Konverter NOK til EUR" << endl;
    cout << "10) Skriv ut gangetabellen" << endl;
    cout << "11) Løs andregradsligning" << endl;
    cout << "12) Pythagoras" << endl;
    cout << "13) Renters renter" << endl;
    cout << "Angi valg (0-13): ";

    int input = 0;
    cin >> input;

    switch(input)
    {
        case 0:
            break;

        case 1:
        {
            inputAndPrintInteger();
            break;
        }

        case 2:
        {
            int result = inputInteger();
            cout << "Du skrev: " << result << endl;
            break;
        }

        case 3:
        {
            inputIntegerAndPrintSum();
            break;
        }

        case 4:
        {
            cout << "------" << endl;
            for (int i = 0; i <= 15; i++)
            {
                cout << i << " er " << (isOdd(i) ? "odde" : "like") << endl;
            }
            cout << "------" << endl;
            break;
        }

        case 5:
        {
            int time = 0;
            cout << "Skriv inn en tid i sekunder: "; 
            cin >> time;
            printHumanReadableTime(time);
            break;
        }

        case 6:
        {
            int n = 0;
            cout << "Angi hvor mange tall som skal summeres: ";
            cin >> n;
            sumGivenIntegers(n);
        }

        case 7:
        {
            sumIntegersInput();
            break;
        }

        case 8:
        {
            double val = inputDouble();
            cout << "Du skrev: " << val << endl;
            break;
        }

        case 9:
        {
            convertNOKtoEUR();
            break;
        }

        case 10:
        {
            multTable();
            break;
        }
        
        case 11:
        {
            solveQuadraticEquation();
            break;
        }
        
        case 12:
        {
            pythagoras();
            break;
        }

        case 13:
        {
            cout << "Innskudd: ";
            int innskudd = inputInteger();
            cout << "Rente: ";
            int rente = inputInteger();
            cout << "Antall år: ";
            int antall = inputInteger();
            vector<int> saldo = calculateBalance(innskudd, rente, antall);
            printBalance(saldo);
            break;
        }

        default:
            break;
    }
}

// Task 1
void inputAndPrintInteger() 
{
    int result;
    cout << "Skriv inn et tall: ";
    cin >> result;
    cout << "Du skrev: " << result << endl;
}

int inputInteger()
{
    int result = 0;
    cout << "Skriv inn et tall: ";
    cin >> result;
    return result;
}

void inputIntegerAndPrintSum()
{
    int firstNum = inputInteger();
    int secondNum = inputInteger();
    cout << "Summen av tallene: " << firstNum + secondNum << endl;
}

bool isOdd(int num)
{
    return num % 2;
}

void printHumanReadableTime(int seconds)
{
    int hours = seconds / 3600;
    int minutes = (seconds % 3600) / 60;
    int seconds_ = seconds - hours * 3600 - minutes * 60;
    cout << hours << " timer, "
         << minutes << " minutter, "
         << seconds_ << " sekunder" << endl;
}

// Task 2
void sumGivenIntegers(int numInt)
{
    int sum = 0;
    for (int i = 0; i < numInt; i++)
    {
        int temp = 0;
        cout << "Input number (" << i+1 << "/" << numInt << "): ";
        cin >> temp;
        sum += temp;
    }
    cout << "Summen er " << sum << endl;
}
void sumIntegersInput()
{
    int sum = 0;
    cout << "Skriv '0' for å avslutte." << endl;

    while(1)
    {
        int temp = 0;
        cout << "Input number: ";
        cin >> temp;
        
        if (temp == 0)
            break;

        sum += temp;
    }

    cout << "Summen er: " << sum << endl;
}

double inputDouble()
{
    double val = 0.;
    cout << "Skriv inn et tall: ";
    cin >> val;
    return val;
}

void convertNOKtoEUR()
{
    double val = 0;

    while (1)
    {
        val = inputDouble();

        if (val > 0)
            break;
        else
            cout << "Ugyldig verdi, prøv igjen." << endl;
    }

    cout << fixed;
    cout << setprecision(2);
    cout << "Beløp: €" << val * 9.75 << endl;
}

void multTable()
{
    int m = 0;
    int n = 0;
    cout << "Enter height: ";
    cin >> m;
    cout << "Enter width: ";
    cin >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << i*j << "\t";
        }
        cout << endl;
    }
}

// Task 3
double discriminant(double a, double b, double c)
{
    return b * b - 4. * a * c;
}

void printRealRoots(double a, double b, double c)
{
    double disc = discriminant(a, b, c);

    if (disc < 0)
    {
        cout << "No real roots." << endl;
    } else if (abs(disc) < 1e-5) 
    {
        cout << "One real root: " << -1. * b / (2. * a) << endl;
    } else
    {
        double r1 = (-1. * b + pow(disc, 0.5)) / (2. * a);
        double r2 = (-1. * b - pow(disc, 0.5)) / (2. * a);

        cout << "Two real roots: " << r1 << ", " << r2 << endl;
    }
}

void solveQuadraticEquation()
{
    double a = inputDouble();
    double b = inputDouble();
    double c = inputDouble();
    printRealRoots(a, b, c);
}

void pythagoras()
{
    AnimationWindow win{100, 100, 1024, 1024, "Pythagoras"};

    // Trekant med punkt 1 nede venstre hjørne, tegnet med klokka
    Point point1{400, 400};
    Point point2{400, 200};
    Point point3{600, 400};

    win.draw_triangle(point1, point2, point3, Color::grey);

    // Firkant venstre katet (mot klokka)
    win.draw_quad(
        point1, point2, Point{200, 200}, Point{200, 400},
        Color::green_yellow
    );

    // Firkant nedre katet (med klokka)
    win.draw_quad(
        point1, point3, Point{600, 600}, Point{400, 600},
        Color::blue_violet
    );

    
    // Firkant hypotenus (mot klokka)
    win.draw_quad(
        point2, point3, Point{800, 200}, Point{600, 0},
        Color::orange_red
    );

    win.wait_for_close();
}

// Task 5
vector<int> calculateBalance(int innskudd, int rente, int antallAr)
{
    vector<int> saldo (antallAr+1, 0);
    const double vekstfaktor = 1. + static_cast<double>(rente)/100.;
    saldo[0] = innskudd;

    for (int i = 1; i <= antallAr; i++)
    {
        double temp = static_cast<double>(saldo[i-1]) * pow(vekstfaktor, i);
        saldo[i] = static_cast<int> (temp);
    }

    return saldo;
}

void printBalance(const vector<int> &balanceValues) 
{
    cout << "År\t\tSaldo" << endl;
    for (int i = 0; i < balanceValues.size(); i++)
        cout << i << "\t\t" << balanceValues[i] << endl;
}
