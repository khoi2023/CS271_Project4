/*
File name: BSTNode.hpp
Author: Michael C. Chavrimootoo
Last Updated: 02/20/2025
Creation Date: 02/20/2025
Description: Header file for the BSTNode<> templated class
*/

#pragma once

// include your DoublyLinkedList files from Project 1!
#include "DoublyLinkedList.hpp"
#include "DoublyLinkedList.tpp"


template<class T>
class BSTNode {
    private:
    // attributes
    T value;
    BSTNode<T> *parent, *left, *right;

    public:

    // default constructor
    BSTNode<T>(void);


    // value constructor
    BSTNode<T>(T value);


    //copy constructor
    BSTNode<T>(const BSTNode<T> &node);


    //assignment operator
    BSTNode<T>& operator=(const BSTNode<T> &rhs);


    //getValue
    T& getValue(void);


    //getParent
    BSTNode<T> * getParent(void);


    //getLeftChild
    BSTNode<T> * getLeftChild(void);


    //getRightChild
    BSTNode<T> * getRightChild(void);


    //setValue
    void setValue(T &value);


    //nullify parent; sets parent to nullptr
    void nullifyParent(void);


    //setLeft
    void setLeftChild(BSTNode<T> *node);


    //setRight
    void setRightChild(BSTNode<T> *node);


    //min
    BSTNode<T>* treeMin(void);


    //max
    BSTNode<T>* treeMax(void);


    // preorder
    DoublyLinkedList<T> getPreOrderTraversal(void) const;


    // inorder
    DoublyLinkedList<T> getInOrderTraversal(void) const;


    // postorder
    DoublyLinkedList<T> getPostOrderTraversal(void) const;


    //destructor
    ~BSTNode<T>(void);
};
