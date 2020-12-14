//
// Created by Brayon on 2020-11-11.
//

#include <Node.hpp>

using namespace std;

template<typename T>
Node<T>::Node() : next_(nullptr), prev_(nullptr) {}

template<typename T>
Node<T>::Node(T value) : next_(nullptr), prev_(nullptr) {
    this->value_ = make_unique<T>(value);
}

template<typename T>
Node<T>::Node(node_ptr& previous) : next_(nullptr), prev_(previous) {
    this->value_ = make_unique<T>();
}

template<typename T>
Node<T>::Node(node_ptr&& previous) : next_(nullptr), prev_(previous) {
    this->value_ = make_unique<T>();
}

template<typename T>
Node<T>::Node(node_ptr& previous, T value) : next_(nullptr), prev_(previous) {
    this->value_ = make_unique<T>(value);
}

template<typename T>
T Node<T>::value() const{
    return *this->value_;
}

template<typename T>
unique_ptr<T>& Node<T>::value_ptr() {
    return this->value_;
}

template<typename T>
typename Node<T>::node_ptr& Node<T>::next() {
    return this->next_;
}

template<typename T>
typename Node<T>::node_ptr& Node<T>::prev() {
    return this->prev_;
}

template<typename T>
void Node<T>::setNext(node_ptr &nextNode) {
    this->next_ = nextNode;
}

template<typename T>
void Node<T>::setNext(node_ptr &&nextNode) {
    this->next_ = nextNode;
}

template<typename T>
void Node<T>::setPrev(node_ptr &prevNode) {
    this->prev_ = prevNode;
}

template<typename T>
void Node<T>::setPrev(node_ptr &&prevNode) {
    this->prev_ = prevNode;
}
