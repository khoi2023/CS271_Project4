#include <iostream>
#include "BST.hpp"

using namespace std;

void testBSTNode() {
    // Test default constructor
    BSTNode<int> node1;
    assert(node1.getParent() == nullptr);
    assert(node1.getLeftChild() == nullptr);
    assert(node1.getRightChild() == nullptr);

    // Test value assignment constructor
    BSTNode<int> node2(10);
    assert(node2.getValue() == 10);

    // Test copy constructor
    BSTNode<int> node3(node2);
    assert(node3.getValue() == 10);

    // Test assignment operator
    node1 = node2;
    assert(node1.getValue() == 10);

    // Test setValue
    int newValue = 20;
    node1.setValue(newValue);
    assert(node1.getValue() == 20);

    // Test setLeftChild and setRightChild
    node1.setLeftChild(&node2);
    node1.setRightChild(&node3);
    assert(node1.getLeftChild() == &node2);
    assert(node1.getRightChild() == &node3);

    // Test treeMin and treeMax
    assert(node1.treeMin() == &node2);
    assert(node1.treeMax() == &node3);

    cout << "BSTNode tests passed!" << endl;
}

void testBST() {
    // Test default constructor
    BST<int> tree;
    assert(tree.empty());
    assert(tree.size() == 0);

    // Test insert
    BSTNode<int>* node1 = tree.insert(10);
    assert(!tree.empty());
    assert(tree.size() == 1);
    assert(tree.search(10) == node1);

    // Test insert more nodes
    BSTNode<int>* node2 = tree.insert(5);
    BSTNode<int>* node3 = tree.insert(15);
    assert(tree.size() == 3);
    assert(tree.search(5) == node2);
    assert(tree.search(15) == node3);

    // Test treeMin and treeMax
    assert(tree.treeMin() == node2);
    assert(tree.treeMax() == node3);

    // Test erase
    tree.erase(node2);
    assert(tree.size() == 2);
    assert(tree.search(5) == nullptr);

    // Test traversals
    DoublyLinkedList<int> preOrder = tree.getPreOrderTraversal();
    DoublyLinkedList<int> inOrder = tree.getInOrderTraversal();
    DoublyLinkedList<int> postOrder = tree.getPostOrderTraversal();

    assert(preOrder.size() == 2);
    assert(inOrder.size() == 2);
    assert(postOrder.size() == 2);

    cout << "BST tests passed!" << endl;
}

int main() {
    testBSTNode();
    testBST();
    return 0;
}
