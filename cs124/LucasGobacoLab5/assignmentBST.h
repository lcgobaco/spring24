#pragma once
#include "binary_search_tree.h"
#include "assignment.h"
class AssignmentBST : public BinarySearchTree<Assignment> {
public:
    AssignmentBST();
    ~AssignmentBST();

    void insert(Assignment *assignment);
    void erase(Assignment *assignment);
    int size();
    void save(string fileName);
    void list();
    Assignment findById(string id);
    void save_node(ofstream* f, BSTNode<Assignment>* node);
private:
    int size_ = 0;
};
