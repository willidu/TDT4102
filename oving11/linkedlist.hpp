#pragma once

#include <memory>
#include <ostream>
#include <string>

namespace LinkedList {

class Node 
{
public:
    Node() : value(), next(nullptr), prev(nullptr) {}
    Node(const std::string& value, std::unique_ptr<Node> next, Node* prev)
        : value(value), next(std::move(next)), prev(prev) {}
    ~Node() = default;

    std::string getValue() const { return value; }
    Node* getNext() const { return next.get(); }
    Node* getPrev() const { return prev; }

    friend std::ostream & operator<<(std::ostream & os, const Node & node);
    friend class LinkedList;

private:
    const std::string value;    // The data held by the LinkedList
    std::unique_ptr<Node> next; // unique_ptr to the next node
    Node* prev;                 // raw (non-owning) ptr to the previous node
};

class LinkedList
{
public:
    LinkedList()
        : head(std::make_unique<Node>()), tail(head.get()) {}
    ~LinkedList() = default;

    bool isEmpty() const { return head->next == nullptr; }

    Node* begin() const { return head.get(); }
    Node* end() const { return tail; }
    Node* insert(Node* pos, const std::string& value);
    Node* find(const std::string& value);
    Node* remove(Node* pos);

    void remove(const std::string& value);

    friend std::ostream& operator<<(std::ostream & os, const LinkedList& list);

private:
    std::unique_ptr<Node> head;
    Node* const tail;
};

}  // namespace LinkedList
