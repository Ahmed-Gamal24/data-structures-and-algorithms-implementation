#pragma once

#include<iostream>
#include"queue_list_based.h"

template <typename T>
clsQueue<T>::clsQueue(){
    _list = new singlyList::clsLinkedList<T>;
}

template <typename T>
clsQueue<T>::clsQueue(bool unique){
    _list = new singlyList::clsLinkedList<T>(unique);
}

template <typename T>
void clsQueue<T>::enqueue(T data){
    _list->insertLast(data);
}

template <typename T>
T clsQueue<T>::dequeue(){
    T headData = _list->getHeadData();
    _list->deleteHead();
    return headData;
}

template <typename T>
T clsQueue<T>::peek(){
    return _list->getHeadData();
}

template <typename T>
bool clsQueue<T>::hasData(){
    return _list->getLength() > 0;
}

template <typename T>
void clsQueue<T>::display(){
    _list->display();
}

template <typename T>
int clsQueue<T>::size(){//will return the number of nodes
    return _list->getLength();
}