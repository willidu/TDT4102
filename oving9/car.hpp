#pragma once

class Car
{
private:
    unsigned freeSeats;

public:
    Car(unsigned seats);
    bool hasFreeSeats() const;
    void reserveFreeSeat();
};
