#include "utils.hpp"

#include <iostream>
#include <random>

using std::cout;
using std::endl;
using std::cin;

// Task 1
int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
    return startValue;
}

int incrementByValueNumTimesRef(int& startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
    return startValue;
}
void swapNumbers(int& numOne, int& numTwo) {
    int temp { numOne };
    numOne = numTwo;
    numTwo = temp;
}

// Task 2
void printStudent(Student student) {
    cout << "Name: " << student.name << endl;
    cout << "Study program: " << student.studyProgram << endl;
    cout << "Age: " << student.age << endl;
}

bool isInProgram(Student student, std::string program) {
    return student.studyProgram == program;
}

// Task 3
std::string randomizeString(int length, char lowerBound, char upperBound) {
    std::random_device rd;
    std::default_random_engine generator (rd());
    std::uniform_int_distribution distribution (lowerBound, upperBound);

    std::string res;
    for (unsigned i = 0; i < length; i++) {
        res += static_cast<char>(distribution(generator));
    }

    return res;
}

std::string readInputToString(int length, char lowerBound, char upperBound) {
    std::string res;
    int i {0};

    while (i < length) {
        char in;
        cout << "Input character (" << i+1 << "/" << length << ")\n";
        cin >> in;
        in = std::toupper(in);
        if (lowerBound < in < upperBound) {
            res += in;
            i++;
        } else {
            cout << "Invalid input." << endl;
        }
    }

    return res;
}

int countChar(std::string str, char ch) {
    int count {0};

    for (unsigned i = 0; i < str.size(); i++) {
        if (str[i] == ch) {
            count += 1;
        }
    }

    return count;
}