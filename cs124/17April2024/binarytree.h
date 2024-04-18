/*******************************************************

 * Program Name: binarytree.h

 * Author: Lucas Gobaco

 * Date: 17 April 2024

 * Description: This program defines a binary tree and a function that counts the number of nodes with one child in the tree.

 *******************************************************/

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <string>

using namespace std;

template <typename T>
class Node
{
private:
    T data;
    Node* left;
    Node* right;
   friend class Binary_tree;
};

/*
   A binary tree in which each node has two children.
*/
template <typename T>
class Binary_tree
{
public:
    /**
       Constructs an empty tree.
    */
    Binary_tree();

    /**
       Constructs a tree with one node and no children.
       @param root_data the data for the root
    */
    Binary_tree(T root_data);

    /**
       Constructs a binary tree.
       @param root_data the data for the root
       @param left the left subtree
       @param right the right subtree
    */
    Binary_tree(T root_data, Binary_tree<T> left, Binary_tree<T> right);

    /**
       Returns the height of this tree.
       @return the height
    */
    int height() const;

    /**
       Checks whether this tree is empty.
       @return true if this tree is empty
    */
    bool empty() const;

    /**
       Gets the data at the root of this tree.
       @return the root data
    */
    T data() const;

    /**
       Gets the left subtree of this tree.
       @return the left child of the root
    */
    Binary_tree<T> left() const;

    /**
       Gets the right subtree of this tree.
       @return the right child of the root
    */
    Binary_tree<T> right() const;
    /**
       Counts the number of nodes with one child
       @return the number of nodes with one child
    */
    int count_nodes_with_one_child () const;

    /**
       Counts the number of nodes with one child in the
       tree anchored at this node
       @return the number of nodes with one child
    */
    int count_nodes_with_one_child (Node<T>*) const;

private:
    /**
       Returns the height of the subtree whose root is the given node.
       @param n a node or nullptr
       @return the height of the subtree, or 0 if n is nullptr
    */
    int height(const Node<T>* n) const;

    Node<T>* root;
};

#endif