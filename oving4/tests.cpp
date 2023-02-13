#include "tests.hpp"
#include "utils.hpp"

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;

// Task 1
void testCallByValue() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0
         << " increment: " << increment
         << " iterations: " << iterations
         << " result: " << result << endl;
}

void testCallByReference() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimesRef(v0, increment, iterations);
    cout << "v0: " << v0
         << " increment: " << increment
         << " iterations: " << iterations
         << " result: " << result << endl;
}

// Task 2
void testStudentStruct() {
    Student william {"William", "Physics", 20};
    printStudent(william);
    cout << "William studies chemistry: " 
         << (isInProgram(william, "Chemistry") ? "Yes" : "No") << endl;
}

// Task 3
void testString(){
    std::string possibleGrades {"ABCDEF"};
    std::vector<int> gradeWeight {5, 4, 3, 2, 1, 0};
    double avgGrade = 0.;

    std::string grades = randomizeString(8, 'A', 'F');
    cout << "Result: " << grades << endl;

    std::vector<int> gradeCount (possibleGrades.size(), 0);
    for (unsigned i = 0; i < possibleGrades.size(); i++) {
        gradeCount[i] = countChar(grades, possibleGrades[i]);
        avgGrade += gradeCount[i] * gradeWeight[i];
    }

    avgGrade /= grades.size();
    cout << "Average grade: " << avgGrade << endl;
}
