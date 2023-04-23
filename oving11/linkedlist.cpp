#include "linkedlist.hpp"

#include <iostream>

using Node = LinkedList::Node;

// Task 3
std::ostream& operator<< (std::ostream& os, const Node& node)
{
    os << node.getValue();
    return os;
}

Node* LinkedList::LinkedList::insert (Node* pos, const std::string& value)
{
    if (!pos)
    {
        std::cout << "Cannot set head to nullptr." << std::endl;
        exit(1);
    } 
    else if (pos == head.get())
    {
        head = std::make_unique<Node>(value, std::move(head), nullptr);
        pos->prev = head.get();
    }
    else
    {
        pos->prev->next = std::make_unique<Node>(value, std::move(pos->prev->next), pos->prev);
    }
    return pos->prev->next.get();
}

Node* LinkedList::LinkedList::remove (Node* pos)
{
    if (!pos)
    {
        pos->prev->next = std::make_unique<Node>(pos->next->getValue(), std::move(pos->next->next), pos->prev);
    }
    return pos->prev->next.get();
}

Node* LinkedList::LinkedList::find(const std::string& value)
{
    Node* node_ptr = this->begin();

    while (node_ptr != nullptr)
    {
        if (node_ptr->getValue() == value)
            return node_ptr;
        else
            node_ptr = node_ptr->getNext();
    }

    return this->begin();
}

void LinkedList::LinkedList::remove(const std::string& value)
{
    Node* node_ptr = this->find(value);

    if (node_ptr != this->begin())
        this->remove(node_ptr);
}

std::ostream& operator<<(std::ostream& os, const LinkedList::LinkedList& list)
{
    Node* current = list.begin();

    while (current->getNext())
        os << current->getValue() << " ";

    return os;
}

