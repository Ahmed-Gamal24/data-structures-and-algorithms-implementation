#pragma once

#include "singly_linked_list.h"


template <typename T>
class clsStack{

    singlyList::clsLinkedList<T> _data;

public:
    clsStack(bool unique);
    clsStack();
    void push(T data);
    T pop();
    T peek();
    bool isEmpty();   
    int size();
    void display();

};


#include "stack_list_based.tpp"