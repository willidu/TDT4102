#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include <string>

class Animal
{
protected:
    std::string name;
    int age;

public:
    Animal(std::string name, int age) : name{name}, age{age} {}
    virtual ~Animal() {}
    virtual std::string toString() const = 0;
};

class Cat : public Animal
{
using Animal::Animal;
public:
    std::string toString() const;
};

class Dog : public Animal
{
using Animal::Animal;
public:
    std::string toString() const;
};

#endif
