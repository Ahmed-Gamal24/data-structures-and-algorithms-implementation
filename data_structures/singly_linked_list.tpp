#pragma once
#include "singly_linked_list.h"

namespace singlyList {

// ========== clsNode Implementation ==========
template <typename T>
clsNode<T>::clsNode(T data) {
    _data = data;
    _next = nullptr;
}

template <typename T>
clsNode<T>::clsNode(T data, clsNode<T>* next) {
    _data = data;
    _next = next;
}

template <typename T>
T clsNode<T>::data() { return _data; }

template <typename T>
clsNode<T>* clsNode<T>::next() { return _next; }

template <typename T>
void clsNode<T>::setData(T data) { _data = data; }

template <typename T>
void clsNode<T>::setNext(clsNode<T>* next) { _next = next; }


// ========== clsIterator Implementation ==========
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


// ========== clsLinkedList Implementation ==========
template <typename T>
clsLinkedList<T>::clsLinkedList() {
    head = nullptr;
    tail = nullptr;
    this->length = 0;
    this->unique = false;
}

template <typename T>
clsLinkedList<T>::clsLinkedList(bool unique) {
    head = nullptr;
    tail = nullptr;
    this->length = 0;
    this->unique = unique;
}

template <typename T>
T clsLinkedList<T>::getHeadData() {
    if (head == nullptr) {
        throw std::runtime_error("List is empty");
    }
    return head->data();
}

template <typename T>
int clsLinkedList<T>::getLength() {
    return this->length;
}

template <typename T>
bool clsLinkedList<T>::isEmpty() {
    return head == nullptr;
}

template <typename T>
bool clsLinkedList<T>::isExist(T data) {
    return (find(data) != nullptr);
}

template <typename T>
bool clsLinkedList<T>::canInsert(T data) {
    return (!isExist(data));
}

template <typename T>
void clsLinkedList<T>::insertFirst(T data) {
    if (unique && !canInsert(data)) {
        return;
    }

    clsNode<T>* newNode = new clsNode<T>(data);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        this->length++;
        return;
    }

    newNode->setNext(head);
    head = newNode;
    this->length++;
}

template <typename T>
void clsLinkedList<T>::deleteHead() {
    if (isEmpty()) return;

    clsNode<T>* oldHead = head;
    head = head->next();
    if (oldHead->next() == nullptr) {
        tail = nullptr;
    }
    oldHead->setNext(nullptr);
    delete oldHead;
    this->length--;
}

template <typename T>
void clsLinkedList<T>::insertLast(T data) {
    if (unique && !canInsert(data)) {
        return;
    }

    clsNode<T>* newNode = new clsNode<T>(data);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        this->length++;
        return;
    }

    tail->setNext(newNode);
    tail = newNode;
    this->length++;
}

template <typename T>
clsNode<T>* clsLinkedList<T>::find(T data) {
    clsIterator<T> it(head);
    while (it.current() != nullptr) {
        if (it.data() == data) { return it.current(); }
        it.moveNext();
    }
    return nullptr;
}

template <typename T>
void clsLinkedList<T>::insertAfter(T data, T newData) {
    if (isEmpty()) { return; }

    if (unique && !canInsert(data)) {
        return;
    }

    clsNode<T>* newNode = new clsNode<T>(newData);
    clsNode<T>* node = find(data);

    if (node == nullptr) { return; }

    newNode->setNext(node->next());
    node->setNext(newNode);

    if (newNode->next() == nullptr) {
        tail = newNode;
    }

    this->length++;
}

template <typename T>
clsNode<T>* clsLinkedList<T>::findParentNode(clsNode<T>* node) {
    clsIterator<T> it(head);
    while (it.current() != nullptr) {
        if (it.current()->next() == node) { return it.current(); }
        it.moveNext();
    }
    return nullptr;
}

template <typename T>
clsNode<T>* clsLinkedList<T>::findParentNode(T data) {
    clsIterator<T> it(head);
    while (it.current() != nullptr) {
        if (it.current()->next()->data() == data) { return it.current(); }
        it.moveNext();
    }
    return nullptr;
}

template <typename T>
void clsLinkedList<T>::insertBefore(T data, T newData) {
    if (isEmpty()) { return; }

    if (unique && !canInsert(data)) {
        return;
    }

    clsNode<T>* newNode = new clsNode<T>(newData);
    clsNode<T>* node = find(data);

    if (node == nullptr) { return; }

    newNode->setNext(node);
    if (node == head) {
        head = newNode;
        this->length++;
        return;
    }

    clsNode<T>* parent = findParentNode(node);
    parent->setNext(newNode);
    this->length++;
}

template <typename T>
void clsLinkedList<T>::deleteNode(T data) {
    clsNode<T>* node = find(data);
    if (node == nullptr) {
        return;
    }

    if ((node == head) && (node == tail)) {
        head = nullptr;
        tail = nullptr;
        delete node;
    }

    if (node == head) {
        head = head->next();
        delete node;
        this->length--;
        return;
    }

    clsNode<T>* parent = findParentNode(node);

    if (node == tail) {
        tail = parent;
        parent->setNext(nullptr);
        delete node;
        this->length--;
        return;
    }

    parent->setNext(node->next());
    delete node;
    this->length--;
}

template <typename T>
void clsLinkedList<T>::display() {
    clsIterator<T> it(head);
    for (it.current(); it.current() != nullptr; it.moveNext()) {
        if (it.current()->next() != nullptr) {
            cout << it.data() << " -> ";
        } else {
            cout << it.data();
        }
    }
    cout << endl;
}

template <typename T>
void clsLinkedList<T>::display(string newLine) {
    clsIterator<T> it(head);
    for (it.current(); it.current() != nullptr; it.moveNext()) {
        cout << it.data() << endl;
    }
    cout << "----" << endl;
}

} // namespace singlyList
