#include "Grades.h"
#include <string>

using namespace std;

//constructor
Grades::Grades(string grades) {
    grades = grades;
}

//destructor
Grades::~Grades() {}

//accessors
string Grades::getGrades() const {
    return grades;
}

//mutators
void Grades::setGrades(string grades) {
    grades = grades;
}