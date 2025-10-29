#pragma once

#include"stack_list_based.h"

template <typename T>
clsStack<T>::clsStack(bool unique){
    _data = new singlyList::clsLinkedList<T>(unique);
}

template <typename T>
clsStack<T>::clsStack(){
    _data = new singlyList::clsLinkedList<T>;
}

template <typename T>
void clsStack<T>::push(T data){
    _data.insertFirst(data);
}

template <typename T>
T clsStack<T>::pop(){
    T headData = _data.getHeadData();
    _data.deleteHead();
    return headData;
}

template <typename T>
T clsStack<T>::peek(){
    return _data.getHeadData();
}

template <typename T>
bool clsStack<T>::isEmpty(){
    return _data.isEmpty();
}

template <typename T>
int clsStack<T>::size(){
    return _data.getLength();
}

template <typename T>
void clsStack<T>::display(){
    _data.display("newLine per item");
}

