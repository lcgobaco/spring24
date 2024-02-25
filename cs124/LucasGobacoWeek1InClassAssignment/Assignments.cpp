#include "Assignments.h"
#include <string>

//constructor
Assignments::Assignments(string assignment) {
    assignment = assignment;
}

//destructor
Assignments::~Assignments() {}

//accessors
string Assignments::getAssignment() const {
    return assignment;
}

//mutators
void Assignments::setAssignment(string assignment) {
    assignment = assignment;
}