#ifndef _UTILS_H_
#define _UTILS_H_

#include <string>

// Task 1
int incrementByValueNumTimes(int startValue, int increment, int numTimes);
int incrementByValueNumTimesRef(int& startValue, int increment, int numTimes);
void swapNumbers(int& numOne, int& numTwo);

// Task 2
struct Student {
    std::string name;
    std::string studyProgram;
    int age;
};

void printStudent(Student student);
bool isInProgram(Student student, std::string program);

// Task 3
std::string randomizeString(int length, char lowerBound = 'A', char upperBound = 'F');
std::string readInputToString(int length, char lowerBound = 'A', char upperBound = 'F');
int countChar(std::string str, char ch);

#endif