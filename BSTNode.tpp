/*
BSTNode.tpp
A file that contains the implementation of the BSTNode class methods in the BSTNode.hpp file.
Written by: Khoi V.
*/

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <stdexcept>
#include "BSTNode.hpp"

using namespace std;

// Default constructor.
// Parameter: NONE.
// Return value: NONE.
template <class T>
BSTNode<T>::BSTNode(void) {
    parent = nullptr;
    left = nullptr;
    right = nullptr;
}

// Value assignment constructor.
// Parameter: A value to be assigned to the node.
// Return value: NONE.
template <class T>
BSTNode<T>::BSTNode(T value) {
    this->value = value;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
}

// Copy constructor.
// Parameter: A given BSTNode.
// Return value: NONE.
template <class T>
BSTNode<T>::BSTNode(const BSTNode<T> &node) {
    this->value = node.value;
    this->parent = node.parent;
    this->left = node.left;
    this->right = node.right;
}

// Assignment operator.
// Parameter: A given BSTNode.
// Return value: A new BSTNode which is exactly the same as the node being assigned.
template <class T>
BSTNode<T>& BSTNode<T>::operator=(const BSTNode<T> &rhs) {
    if (this == &rhs) {
        return *this;  // Self-assignment check
    }
    this->value = rhs.value;
    this->parent = rhs.parent;
    this->left = rhs.left;
    this->right = rhs.right;
    return *this;  // Allow chain assignments
}

// Get value.
// Parameter: NONE.
// Return value: The value of the node.
template <class T>
T& BSTNode<T>::getValue(void) {
    return value;
}

// Get parent.
// Parameter: NONE.
// Return value: The parent of the node.
template <class T>
BSTNode<T> * BSTNode<T>::getParent(void) {
    return parent;
}

// Get left child.
// Parameter: NONE.
// Return value: The left child of the node.
template <class T>
BSTNode<T> * BSTNode<T>::getLeftChild(void) {
    return left;
}

// Get right child.
// Parameter: NONE.
// Return value: The right child of the node.
template <class T>
BSTNode<T> * BSTNode<T>::getRightChild(void) {
    return right;
}

// Set value.
// Parameter: A value to be assigned to the node.
// Return value: NONE.
template <class T>
void BSTNode<T>::setValue(T &value) {
    this->value = value;
}

// Nullify parent.
// Parameter: NONE.
// Return value: NONE.
template <class T>
void BSTNode<T>::nullifyParent(void) {
    parent = nullptr;
}

// Set left child.
// Parameter: A pointer to a new node. This sets the left child of the node to this new node. 
// Return value: NONE.
template <class T>
void BSTNode<T>::setLeftChild(BSTNode<T> *node) {
    left = node;
}

// Set right child.
// Parameter: A pointer to a new node. This sets the right child of the node to this new node.
// Return value: NONE.
template <class T>
void BSTNode<T>::setRightChild(BSTNode<T> *node) {
    right = node;
}

// Get minimum value in its subtree.
// Parameter: NONE.
// Return value: The node with the minimum value in the subtree in which the node is the root.
template <class T>
BSTNode<T>* BSTNode<T>::treeMin(void) {
    BSTNode<T> *current = this;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// Get maximum value in its subtree.
// Parameter: NONE.
// Return value: The node with the maximum value in the subtree in which the node is the root.
template <class T>
BSTNode<T>* BSTNode<T>::treeMax(void) {
    BSTNode<T> *current = this;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current;
}

// Preorder traversal.
// Parameter: NONE.
// Return value: A DoublyLinkedList of the values in the subtree in which the node is the root, in preorder.
template <class T>
DoublyLinkedList<T> BSTNode<T>::getPreOrderTraversal(void) const {
    DoublyLinkedList<T> list;
    list.push_back(this->value);
    if (left != nullptr) {
        DoublyLinkedList<T> leftList = left->getPreOrderTraversal();
        list = list.concatenate(leftList);
    }
    if (right != nullptr) {
        DoublyLinkedList<T> rightList = right->getPreOrderTraversal();
        list = list.concatenate(rightList);
    }
    return list;
}

// Inorder traversal.
// Parameter: NONE.
// Return value: A DoublyLinkedList of the values in the subtree in which the node is the root, in inorder.
template <class T>
DoublyLinkedList<T> BSTNode<T>::getInOrderTraversal(void) const {
    DoublyLinkedList<T> list;
    if (left != nullptr) {
        DoublyLinkedList<T> leftList = left->getInOrderTraversal();
        list = list.concatenate(leftList);
    }
    list.push_back(this->value);
    if (right != nullptr) {
        DoublyLinkedList<T> rightList = right->getInOrderTraversal();
        list = list.concatenate(rightList);
    }
    return list;
}

// Postorder traversal.
// Parameter: NONE.
// Return value: A DoublyLinkedList of the values in the subtree in which the node is the root, in postorder.
template <class T>
DoublyLinkedList<T> BSTNode<T>::getPostOrderTraversal(void) const {
    DoublyLinkedList<T> list;
    if (left != nullptr) {
        DoublyLinkedList<T> leftList = left->getPostOrderTraversal();
        list = list.concatenate(leftList);
    }
    if (right != nullptr) {
        DoublyLinkedList<T> rightList = right->getPostOrderTraversal();
        list = list.concatenate(rightList);
    }
    list.push_back(this->value);
    return list;
}

// Destructor.
// Parameter: NONE.
// Return value: NONE.
template <class T>
BSTNode<T>::~BSTNode(void) {
    // Do nothing.
    // The destructor of the BST class will take care of deleting the nodes.
    // This is because the nodes are dynamically allocated.
    // If we delete the nodes here, it will cause a double deletion error.
}
