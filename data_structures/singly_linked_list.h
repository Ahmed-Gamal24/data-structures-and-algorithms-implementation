#pragma once

#include <iostream>
#include <stdexcept>
using namespace std;

namespace singlyList {

template <typename T>
class clsNode {
private:
    T _data;
    clsNode<T>* _next;

public:
    clsNode(T data);
    clsNode(T data, clsNode<T>* next);

    // getters and setters
    T data();
    clsNode<T>* next();

    void setData(T data);
    void setNext(clsNode<T>* next);
};


template <typename T>
class clsIterator {
private:
    clsNode<T>* _current;

public:
    clsIterator(clsNode<T>* current);

    T data();
    clsNode<T>* current();
    void moveNext();
};


template <typename T>
class clsLinkedList {
private:
    clsNode<T>* head;
    clsNode<T>* tail;
    int length;
    bool unique;

public:
    clsLinkedList();
    clsLinkedList(bool unique);

    T getHeadData();
    int getLength();
    bool isEmpty();
    bool isExist(T data);
    bool canInsert(T data);

    void insertFirst(T data);
    void deleteHead();
    void insertLast(T data);
    clsNode<T>* find(T data);
    void insertAfter(T data, T newData);
    clsNode<T>* findParentNode(clsNode<T>* node);
    clsNode<T>* findParentNode(T data);
    void insertBefore(T data, T newData);
    void deleteNode(T data);

    void display();
    void display(string newLine);
};

} // namespace singlyList

#include "singly_linked_list.tpp"
