#ifndef DLINKEDLIST_HPP
#define DLINKEDLIST_HPP
#include <iostream>
#include <initializer_list>

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& value, Node* p = nullptr, Node* n = nullptr) : data(value), prev(p), next(n) {}
    };
    Node* head;
    Node* tail;
public:
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList& other);
    DoublyLinkedList(DoublyLinkedList&& other) noexcept;
    DoublyLinkedList& operator=(const DoublyLinkedList& other);
    DoublyLinkedList& operator=(DoublyLinkedList&& other) noexcept;
    DoublyLinkedList(std::initializer_list<T> lst);
    ~DoublyLinkedList();

    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void pop_back();
    void erase(Node* node);
    void clear();

    T& front() const;
    T& back() const;
    Node* find(const T& value) const;
    void merge(DoublyLinkedList<T>& other);

};


#endif