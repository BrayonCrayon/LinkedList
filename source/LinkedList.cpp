//
// Created by Brayon on 2020-11-08.
//

#include <LinkedList.hpp>

using namespace std;

template<typename T>
LinkedList<T>::LinkedList() : size_(0) {}

template<typename T>
LinkedList<T>::LinkedList(size_t size) : size_(size) {
    if (this->size_ <= 0) {
        return;
    }

    this->node_ = make_shared<Node<T>>();
    node_ptr currentNode = this->node_;
    for (size_t i = 1; i < this->size_; ++i) {
        currentNode->setNext(make_shared<Node<T>>(currentNode));
        currentNode = currentNode->next();
    }
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
}

template<typename T>
LinkedList<T>::LinkedList(initializer_list<T> args) : size_(args.size()) {
    if (this->size_ <= 0) {
        return;
    }

    auto it = args.begin();
    this->node_ = make_shared<Node<T>>(*it);
    node_ptr currentNode = this->node_;
    for (size_t i = 1; i < this->size_; ++i) {
        ++it;
        currentNode->setNext(make_shared<Node<T>>(currentNode, *it));
        currentNode = currentNode->next();
    }
}

template<typename T>
LinkedList<T>::~LinkedList() = default;

template<typename T>
size_t LinkedList<T>::size() const {
    return this->size_;
}

template<typename T>
typename LinkedList<T>::node_ptr &LinkedList<T>::head() {
    return this->node_;
}