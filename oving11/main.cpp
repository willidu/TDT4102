#include "test.hpp"

#include <iostream>

int main()
{
    int key {0};
    std::cout << "1: Task 1 - Iterators with vector" << std::endl;
    std::cout << "2: Task 1 - Iterators with set" << std::endl;
    std::cout << "3: Task 2 - Ordered list with people" << std::endl;
    std::cout << "4: Task 3 - Linked list" << std::endl;
    std::cout << "Enter value: ";

    std::cin >> key;
    std::cout << std::endl;

    switch (key)
    {
    case 1:
        testVectorIterator();
        break;

    case 2:
        testSetIterator();
        break;

    case 3:
        testOrderedList();
        break;

    case 4:
        testLinkedList();
        break;
    
    default:
        break;
    }

    return 0;
}
