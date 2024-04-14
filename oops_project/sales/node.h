#ifndef node_h
#define node_h

#include <iostream>

template <class T>
class Node {
private:
    T data;
    Node *next;

public:
    Node();
    Node(T data);
    void print();
    void modifyData(T newData);
    void modifyNext(Node *newNext);
    Node& operator=(const Node &other);
    T retrieveData();
    Node *retrieveNext();
};

template <class T>
Node<T>::Node() {
    data = 0;
    next = nullptr;
}

template <class T>
Node<T>::Node(T data) {
    this->data = data;
    next = nullptr;
}

template <class T>
void Node<T>::print() {
    std::cout << "||" << data << "||" << "->";
}

template <class T>
T Node<T>::retrieveData() {
    return data;
}

template <class T>
Node<T> *Node<T>::retrieveNext() {
    return next;
}

template <class T>
void Node<T>::modifyData(T newData) {
    data = newData;
}

template <class T>
void Node<T>::modifyNext(Node<T> *newNext) {
    next = newNext;
}

#endif
