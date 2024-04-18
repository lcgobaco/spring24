/*******************************************************

 * Program Name: binarytree.cpp

 * Author: Lucas Gobaco

 * Date: 17 April 2024

 * Description: This program implements a binary tree and a function that counts the number of nodes with one child in the tree.

 *******************************************************/

#include <algorithm>
#include <iostream>
#include "binarytree.h"

using namespace std;

template <typename T>
Binary_tree<T>::Binary_tree()
{
    root = nullptr;
}

template <typename T>
Binary_tree<T>::Binary_tree(T root_data)
{
    root = new Node<T>;
    root->data = root_data;
    root->left = nullptr;
    root->right = nullptr;
}

template <typename T>
Binary_tree<T>::Binary_tree(T root_data, Binary_tree left, Binary_tree right)
{
    root = new Node<T>;
    root->data = root_data;
    root->left = left.root;
    root->right = right.root;
}

template <typename T>
int height(const Node<T>* n)
{
    if (n == nullptr)
    {
        return 0;
    }
    else
    {
        return 1 + max(height(n->left), height(n->right));
    }
}

template <typename T>
int Binary_tree<T>::height() const
{
    return height(root);
}

template <typename T>
bool Binary_tree<T>::empty() const
{
    return root == nullptr;
}

template <typename T>
T Binary_tree<T>::data() const
{
    return root->data;
}

template <typename T>
Binary_tree<T> Binary_tree<T>::left() const
{
    Binary_tree result;
    result.root = root->left;
    return result;
}

template <typename T>
Binary_tree<T> Binary_tree<T>::right() const
{
    Binary_tree result;
    result.root = root->right;
    return result;
}

template <typename T>
int Binary_tree<T>::count_nodes_with_one_child (Node<T>* n) const
{
    // TODO
    if (n == nullptr || (n->left == nullptr && n->right == nullptr))
    {
        return 0;
    }
    else if (n->left == nullptr || n->right == nullptr)
    {
        return 1 + count_nodes_with_one_child(n->left) + count_nodes_with_one_child(n->right);
    }
    else
    {
        return count_nodes_with_one_child(n->left) + count_nodes_with_one_child(n->right);
    }
}

template <typename T>
int Binary_tree<T>::count_nodes_with_one_child() const
{
    // TODO
    return count_nodes_with_one_child(root);
}