/*
File name: DoublyLinkedList.hpp
Author: Michael C. Chavrimootoo
Last Updated: 01/16/2025
Creation Date: 09/02/2024
Description: Header file for the DoublyLinkedList<> templated class
*/


/*
ABOUT THIS FILE:
- This file contains the class definition for DoublyLinkedList<T>.
- DO NOT MODIFY THIS FILE
- You should implement DoublyLinkedList.cpp yourself.
- Each method has a docstring describing it. You will be tested on the correctness of your methods, based on the docstring descriptions.
- The naming conventions may seem new to you (e.g., `push_back` or `pop_front` or `erase`, etc.), but those are standard C++ names, as you can see by exploring any standard container in the C++ STL.
*/

// Modern way of doing include guards; nothing wrong with the old way
#pragma once
#include <iostream>


template<class T>
class DoublyLinkedList{

    private:
    // Private struct for the nodes of the linked list
    struct Node{
        // Value of the node
        T value;
        // Pointer the node preceding the current node
        Node *prev;
        // Pointer to the node following the current node
        Node *next;

        /*
        Description:
            - Default Constructor for DoublyLinkedList<T>::Node
        Parameters: None
        Return: None
        Exceptions: None
        */
        Node() : prev(nullptr), next(nullptr) {}


        /*
        Description:
            - Value constructor for DoublyLinkedList<T>::Node
        Parameters:
            - const T &item: the value to assign to the node
        Return: None
        Exceptions: None
        */
        Node(const T &item) : value(item), prev(nullptr), next(nullptr) {}
        
        
        /*
        Description:
            - Destructor for DoublyLinkedList<T>::Node
        Parameters: None
        Return: None
        Exceptions: None
        */
        ~Node() {}
    };
    
    // Pointer to the head node
    Node* head;
    // Pointer to the tail node
    Node* tail;
    // Member keeping track of the number of elements in the list
    size_t numElements;

    /*
    Description:
        - Computes the pointer to the node at the specified index
    Parameters: 
        - size_t index: the specified index as (unsigned)
    Return: a pointer of type Node
    Exceptions:
        - std::out_of_range if the index is greater than the number of elements in the list
    */
    Node* getPointer(size_t index); // this is private, so keep pointer


    public:

    /*
    Description:
        - Default Constructor for DoublyLinkedList<T>
    Parameters: None
    Return: None
    Exceptions: None
    */
    DoublyLinkedList<T>(void);


    /*
    Description:
        - Copy Constructor for DoublyLinkedList<T>; copies the data in the nodes too. 
        - If `T`, the template parameter, does not have a copy constructor, the behavior is undefined. (There are ways to force `T` to have a copy constructor at compile time, but it's messy and not worth diving into in this course.)
    Parameters: 
        - DoublyLinkedList<T> rhs: Doubly-linked list to copy
    Return: None
    Exceptions: None
    */
    DoublyLinkedList<T>(const DoublyLinkedList<T>& list);


    /*
    Description:
        - Assignment Operator for DoublyLinkedList<T>
        - If `T`, the template parameter, does not have a copy constructor, the behavior is undefined. (There are ways to force `T` to have a copy constructor at compile time, but it's messy and not worth diving into in this course.)
    Parameters: 
        - DoublyLinkedList<T> rhs: Doubly-linked list assign
    Return: None
    Exceptions: None
    Note: 
        - This may defer from what you've seen in CS 173; here, rhs is not a const reference, which allows the compiler to insert a call to the copy constructor and optimize in ways we couldn't. 
    */
    DoublyLinkedList<T>& operator=(DoublyLinkedList<T> rhs);


    /*
    Description:
        - Destructor for DoublyLinkedList<T>
    Parameters: None
    Return: None
    Exceptions: None
    */
    ~DoublyLinkedList<T>(void);


    /*
    Description:
        - Inserts `item` at position `index` in the list.
    Parameters:
        - const T &item: a const reference to the item to be inserted
        - size_t index: the index at which to place `item`
    Return: None
    Exceptions:
        - std::out_of_range if `index` exceeds the size of the list
    */
    void insert(const T &item, size_t index);


    /*
    Description:
        - Erases the node at position `index`, freeing the memory allocated to the node and updating the surrounding pointers to keep integrity of the list
    Parameters:
        - size_t index: the position of the node to delete
    Return: None
    Exceptions:
        - std::out_of_range if `index` is invalid
    */
    void erase(size_t index);


    /*
    Description:
        - Returns the index of the first node with value equal to `item`
    Parameters:
        - const T &item: the value to be searched for in the list
    Return:
        - The smallest index of a node containing value equal to `item`. If no such node exists, return the value of numElements (which is not a valid index)
    Exceptions: None
    */
    size_t search(const T &item) const;


    /*
    Description:
        - Inserts item at the front of the list
    Parameters:
        - const T &item: the value to be inserted
    Return: None
    Exceptions: None
    */
    void push_front(const T &item);


    /*
    Description:
        - Inserts item at the end of the list
    Parameters:
        - const T &item: the value to be inserted
    Return: None
    Exceptions: None
    */
    void push_back(const T &item);


    /*
    Description:
        - Erases the node at the front of the list and returns its value
    Parameters: None
    Return:
        - The value of the node previously at the front of the list
    Exceptions:
        - std::out_of_range if the list is empty
    */
    T pop_front(void);


    /*
    Description:
        - Erases the node at the back of the list and returns its value
    Parameters: None
    Return:
        - The value of the node previously at the back of the list
    Exceptions:
        - std::out_of_range if the list is empty
    */
    T pop_back(void);


    /*
    Description:
        - Finds the node at position `index` and returns a reference to its value
    Parameters:
        - size_t index: index of the value to find
    Return:
        - A reference to the value of the node at position `index`
    Exceptions:
        - std::out_of_range if `index` is invalid
    */
    T& operator[](size_t index);


    /*
    Description:
        - Computes the size of the list
    Parameters: None
    Return:
        - The size of the list
    Exceptions: None
    */
    size_t size(void) const;


    /*
    Description:
        - Determines if the list is empty
    Parameters: None
    Return:
        - `true` if the list is empty, `false` otherwise
    Exceptions: None
    */
    bool empty(void) const;


    /*
    Description:
        - Concatenates the current list and `list` by constructing a new list that starts with the elements of the current list (in order) followed by the elements of `list` (in order)
    Parameters:
        - const DoublyLinkedList<T> &list: the list to concatenate the current list with
    Return:
        - The newly constructed list created from the concatenation
    Exceptions: None
    */
    DoublyLinkedList<T> concatenate(const DoublyLinkedList<T> &list) const;


    /*
    Description:
        - Checks if `rhs` is equal to the current list.
        - Equality holds if the two lists have the same length, and for each index i, the elements at position i in both lists are equal
    Parameters:
        - const DoublyLinkedList<T> &rhs: the list to compare the current list with
    Returns:
        - `true` if the two lists are equal, `false` otherwise
    Exceptions: None
    */
    bool operator==(const DoublyLinkedList<T> &rhs) const;


    /*
    Description:
        - Checks if `rhs` is not equal to the current list.
        - Equality holds if the two lists have the same length, and for each index i, the elements at position i in both lists are equal
    Parameters:
        - const DoublyLinkedList<T> &rhs: the list to compare the current list with
    Returns:
        - `false` if the two lists are equal, `true` otherwise
    Exceptions: None
    */
    bool operator!=(const DoublyLinkedList<T> &rhs) const;
};


// Because our class is templated, we must do this to the
// allow the compile to implicitly instantiate the class
// the .tpp extension indicates that the file contains template definitions
