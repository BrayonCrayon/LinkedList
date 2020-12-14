//
// Created by Brayon on 2020-11-08.
//

#ifndef LINKEDLIST_LINKEDLIST_HPP
#define LINKEDLIST_LINKEDLIST_HPP

#include <Node.hpp>
#include <initializer_list>
#include <iterator>

template<typename T>
class LinkedList {

    using node_ptr = typename Node<T>::node_ptr;
    node_ptr node_;
    size_t size_;

public:
    // Iterators
    class Iterator;

    LinkedList();

    explicit LinkedList(size_t size);

    LinkedList(size_t size, T value);

    LinkedList(std::initializer_list<T>);

    LinkedList(const LinkedList<T> &);

    LinkedList(LinkedList<T>&&) noexcept;

    ~LinkedList();

    [[nodiscard]] size_t size() const;

    [[nodiscard]] node_ptr head() const;

    void insert(T value, size_t index);

    void insert(T value);

    void erase(size_t index);

    [[nodiscard]] node_ptr findLast();

    [[nodiscard]] node_ptr findAt(int index);

    [[nodiscard]] node_ptr operator[](int index);

    [[nodiscard]] Iterator begin();
    [[nodiscard]] Iterator end();

};

template<typename T>
class LinkedList<T>::Iterator {
    node_ptr _ptr;
public:
    using _iterator_category = std::forward_iterator_tag;
    using value_type = node_ptr;
    using difference_type = node_ptr;
    using pointer = node_ptr*;
    using reference = node_ptr&;

    Iterator();
    explicit Iterator(node_ptr ptr);
    explicit Iterator(node_ptr&& ptr);
    Iterator& operator++();
    Iterator& operator--();

    Iterator& operator++(int);
    Iterator& operator--(int);

    node_ptr& operator->();
    node_ptr& operator*();

};

#endif //LINKEDLIST_LINKEDLIST_HPP
