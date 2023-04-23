#include "utils.hpp"

#include <algorithm>
#include <iostream>

void replace(std::vector<std::string>& vec, std::string old, std::string replacement)
{
    for (std::vector<std::string>::iterator it = vec.begin(); it != vec.end(); it++)
        if (*it == old)
        {
            vec.erase(it);
            vec.insert(it, replacement);
        }
}

void replace(std::set<std::string>& set, std::string old, std::string replacement)
{
    for (std::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
        if (*it == old)
        {
            set.erase(it);
            set.insert(replacement);
            
            return;
        }
}

void printList(const std::list<Person>& l)
{
    for (const Person& p : l)
        std::cout << p.getFirstName() << " ";
    std::cout << std::endl;
}
