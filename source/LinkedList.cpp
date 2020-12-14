//
// Created by Brayon on 2020-11-08.
//

#include <LinkedList.hpp>
#include <iostream>

using namespace std;

/*
 ***************************************
 **** Constructors                  ****
 ***************************************
 */

template<typename T>
LinkedList<T>::LinkedList() : size_(0) {}

template<typename T>
LinkedList<T>::LinkedList(size_t size) : size_(size) {
    if (this->size_ <= 0) {
        return;
    }

    this->node_ = make_shared<Node<T>>(T());
    node_ptr currentNode = this->node_;
    for (size_t i = 1; i < this->size_; ++i) {
        currentNode->setNext(make_shared<Node<T>>(currentNode));
        currentNode = currentNode->next();
    }
    currentNode->setNext(make_shared<Node<T>>());
    currentNode->next()->setPrev(currentNode);
}

template<typename T>
LinkedList<T>::LinkedList(size_t size, T value) : size_(size) {
    if (this->size_ <= 0) {
        return;
    }

    this->node_ = make_shared<Node<T>>(value);
    node_ptr currentNode = this->node_;
    for (size_t i = 1; i < this->size_; ++i) {
        currentNode->setNext(make_shared<Node<T>>(currentNode, value));
        currentNode = currentNode->next();
    }
    currentNode->setNext(make_shared<Node<T>>());
    currentNode->next()->setPrev(currentNode);
}

template<typename T>
LinkedList<T>::LinkedList(initializer_list<T> args) : size_(args.size()) {
    if (this->size_ <= 0) {
        return;
    }

    auto it = args.begin();
    this->node_ = make_shared<Node<T>>(*it++);
    node_ptr currentNode = this->node_;
    for (size_t i = 1; i < this->size_; ++i, ++it) {
        currentNode->setNext(make_shared<Node<T>>(currentNode, *it));
        currentNode = currentNode->next();
    }
    currentNode->setNext(make_shared<Node<T>>());
    currentNode->next()->setPrev(currentNode);
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> & listToCopy) : size_(listToCopy.size()) {
    if (this->size_ <= 0) {
        return;
    }

    node_ptr currentNodeToCopy = listToCopy.head();
    this->node_ = make_shared<Node<T>>(currentNodeToCopy->value());
    node_ptr currentNode = this->node_;

    for (size_t i = 1; i < size_; ++i) {
        currentNodeToCopy = currentNodeToCopy->next();
        currentNode->setNext(make_shared<Node<T>>(currentNode, currentNodeToCopy->value()));
        currentNode = currentNode->next();
    }
    currentNode->setNext(make_shared<Node<T>>());
    currentNode->next()->setPrev(currentNode);
}

template<typename T>
LinkedList<T>::LinkedList(LinkedList<T> && listToMove) noexcept : size_(listToMove.size()) {
    listToMove.size_ = 0;
    this->node_ = listToMove.head();
    listToMove.node_.reset();
    listToMove.node_ = nullptr;
}

template<typename T>
LinkedList<T>::~LinkedList() = default;

/*
 ***************************************
 **** Member Functions              ****
 ***************************************
 */

template<typename T>
size_t LinkedList<T>::size() const {
    return this->size_;
}

template<typename T>
typename LinkedList<T>::node_ptr LinkedList<T>::head() const {
    return this->node_;
}

template<typename T>
typename LinkedList<T>::node_ptr LinkedList<T>::findAt(int index) {
    if (index >= this->size_ || index < 0) {
        throw range_error("Index is out of range: " + to_string(index));
    }

    node_ptr currentNode = this->node_;
    for (int i = 0; i < index; ++i) {
        currentNode = currentNode->next();
    }
    return currentNode;
}

template<typename T>
typename LinkedList<T>::node_ptr LinkedList<T>::findLast() {
    node_ptr currentNode = this->node_;
    for (int i = 0; i < this->size_; ++i) {
        if (currentNode->next()->value_ptr() == nullptr) {
            break;
        }
        currentNode = currentNode->next();
    }
    return currentNode;
}

template<typename T>
void LinkedList<T>::insert(T value, size_t index) {

    if (this->node_ == nullptr) {
        this->node_ = make_shared<Node<T>>(value);
    }
    else {
        node_ptr foundNode = this->findAt(index);
        node_ptr newNode = make_shared<Node<T>>(foundNode->prev(), value);
        newNode->setNext(foundNode);
        foundNode->prev()->setNext(newNode);
        foundNode->setPrev(newNode);
    }

    ++this->size_;
}

template<typename T>
void LinkedList<T>::insert(T value) {
    if (this->node_ == nullptr) {
        this->node_ = make_shared<Node<T>>(value);
        this->node_->setNext(make_shared<Node<T>>());
        this->node_->next()->setPrev(this->node_);
    }
    else {
        node_ptr lastNode = this->findLast();
        lastNode->setNext(make_shared<Node<T>>(lastNode, value));
    }
    ++this->size_;
}

template<typename T>
void LinkedList<T>::erase(size_t index) {
    if (index >= this->size_ || index < 0) {
        throw range_error("Index is out of range: " + to_string(index));
    }

    node_ptr currentNode = this->node_;
    for (int i = 0; i < index; ++i) {
        currentNode = currentNode->next();
    }

    node_ptr nextNode = currentNode->next();
    node_ptr prevNode = currentNode->prev();

    nextNode->setPrev(prevNode);
    prevNode->setNext(nextNode);
    currentNode->setPrev(nullptr);
    currentNode->setNext(nullptr);
    currentNode.reset();
    --this->size_;
}

template<typename T>
typename LinkedList<T>::Iterator LinkedList<T>::begin() {
    return Iterator(this->node_);
}

template<typename T>
typename LinkedList<T>::Iterator LinkedList<T>::end() {
    return Iterator(this->findLast()->next());
}

/*
 ***************************************
 **** Overloaded Operators          ****
 ***************************************
 */

template<typename T>
typename LinkedList<T>::node_ptr LinkedList<T>::operator[](int index) {
    return this->findAt(index);
}

/*
 ***************************************
 **** Iterator                      ****
 ***************************************
 */

template<typename T>
LinkedList<T>::Iterator::Iterator() {}

template<typename T>
LinkedList<T>::Iterator::Iterator(node_ptr ptr) : _ptr(ptr) {}

template<typename T>
LinkedList<T>::Iterator::Iterator(node_ptr&& ptr) : _ptr(ptr) {}

template<typename T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator++() {
    this->_ptr = this->_ptr->next();
    return *this;
}

template<typename T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator++(int) {
    this->_ptr = this->_ptr->next();
    return *this;
}

template<typename T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator--() {
    this->_ptr = this->_ptr->prev();
    return *this;
}

template<typename T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator--(int) {
    this->_ptr = this->_ptr->prev();
    return *this;
}

template<typename T>
typename LinkedList<T>::node_ptr& LinkedList<T>::Iterator::operator*() {
    return this->_ptr;
}

template<typename T>
typename LinkedList<T>::node_ptr& LinkedList<T>::Iterator::operator->() {
    return this->_ptr;
}