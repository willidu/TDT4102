#ifndef _CANNONBALL_H
#define _CANNONBALL_H

#include <vector>

// Task 1
double accY();
double velY(double initVelY, double time);
double posX(double initPos, double initVel, double time);
double posY(double initPos, double initVel, double time);
void printTime(double time);
double flightTime(double initVelY);

// Task 4
double getUserInputTheta();
double getUserInputAbsVel();
double degToRad(double deg);
double getVelX(double theta, double absVel);
double getVelY(double theta, double absVel);
std::vector<double> getVelVec(double theta, double absVel);
double getDistanceTraveled(double velX, double velY);
double targetPractice(double distToTarget, double velX, double velY);

// Task 5
void playTargetPractice();

#endif
