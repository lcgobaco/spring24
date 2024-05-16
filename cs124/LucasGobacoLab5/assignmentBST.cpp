#include "assignmentBST.h"
#include <string>

AssignmentBST::AssignmentBST()
: BinarySearchTree() {}

AssignmentBST::~AssignmentBST() {}

void AssignmentBST::insert(Assignment* assignment) {
    BinarySearchTree::insert(assignment);
    size_++;
}

void AssignmentBST::erase(Assignment* assignment) {
    BinarySearchTree::erase(assignment);
    size_--;
}

int AssignmentBST::size() {
    return size_;
}

Assignment* AssignmentBST::findById(string id)
{
    cout << "AssignmentBST::findById " << id << endl;
    Assignment* a = new Assignment(id, nullptr, "", "", "", 0, 0);
    return find(a);
    // BSTNode<Assignment*>* current = getRoot();
    // while (current != nullptr)
    // {
    //     int x = stoi(id);
    //     int y = stoi(current->getData()->getAssignmentId());
    //    //cout << id << " " << current->getData()->getAssignmentId() << " " << cmp << endl;
    //     if (x < y)
    //     {
    //         current = current->getLeft();
    //     }
    //     else if (x > y)
    //     {
    //         current = current->getRight();
    //     }
    //     else
    //     {
    //         return current->getData();
    //     }
    // }
    // return nullptr;
}
