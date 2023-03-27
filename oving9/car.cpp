#include "car.hpp"

Car::Car(unsigned seats) : freeSeats{seats} {}

bool Car::hasFreeSeats() const
{
    return freeSeats > 0;
}

void Car::reserveFreeSeat()
{
    freeSeats--;
}
