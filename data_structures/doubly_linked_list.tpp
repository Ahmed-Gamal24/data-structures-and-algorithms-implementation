#pragma once

#include<iostream>

#include"doubly_linked_list.h"

namespace doublyList{

    //==============clsNode class Implementation============    
    template <typename T>
    clsNode<T>::clsNode(T data) {
        _data = data;
        _next = nullptr;
        _back = nullptr;
    }

    template <typename T>
    clsNode<T>::clsNode(T data, clsNode<T>* next, clsNode<T>* back) {
        _data = data;
        _next = next;
        _back = back;
    }

    //setters and getters 
    template <typename T>
    T clsNode<T>::data() { return _data; }

    template <typename T>
    clsNode<T>* clsNode<T>::next() { return _next; }

    template <typename T>
    clsNode<T>* clsNode<T>::back() { return _back; }

    template <typename T>
    void clsNode<T>::setData(T data) { _data = data; }

    template <typename T>
    void clsNode<T>::setNext(clsNode<T>* next) { _next = next; }

    template <typename T>
    void clsNode<T>::setBack(clsNode<T>* back) { _back = back; }

        

    //==============clsIterator class Implementation============    

    template <typename T>
    clsIterator<T>::clsIterator(clsNode<T>* current) {
        _current = current;
    }

    template <typename T>
    T clsIterator<T>::data() {
        return _current->data();
    }

    template <typename T>
    clsNode<T>* clsIterator<T>::current() {
        return _current;
    }

    template <typename T>
    void clsIterator<T>::moveNext() {
        _current = _current->next();
    }



    //==============clsLinkedList class Implementation============     
    template <typename T>
    clsLinkedList<T>::clsLinkedList() {
        _head = nullptr;
        _tail = nullptr;
        _length = 0;
    }

    template <typename T>
    clsLinkedList<T>::clsLinkedList(const clsLinkedList<T>& l) {
        this->_head = nullptr;
        this->_tail = nullptr;
        this->_length = 0;
        
        clsIterator<T> it(l._head);
        for (it.current(); it.current() != nullptr; it.moveNext()) {
            this->insertLast(it.current()->data());
        }
    }

    template <typename T>
    int clsLinkedList<T>::length() {
        return _length;
    }

    template <typename T>
    bool clsLinkedList<T>::isEmpty() {
        return _head == nullptr;
    }

    template <typename T>
    void clsLinkedList<T>::insertLast(T data) {
        clsNode<T>* newNode = new clsNode<T>(data);
        if (_head == nullptr) {
            _head = newNode;
            _tail = newNode;
            _length++;
            return;
        }
        
        _tail->setNext(newNode);
        newNode->setBack(_tail);
        _tail = newNode;
        
        _length++;
    }

    template <typename T>
    clsNode<T>* clsLinkedList<T>::find(T data) {
        clsIterator<T> it(_head);
        while (it.current() != nullptr) {
            if (it.data() == data) { return it.current(); }
            it.moveNext();
        }
        return nullptr;
    }

    template <typename T>
    void clsLinkedList<T>::insertAfter(T data, T newData) {
        if (isEmpty()) { return; }
        
        //create new node for the newData
        clsNode<T>* newNode = new clsNode<T>(newData);
        //search for the node of data
        clsNode<T>* node = find(data);
        
        if (node == nullptr) { return;}//the node of(data) does not exist
        
        
        newNode->setNext(node->next());
        newNode->setBack(node);
        node->setNext(newNode);
        
        
        if (node == _tail) {
            _tail = newNode;
        }
        else {
            newNode->next()->setBack(newNode);
        }
        
        _length++;
    }

    template <typename T>
    void clsLinkedList<T>::deleteNode(T data) {
        clsNode<T>* node = find(data);
        if (node == nullptr) {
            return;
        }
        
        else if ((node == _head) && (node == _tail)) {
            _head = nullptr;
            _tail = nullptr;
        }
        
        else if (node == _head) {
            _head = _head->next();
            _head->setBack(nullptr);
            node->setNext(nullptr);
        }
        
        else if (node == _tail) {
            _tail = _tail->back();
            _tail->setNext(nullptr);
            node->setBack(nullptr);
        }
        
        else {
            node->back()->setNext(node->next());
            node->next()->setBack(node->back());
        }
        
        delete node;
        _length--;
    }

    template <typename T>
    void clsLinkedList<T>::insertBefor(T data, T newData) {
        clsNode<T>* newNode = new clsNode<T>(newData);
        clsNode<T>* node = find(data);
        
        if (node == nullptr) {
            return;
        }
        
        else if (node == _head) {
            _head = newNode;
            newNode->setNext(node);
            node->setBack(newNode);
        }
        
        else {
            node->back()->setNext(newNode);
            newNode->setBack(node->back());
            node->setBack(newNode);
            newNode->setNext(node);
        }
        
        _length++;
    }

    template <typename T>
    void clsLinkedList<T>::display() {
        clsIterator<T> it(_head);
        for (it.current(); it.current() != nullptr; it.moveNext()) {
            if (it.current()->next() != nullptr) {
                std::cout << it.data() << " -> ";
            }
            else {
                std::cout << it.data();
            }
        }
        std::cout << std::endl;
    }

}


