#include "test.hpp"
#include "utils.hpp"
#include "linkedlist.hpp"

// Task 1
void testVectorIterator()
{
    std::vector<std::string> vec = {"William", "har", "lyst", "paa", "lunsj"};

    for (std::vector<std::string>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    for (std::vector<std::string>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    replace(vec, "lunsj", "middag");
    for (const auto& val : vec)
        std::cout << val << " ";
    std::cout << std::endl;
}

void testSetIterator()
{
    std::set<std::string> set = {"William", "har", "lyst", "paa", "lunsj"};

    for (std::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    for (std::set<std::string>::reverse_iterator it = set.rbegin(); it != set.rend(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    replace(set, "lunsj", "middag");
    for (const auto& val : set)
        std::cout << val << " ";
    std::cout << std::endl;
}

// Task 2
void testOrderedList()
{
    std::list<Person> l;

    l.emplace_back("Sophia", "Wellman");
    l.emplace_back("William", "Dugan");
    l.emplace_back("Albrekt", "M.");
    Person other {"Aaaa", "Bbbbb"};

    printList(l);
    insertOrdered(l, other);
    printList(l);

    /* 
        Hvis listen er tom: Ingenting blir lagt til. Sammenligner med NULL?
        Tillegg på slutten: Funker ikke.
     */
}

// Task 3
void testLinkedList()
{
    using Node = LinkedList::Node;
    using LinkedList::LinkedList;

    LinkedList l;
    Node* n1 = l.insert(l.end(), "1");
    Node* n2 = l.insert(n1, "2");
    Node* n3 = l.insert(n2, "3");

    Node* found = l.find("1");
    l.remove(found);

    // l.remove("3");
    // std::cout << l << std::endl;
}
