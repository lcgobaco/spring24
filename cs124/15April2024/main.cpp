/*******************************************************

 * Program Name: main.cpp

 * Author: Lucas Gobaco

 * Date: 10 April 2024

 * Description: This program implements a program that creates a tree with nodes and children.

 *******************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Node {
private:
    /**
       Computes the size of the subtree whose root is this node.
       @return the number of nodes in the subtree
    */
    int size() const;

    /**
       Counts the number of leave in the subtree anchored at this node
       @return the number of leaves in the subtree
    */
    int number_of_leaves() const;
    string data;
    vector<Node*> children;
    friend class Tree;
};

/*
   A tree in which each node has an arbitrary number of children.
*/
class Tree
{
public:
    /**
       Constructs an empty tree.
    */
    Tree();

    /**
       Constructs a tree with one node and no children.
       @param root_data the data for the root
    */
    Tree(string root_data);

    /**
       Adds a subtree as the last child of the root.
    */
    void add_subtree(const Tree& subtree);

    /**
       Computes the size of this tree.
       @return the number of nodes in the tree
    */
    int size() const;

    /**
       Computes the number of leaves in the tree
       @return the number of leaves in the tree
    */
    int number_of_leaves() const;

private:
    Node* root;
};

Tree::Tree()
{
    root = nullptr;
}

Tree::Tree(string root_data)
{
    root = new Node;
    root->data = root_data;
}

void Tree::add_subtree(const Tree& subtree)
{
    root->children.push_back(subtree.root);
}

/**
   Computes the size of this tree.
   @return the number of nodes in the tree
*/
int Tree::size() const
{
    int count = -1;
    count = root->size();
    return count;
}

/**
   Computes the size of the subtree whose root is this node.
   @return the number of nodes in the subtree
*/
int Node::size() const
{
    int sum = 0;
    if (data != "")
    {
        sum = 1;
        for (Node* child : children)
            sum = sum + child->size();
    }
    return sum;
}

int Node::number_of_leaves() const
{
    int sum = 0;
    if (data != "")
    {
        if (children.size() == 0)
            return 1;
        for (Node* child : children)
            sum = sum + child->number_of_leaves();
    }
    return sum;
}

int Tree::number_of_leaves() const
{
    int count = -1;
    count = root->number_of_leaves();
    return count;
}

int main()
{
    Tree t1("Anne");
    Tree t2("Peter");
    t1.add_subtree(t2);
    Tree t3("Zara");
    t1.add_subtree(t3);
    Tree t4("Savannah");
    t2.add_subtree(t4);
    cout << "Number of nodes:  " << t1.size() << endl;
    cout << "Number of leaves: " << t1.number_of_leaves() << endl;
    return 0;
}