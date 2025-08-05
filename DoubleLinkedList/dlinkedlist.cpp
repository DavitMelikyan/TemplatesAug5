#include "dlinkedlist.hpp"

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node* tmp = head;
    while (tmp) {
        Node* tmpnext = tmp->next;
        delete tmp;
        tmp = tmpnext;
    }
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& other) : head(nullptr), tail(nullptr) {
    Node* tmp = other.head;
    while (tmp) {
        push_back(tmp->data);
        tmp = tmp->next;
    }
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(DoublyLinkedList&& other) noexcept : head(other.head), tail(other.tail) {
    other.head = nullptr;
    other.tail = nullptr;
}


template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList& other) {
    if (this == &other) {
        return *this;
    }
    clear();
    head = nullptr;
    tail = nullptr;
    Node* tmp = other.head;
    while (tmp) {
        push_back(tmp->data);
        tmp = tmp->next;
    }
    return *this;
}

template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(DoublyLinkedList&& other) noexcept {
    if (this == &other) {
        return *this;
    }
    clear();
    head = other.head;
    tail = other.tail;
    other.head = nullptr;
    other.tail = nullptr;
    return *this;
}


template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(std::initializer_list<T> lst) : head(nullptr), tail(nullptr) {
    for (const T& item : lst) {
        push_back(item);
    }
}

template <typename T>
void DoublyLinkedList<T>::push_front(const T& value) {
    Node* nd = new Node(value);
    if (head == nullptr) {
        head = nd;
        tail = nd;
        return;
    }
    nd->next = head;
    head->prev = nd;
    head = nd;
}

template <typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
    Node* nd = new Node(value);
    if (tail == nullptr) {
        head = tail = nd;
    } else {
        tail->next = nd;
        nd->prev = tail;
        tail = nd;
    }
}


template <typename T>
void DoublyLinkedList<T>::pop_front() {
    if (head == nullptr) {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    Node* tmp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    } else {
    tail = nullptr;
    }   
    delete tmp;
}

template <typename T>
void DoublyLinkedList<T>::pop_back() {
    if (head == nullptr) {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }

    Node* tmp = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete tmp;
}

template <typename T>
void DoublyLinkedList<T>::erase(Node* node) {
    if (!node) return;

    if (node == head) {
        pop_front();
        return;
    }
    if (node == tail) {
        pop_back();
        return;
    }

    if (node->prev) node->prev->next = node->next;
    if (node->next) node->next->prev = node->prev;

    delete node;
}

template <typename T>
void DoublyLinkedList<T>::clear() {
    Node* tmp = head;
    while (tmp) {
        Node* nxt = tmp->next;
        delete tmp;
        tmp = nxt;
    }
    head = nullptr;
    tail = nullptr;
}

template <typename T>
T& DoublyLinkedList<T>::front() const {
    return head->data;
}

template <typename T>
T& DoublyLinkedList<T>::back() const {
    return tail->data;
}

template <typename T>
typename DoublyLinkedList<T>::Node* DoublyLinkedList<T>::find(const T& value) const {
    Node* tmp = head;
    while (tmp) {
        if (tmp->data == value) return tmp;
        tmp = tmp->next;
    }
    return nullptr;
}


template <typename T>
void DoublyLinkedList<T>::merge(DoublyLinkedList<T>& other) {
    if (other.head == nullptr) return;

    if (tail) {
        tail->next = other.head;
        other.head->prev = tail;
        tail = other.tail;
    } else {
        head = other.head;
        tail = other.tail;
    }

    other.head = nullptr;
    other.tail = nullptr;
}