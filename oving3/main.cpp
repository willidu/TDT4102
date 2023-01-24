/*
Task 4e)
bool checkIfDistanceToTargetIsCorrect() {
    double error = targetPractice(0,0,0);
    if(error == 0) 
        return true;
}
The error:
../main.cpp:18:1: error: non-void function does not return a value in all control paths [-Werror,-Wreturn-type]
Meaning that the if statement is not triggered and the non-void functuon returns nothing.
Also, implicit type conversion from double to int/bool.
*/

#include "cannonball.hpp"
#include "utils.hpp"

#include <iostream>
#include <string>
#include <cstdlib>

using std::cout;
using std::endl;

void exampleTask();
void testDeviation(
    double compareOperant, double toOperand,
    double maxError, std::string name);
void testRand();

int main() {
    exampleTask();
    // testRand();
    playTargetPractice();

    return 0;
}

void exampleTask() {
    const double maxErr = 0.01;

    testDeviation(velY(25., 2.5), 0.475, maxErr, "velY(25., 2.5)");
    testDeviation(velY(25., 5.), -24.05, maxErr, "velY(25., 5.)");
    testDeviation(posX(0, 50., 2.5), 125., maxErr, "posX(0, 50., 2.5)");
    testDeviation(posX(0, 50., 5.), 250., maxErr, "posX(0, 50., 5.)");
    testDeviation(posY(0, 25., 2.5), 31.84, maxErr, "posY(0, 25., 2.5)");
    testDeviation(posY(0, 25., 5.), 2.375, maxErr, "posY(0, 25., 5.)");

    auto testVector = getVelVec(degToRad(27.5), 15.64);
    testDeviation(testVector[0], 13.8728, maxErr, "getVelVec(degToRad(27.5), 15.64)[0]");
    testDeviation(testVector[1], 7.22175, maxErr, "getVelVec(degToRad(27.5), 15.64)[1]");

    testDeviation(getDistanceTraveled(testVector[0], testVector[1]), 20.4253, maxErr, "getDistanceTraveled(testVector[0], testVector[1])");
    testDeviation(targetPractice(25., testVector[0], testVector[1]), 4.5747, maxErr, "targetPractice(25., testVector[0], testVector[1])");
}

void testDeviation(
    double compareOperant, double toOperand,
    double maxError, std::string name) 
{
    bool lessThanErr = std::abs(compareOperant - toOperand) <= maxError;
    if ( !lessThanErr ) {
        cout << name << " test failed!"
             << "\n\t"
             << "Expected " << toOperand << ", got " << compareOperant << endl;
    }
}

void testRand() {
    for (int i = 0; i < 10; i++) {
        cout << randomWithLimits(0, 10) << " ";
    }
    cout << endl;
}
