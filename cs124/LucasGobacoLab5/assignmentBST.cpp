#include "assignmentBST.h"
#include <string>
#include <fstream>

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

void AssignmentBST::save(string fileName) {
    ofstream file(fileName);
    if (file.is_open()) {
    file << "Id,GradeScaleId,Description,Start Date,End Date,Possible Points,Points\n";
    save_node(&file, getRoot());
    }

}

void AssignmentBST::save_node(ofstream* file, BSTNode<Assignment>* node)
{
    if (node == nullptr) {
        return;
    }

    // Traverse the left subtree
    save_node(file, node->getLeft());

    // Visit the current node
    Assignment assignment = node->getData();
    *file << assignment.getAssignmentId() << ",";
    *file << assignment.getGradeScale()->getGradeScaleId() << ",";
    *file << assignment.getDescription() << ",";
    *file << assignment.getStartDate() << ",";
    *file << assignment.getEndDate() << ",";
    *file << assignment.getPossiblePoints() << ",";
    *file << assignment.getPoints() << endl;

    // Traverse the right subtree
    save_node(file, node->getRight());
}

void AssignmentBST::list() {
    print_node(getRoot());
}
