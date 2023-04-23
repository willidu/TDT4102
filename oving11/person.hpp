#pragma once

#include <list>
#include <string>
#include <iostream>
#include <algorithm>

class Person
{
public:
    Person(std::string firstName, std::string lastName)
        : m_FirstName{firstName}, m_LastName{lastName} {};

    std::string getFirstName() const { return m_FirstName; }
    std::string getLastName() const { return m_LastName; }

    friend std::ostream& operator<< (std::ostream& os, const Person& p);
    bool operator< (const Person& other) const;

private:
    std::string m_FirstName;
    std::string m_LastName;
};

void insertOrdered(std::list<Person>& l, const Person& p);
