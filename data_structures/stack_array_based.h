#pragma once

#include <optional>

template <typename T>
class clsStack{

    T* _arr;
    int _topIndex;
    int _size;
    int _length;//num of ocupied cells
    bool _unique;

    bool isFull();
    void resize();
public:
    clsStack(bool unique);
    clsStack();
    bool isExist(T data);
    void push(T data);
    std::optional<T> pop();
    std::optional<T> peek();
    bool isEmpty();   
    int size();
    void display();

};

#include "stack_array_based.tpp"