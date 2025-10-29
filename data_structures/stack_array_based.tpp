#include <iostream>
#include <optional>
#include "stack_array_based.h"

template <typename T>
clsStack<T>::clsStack(bool unique){
    _size = 10;
    _topIndex = -1;
    _arr = new T[_size];
    _unique = unique;
    _length = 0;
}

template <typename T>
clsStack<T>::clsStack(){
    _size = 10;
    _topIndex = -1;
    _arr = new T[_size];
    _unique = false;
    _length = 0;
}

template <typename T>
bool clsStack<T>::isExist(T data){
    for(int i = _topIndex; i >= 0; --i){
        if(_arr[i] == data){
            return true;
        }
    }
    return false;
}

template <typename T>
void clsStack<T>::push(T data){
    if(_unique){
        if(isExist(data)){
        return;
    }
    }

    if(isFull()){
        resize();
    }

    _arr[++_topIndex] = data;
    _length++;
}

template <typename T>
std::optional<T> clsStack<T>::pop(){
    if(isEmpty()){
        return{};
    }

    T popedData = _arr[_topIndex];
    _topIndex--;
    _length--;
    return popedData;
}

template <typename T>
std::optional<T> clsStack<T>::peek(){
    if(isEmpty()){
        return{};
    }

    return _arr[_topIndex];
}

template <typename T>
bool clsStack<T>::isEmpty(){
    return _topIndex == -1;
}

template <typename T>
bool clsStack<T>::isFull(){
    return _length == _size;
}

template <typename T>
void clsStack<T>::resize(){
    _size*=2;
    T* newArr = new T[_size];
    for(int i = 0; i < _length; ++i){
        newArr[i] = _arr[i];
    }
    delete _arr;
    _arr = newArr;
}

template <typename T>
int clsStack<T>::size(){
    return _length;
}

template <typename T>
void clsStack<T>::display(){
    for(int i = _topIndex; i >= 0; --i){
        cout << _arr[i] << endl;
    }
    cout << "----" << endl;
}