//
// Created by Brayon on 2020-11-11.
//

#ifndef LINKEDLIST_NODE_HPP
#define LINKEDLIST_NODE_HPP

#include <memory>

template<typename T>
class Node {
public:
    using node_ptr = std::shared_ptr<Node<T>>;

private:
    std::unique_ptr<T> value_;
    node_ptr next_;
    node_ptr prev_;
public:

    Node();

    explicit Node(T value);

    explicit Node(node_ptr &previous);

    explicit Node(node_ptr &&previous);

    explicit Node(node_ptr &previous, T value);

    T value() const;
    std::unique_ptr<T>& value_ptr();

    node_ptr &next();

    node_ptr &prev();

    void setNext(node_ptr &nextNode);
    void setNext(node_ptr &&nextNode);

    void setPrev(node_ptr &prevNode);
    void setPrev(node_ptr &&prevNode);
};

#endif //LINKEDLIST_NODE_HPP
