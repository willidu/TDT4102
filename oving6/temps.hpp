#ifndef _TEMPS_H_
#define _TEMPS_H_

#include <iostream>
#include <vector>
#include <string>

struct Temps
{
    double max;
    double min;
    
    friend std::istream& operator>> (std::istream& is, Temps& t);
    friend std::ostream& operator<< (std::ostream& os, Temps& t);
};

std::vector<Temps> readTemps(std::string path);
std::ostream& operator<< (std::ostream& os, std::vector<Temps> temps);
void tempStats(const std::vector<Temps>& temps);

#endif
