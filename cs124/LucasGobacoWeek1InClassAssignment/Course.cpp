#include "Course.h"
#include <string>
#include <vector>

//constructor
Course::Course(string name, string instructor) {
    name = name;
    instructor = instructor;
}

//destructor
Course::~Course() {}

//accessors
string Course::getName() const {
    return name;
}

string Course::getInstructor() const {
    return instructor;
}

//mutators
void Course::setName(string name) {
    name = name;
}

void Course::setInstructor(string instructor) {
    instructor = instructor;
}