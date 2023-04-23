#include "person.hpp"

std::ostream& operator<< (std::ostream& os, const Person& p)
{
    os << p.getFirstName() << " " << p.getLastName();
    return os;
}

bool Person::operator< (const Person& other) const
{
    return std::min(this->getFirstName(), other.getFirstName()) == this->getFirstName();;
}

void insertOrdered(std::list<Person>& l, const Person& p)
{
    l.sort();

    for (std::list<Person>::iterator it = l.begin(); it != l.end(); it++)
        if (p < *it)
        {
            l.insert(it, p);
            return;
        }
}
