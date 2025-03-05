/*
BSTNode.tpp
A file that contains the implementation of the BST class methods in the BSTNode.hpp file.
Written by: Duc T.
*/

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <stdexcept>
#include "BST.hpp"

using namespace std;

// Comparison struct
// Description: This struct is used to compare two values of type T.
// Parameters: two values of type T, a and b.
// Return value: true if a <= b, and false otherwise
template<class T>
struct BSTComparator {
    bool operator() (T a, T b) const {
        return a <= b;
    }
};

// Transplant function.
// Description: This function replaces one subtree as a child of its parent with another subtree.
// Parameters: the root of the subtree to be replaced, the root of the subtree to replace it with.
// Return value: NONE.
template<class T, typename Comparator>
void BST<T,Comparator>::transplant(BSTNode<T> *oldNode, BSTNode<T> *newNode){
    if (oldNode -> parent == NULL){
        this -> root = newNode;
    }
    else if (oldNode->parent->left == oldNode){
        oldNode->parent->left = newNode;
    }
    else {
        oldNode->parent->right = newNode
    }
    if (newNode != NULL){
        newNode->parent = oldNode->parent;
    }
}

// Delete subtree function.
// Description: This function deletes the subtree rooted at a given node.
// Parameters: the root of the subtree to be deleted.
// Return value: NONE.
template<class T, typename Comparator>
void BST<T,Comparator>::deleteSubTree(BSTNode<T> *node){
    if (node != NULL){
        deleteSubTree(node->left);
        deleteSubTree(node->right);
        delete node;
    }
}

// Copy subtree function.
// Description: This function performs a deep copy of the subtree rooted at a given node.
// Parameters: the root of the subtree to be copied.
// Return value: the root of the copied subtree.
template<class T, typename Comparator>
BSTNode<T>* BST<T,Comparator>::copySubTree(BSTNode<T> *node){
    if (node == NULL){
        return NULL;
    }
    BSTNode<T> *newNode = new BSTNode<T>(node - >value);
    newNode->left = copySubTree(node->left);
    newNode->right = copySubTree(node->right);
    return newNode;
}

// Default constructor.
// Description: This function constructs an empty BST.
// Parameters: NONE.
// Return value: NONE.
template<class T, typename Comparator>
BST<T,Comparator>::BST(Comparator comparator = Comparator()){
    root = NULL;
    numNodes = 0;
    comparator = comparator;
}

// Copy constructor.
// Description: This function constructs a BST that is a deep copy of another BST.
// Parameters: a given BST.
// Return value: NONE.
template<class T, typename Comparator>
BST<T,Comparator>::BST(const BST<T, Comparator> &tree){
    root = copySubTree(tree.root);
    numNodes = tree.numNodes;
    comparator = tree.comparator;
}

// Assignment operator.
// Description: This function assigns a BST to another BST.
// Parameters: a given BST.
// Return value: a new BST which is exactly the same as the BST being assigned.
template<class T, typename Comparator>
BST<T, Comparator>& BST<T,Comparator>::operator=(const BST<T, Comparator> &tree){
    if (this != &tree){
        deleteSubTree(root);
        root = copySubTree(tree.root);
        numNodes = tree.numNodes;
        comparator = tree.comparator;
    }
    return *this;
}

// Checks if is empty.
// Description: This function checks if the BST is empty.
// Parameters: NONE.
// Return value: true if the BST is empty, and false otherwise.
template<class T, typename Comparator>
bool BST<T,Comparator>::empty(void) const{
    return numNodes == 0;
}

// Size.
// Description: This function returns the number of nodes in the BST.
// Parameters: NONE.
// Return value: the number of nodes in the BST.
template<class T, typename Comparator>
size_t BST<T,Comparator>::size(void) const{
    return numNodes;
}

// Destructor.
// Description: This function destroys the BST.
// Parameters: NONE.
// Return value: NONE.
template<class T, typename Comparator>
BST<T,Comparator>::~BST<T, Comparator>(void){
    deleteSubTree(root);
}

// Insert function.
// Description: This function inserts a value into the BST.
// Parameters: a value to be inserted.
// Return value: the node that was inserted.
template<class T, typename Comparator>
BSTNode<T>* BST<T,Comparator>::insert(T value){
    BSTNode<T>* newNode = new BSTNode<T>(value);
    BSTNode<T>* parent = NULL;
    BSTNode<T>* current = root;

    while (current != NULL) {
        parent = current;
        if (comparator(value, current->value)) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    newNode->parent = parent;
    if (parent == NULL) {
        root = newNode;
    } else if (comparator(value, parent->value)) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    numNodes++;
    return newNode;
}

// Delete function.
// Description: This function deletes a node from the BST.
// Parameters: the node to be deleted.
// Return value: NONE.
// throws std::invalid_argument if nodeToDelete == nullptr.
// throws std::length_error if tree is empty.
template<class T, typename Comparator>
void BST<T,Comparator>::erase(BSTNode<T>* nodeToDelete){
    if (nodeToDelete == NULL){
        throw invalid_argument("Can not delete a null node");
    }
    if (numNodes == 0){
        throw length_error("Tree is empty");
    }
    if (nodeToDelete->left == NULL){
        transplant(nodeToDelete,nodeToDelete->right);
    }
    else if (nodeToDelete-> right == NULL){
        transplant(nodeToDelete,nodeToDelete->left);
    }
    else{
        BSTNode<T> *successor = treeMin();
        if (successor != nodeToDelete->right){
            transplant(successor,successor->right);
            successor->right = nodeToDelete->right;
            successor->right->parent = successor;
        }
        transplant(nodeToDelete,successor);
        successor->left = nodeToDelete->left;
        successor->left->parent = successor;
    }
    delete nodeToDelete;
    numNodes --;
}

// Search function.
// Description: This function searches for a value in the BST.
// Parameters: a value to be searched.
// Return value: the node that contains the value, or NULL if the value is not found.
template<class T, typename Comparator>
BSTNode<T>* BST<T,Comparator>::search(T value) const{
    BSTNode<T> *current = root;
    while (current && current->value!= value){
        if (comparator(value,current->value)){
            current = current->left;
        }
        else{
            current = current->right;
        }
    }
    return current;
}

// Min function.
// Description: This function returns the node with the minimum value in the BST.
// Parameters: NONE.
// Return value: the node with the minimum value in the BST.
// throws std::length_error if tree is empty.
template<class T, typename Comparator>
BSTNode<T>* BST<T,Comparator>::treeMin(void) const{
    if (numNodes == 0){
        throw length_error("Tree is empty!");
    }
    return root->treeMin();
}

// Max function.
// Description: This function returns the node with the maximum value in the BST.
// Parameters: NONE.
// Return value: the node with the maximum value in the BST.
// throws std::length_error if tree is empty.
template<class T, typename Comparator>
BSTNode<T>* BST<T,Comparator>::treeMax(void) const{
    if (numNodes == 0){
        throw length_error("Tree is empty!");
    }
    return root->treeMax();
}

// Preorder traversal.
// Description: This function returns the values in the BST in preorder.
// Parameters: NONE.
// Return value: a DoublyLinkedList of the values in the BST in preorder.
// throws std::length_error if tree is empty.
template<class T, typename Comparator>
DoublyLinkedList<T> BST<T,Comparator>::getPreOrderTraversal(void) const{
    if (numNodes == 0){
        throw length_error("Tree is empty!");
    }
    return root->getPreOrderTraversal();
}

// Inorder traversal.
// Description: This function returns the values in the BST in inorder.
// Parameters: NONE.
// Return value: a DoublyLinkedList of the values in the BST in inorder.
// throws std::length_error if tree is empty.
template<class T, typename Comparator>
DoublyLinkedList<T> BST<T,Comparator>::getInOrderTraversal(void) const{
    if (numNodes == 0){
        throw length_error("Tree is empty!");
    }
    return root->getInOrderTraversal();
}

// Postorder traversal.
// Description: This function returns the values in the BST in postorder.
// Parameters: NONE.
// Return value: a DoublyLinkedList of the values in the BST in postorder.
// throws std::length_error if tree is empty.
template<class T, typename Comparator>
DoublyLinkedList<T> BST<T,Comparator>::getPostOrderTraversal(void) const{
    if (numNodes == 0){
        throw length_error("Tree is empty!");
    }
    return root->getPostOrderTraversal();
}