#include "assignmentBST.h"
#include <string>

AssignmentBST::AssignmentBST()
: BinarySearchTree() {}

AssignmentBST::~AssignmentBST() {}

void AssignmentBST::insert(Assignment* assignment) {
    BinarySearchTree::insert(*assignment);
    size_++;
}

void AssignmentBST::erase(Assignment* assignment) {
    BinarySearchTree::erase(*assignment);
    size_--;
}

int AssignmentBST::size() {
    return size_;
}

Assignment AssignmentBST::findById(string id)
{
    BSTNode<Assignment>* current = getRoot();
    while (current != nullptr)
    {
        int x = stoi(id);
        int y = stoi(current->getData().getAssignmentId());
        if (x < y)
        {
            current = current->getLeft();
        }
        else if (x > y)
        {
            current = current->getRight();
        }
        else
        {
            return current->getData();
        }
    }
    return Assignment();
}
