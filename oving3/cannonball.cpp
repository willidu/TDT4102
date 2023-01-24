#include "cannonball.hpp"
#include "utils.hpp"

#include <cmath>
#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;
using std::cin;

// Task 1
double accY() {
    return -9.81;
}

double velY(double initVelY, double time) {
    return initVelY + accY() * time;
}

double posX(double initPos, double initVel, double time) {
    return initPos + initVel * time;
}

double posY(double initPos, double initVel, double time) {
    return initPos + initVel * time + accY() * std::pow(time, 2) / 2.;
}

void printTime(double time) {
    int hours = time / 3600;
    int minutes = (static_cast<int>(time) % 3600) / 60;
    int seconds_ = time - hours * 3600 - minutes * 60;
    cout << hours << " timer, "
         << minutes << " minutter, "
         << seconds_ << " sekunder" << endl;
}

double flightTime(double initVelY) {
    return -2. * initVelY / accY();
}

// Task 4
double getUserInputTheta() {
    double value;
    cout << "Input angle theta [deg]: ";
    cin >> value;
    return value;
}

double getUserInputAbsVel() {
    double value;
    cout << "Input absolute velocity: ";
    cin >> value;
    return value;
}

double degToRad(double deg) {
    // 0.01745329252 approx eq 180 deg / pi.
    return deg * 0.01745329252;
}

double getVelX(double theta, double absVel) {
    return absVel * std::cos(theta);
}

double getVelY(double theta, double absVel) {
    return absVel * std::sin(theta);
}

std::vector<double> getVelVec(double theta, double absVel) {
    return std::vector<double> { getVelX(theta, absVel), getVelY(theta, absVel) };
}

double getDistanceTraveled(double velX, double velY) {
    return posX(0., velX, flightTime(velY));
}

double targetPractice(double distToTarget, double velX, double velY) {
    return distToTarget - getDistanceTraveled(velX, velY);
}

// Task 5
void playTargetPractice() {
    const int targetDist = randomWithLimits(100, 1000);
    bool won = false;

    for (unsigned trial = 0; trial < 10; trial++) {
        double theta = getUserInputTheta();
        double absVel = getUserInputAbsVel();

        auto velVec = getVelVec(theta, absVel);
        double velX = velVec[0];
        double velY = velVec[1];

        double time = flightTime(velY);

        auto dist = targetPractice(targetDist, velX, velY);
        bool hit = std::abs(dist) <= 5.;

        if (hit) {
            cout << "Congratulations! You won the game!" << endl;
            won = true;
            break;
        } else {
            cout << "You missed the target by " << dist << " meters. " 
                 << "Flight time: ";
            printTime(flightTime(velY));
        }
    }

    if (!won) {
        cout << "The game is sadly over for now. We all know you did your best!" 
             << " Better luck next time, champ." << endl;
    }

}
