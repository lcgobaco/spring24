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
    *file << assignment << endl;

    // Traverse the right subtree
    save_node(file, node->getRight());
}

void AssignmentBST::list() {
    //TODO:
    print();
}

void getValues(BSTNode<Assignment>* node, vector<Assignment>* values);

vector<Assignment>* AssignmentBST::values() {
    vector<Assignment>* values = new vector<Assignment>();
    getValues(getRoot(), values);
    return values;
}

void getValues(BSTNode<Assignment>* node, vector<Assignment>* values) {
    if (node == nullptr) {
        return;
    }

    // Traverse the left subtree
    getValues(node->getLeft(), values);

    values->push_back(node->getData());

    // Traverse the Right subtree
    getValues(node->getRight(), values);

}

void AssignmentBST::print()
{
    int max_index = 0;
    map<int, BSTNode<Assignment>*> index_map;

    // Creating index_map
    cout << "In tree form: " << endl;
    print_tree(getRoot(), &index_map, 0, &max_index);

    // Printing the tree
    double previous_depth = 0;
    for (int i = 0; i <= index_map.size(); i++) {

        double current_depth = floor(log2(i+1));
        if (current_depth != previous_depth) {
            cout << "\n";
            previous_depth = current_depth;
        }
        if (index_map.find(i) != index_map.end()) {
            cout << index_map[i]->getData().getAssignmentId() << " ";
        } else {
            cout << "null ";
        }
    }
    cout << "\n";

    cout << "In order traversal: " << endl;
    print_node(getRoot());

    cout << "\n";

}


