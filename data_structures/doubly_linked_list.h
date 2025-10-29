#pragma once

#include<iostream>

namespace doublyList{

    template <typename T>
    class clsNode {
    private:
        T _data;
        clsNode<T>* _next;
        clsNode<T>* _back;

    public:
        clsNode(T data);
        clsNode(T data, clsNode<T>* next, clsNode<T>* back);  
        T data();
        clsNode<T>* next();
        clsNode<T>* back();
        void setData(T data);
        void setNext(clsNode<T>* next);
        void setBack(clsNode<T>* back);
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
        clsNode<T>* _head;
        clsNode<T>* _tail;
        int _length;

    public:
        clsLinkedList();
        clsLinkedList(const clsLinkedList<T>& l);
        int length();
        bool isEmpty();
        void insertLast(T data);
        clsNode<T>* find(T data);	
        void insertAfter(T data, T newData);
        void deleteNode(T data);
        void insertBefor(T data, T newData);
        void display();
    };



}//end of namespace doublyList

#include"doubly_linked_list.tpp"