#include "animal.hpp"

std::string Animal::toString() const{
    return "Animal: " + name + " " + std::to_string(age);
}

std::string Cat::toString() const{
    return "Cat: " + name + " " + std::to_string(age);
}

std::string Dog::toString() const{
    return "Dog: " + name + " " + std::to_string(age);
}
