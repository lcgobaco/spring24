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
    Assignment findById(string id);
private:
    int size_ = 0;
};
