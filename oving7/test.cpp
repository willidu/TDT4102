#include "test.hpp"

#include <vector>
#include <iostream>

void testAnimal() {
    std::vector<std::unique_ptr<Animal>> ptrVec;
    // Need to remove Animal objects if toString is pure virtual.
    /* 
    ptrVec.emplace_back(new Animal{"Bear", 0});
    ptrVec.emplace_back(new Animal{"Citten", 1});
    ptrVec.emplace_back(new Animal{"Woofer", 7});
     */
    ptrVec.emplace_back(new Cat{"Citten", 2});
    ptrVec.emplace_back(new Dog{"Woofer", 8});

    for (const auto& animal : ptrVec) {
        std::cout << animal->toString() << std::endl;
    }
}