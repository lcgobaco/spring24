#pragma once
#include "binary_search_tree.h"
#include "assignment.h"
class AssignmentBST : public BinarySearchTree<Assignment*> {
public:
    AssignmentBST();
    ~AssignmentBST();
};