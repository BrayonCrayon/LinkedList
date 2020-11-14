//
// Created by Brayon on 2020-11-08.
//

#ifndef LINKEDLIST_LINKEDLIST_HPP
#define LINKEDLIST_LINKEDLIST_HPP

#include <Node.hpp>
#include <initializer_list>

using namespace std;

template<typename T>
class LinkedList {

    using node_ptr = typename Node<T>::node_ptr;
    node_ptr node_;
    size_t size_;

public:

    LinkedList();

    explicit LinkedList(size_t size);

    LinkedList(size_t size, T value);

    LinkedList(std::initializer_list<T>);

    ~LinkedList();

    [[nodiscard]] size_t size() const;

    [[nodiscard]] node_ptr &head();

};

#endif //LINKEDLIST_LINKEDLIST_HPP
