#include "person.hpp"

Person::Person(std::string name, std::string email, std::unique_ptr<Car> carPtr)
    : name{name}, email{email}
{
    std::swap(m_carPtr, carPtr);
}

std::string Person::getName() const
{
    return name;
}

std::string Person::getEmail() const
{
    return email;
}

void Person::setEmail(std::string newEmail)
{
    email = newEmail;
}

bool Person::hasAvailableSeats() const
{
    if (m_carPtr != nullptr)
    {
        return m_carPtr->hasFreeSeats();
    }

    return false;
}

std::ostream& operator<< (std::ostream& os, const Person& p)
{
    os << "Name: " << p.getName() << '\n'
       << "Email: " << p.getEmail();

    return os;
}

