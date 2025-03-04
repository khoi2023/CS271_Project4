/*
File name: BST.hpp
Author: Michael C. Chavrimootoo
Last Updated: 02/20/2025
Creation Date: 02/20/2025
Description: Header file for the BST<> templated class
*/

#pragma once

#include "BSTNode.hpp"
#include <functional>

/*
This class expects to template parameters: a type T and a comparator Comparator, over T
To define custom comparisons, you must pass as your comparator a struct defined as follows.
The name of the struct is your choice, and defined by the programmer. The struct only needs to implement one operator,
as seen below.
*/
// This should be defined by the programmer
// template<class T>
// struct BSTComparator {
//     bool operator() (T* a, T* b) const {
//          return: true if a <= b, and false otherwise // you must implement this logic yourself when you want to customize the comparison.
//     }
// };



template<class T, typename Comparator = std::less_equal<T> >
class BST {

    private:
    void transplant(BSTNode<T> *oldNode, BSTNode<T> *newNode);
    void deleteSubTree(BSTNode<T> *node);
    BSTNode<T>* copySubTree(BSTNode<T> *node);

    BSTNode<T> *root;
    size_t numNodes;
    Comparator comparator;


    public:
    // default constructor
    BST<T, Comparator>(Comparator comparator = Comparator());


    // copy constructor
    BST<T, Comparator>(const BST<T, Comparator> &tree);


    // assignment operator
    BST<T, Comparator>& operator=(const BST<T, Comparator> &tree);


    // checks if is empty
    bool empty(void) const;


    // size
    size_t size(void) const;


    // destructor
    ~BST<T, Comparator>(void);


    // insert
    BSTNode<T>* insert(T value);
 
    
    // delete
    // throws std::invalid_argument if nodeToDelete == nullptr
    // throws std::length_error if tree is empty
    void erase(BSTNode<T>* nodeToDelete);


    // search
    BSTNode<T>* search(T value) const;


    // min
    // throws  std::length_error if tree is empty
    BSTNode<T>* treeMin(void) const;


    // max
    // throw std::length_error if tree is empty
    BSTNode<T>* treeMax(void) const;


    // preorder
    DoublyLinkedList<T> getPreOrderTraversal(void) const;


    // inorder
    DoublyLinkedList<T> getInOrderTraversal(void) const;


    // postorder
    DoublyLinkedList<T> getPostOrderTraversal(void) const;
};