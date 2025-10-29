#pragma once

#include"singly_linked_list.h"

template <typename T>
class clsQueue{

    singlyList::clsLinkedList<T>* _list;
    int _size;

public:
    clsQueue();
    clsQueue(bool unique);
    void enqueue(T data);
    T dequeue();
    T peek();
    bool hasData();
    void display();
    int size();//will return the number of nodes

};

#include"queue_list_based.tpp"