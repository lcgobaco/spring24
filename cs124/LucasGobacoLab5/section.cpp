/*******************************************************

 * Program Name: section.cpp

 * Author: Lucas Gobaco

 * Date: 22 April 2024

 * Description: This program implements a class that stores a section's ID, term, course name, and faculty members.

 *******************************************************/

#include "section.h"

Section::Section(string id, const string& term, const string& courseName, int units, Faculty* faculty)
    : sectionId(id), term(term), courseName(courseName), units(units), faculty(faculty) {}

Section::Section() {};

string Section::getSectionId() const { return sectionId; }

string Section::getTerm() const { return term; }

string Section::getCourseName() const { return courseName; }

string Section::getName() const { return courseName; }

int Section::getUnits() const { return units; }

Faculty* Section::getFaculty() const { return faculty; }

vector<GradeScale*> Section::getGradeScales() const { return gradeScales; }

void Section::setSectionId(string id) { sectionId = id; }

void Section::setTerm(const string& t) { term = t; }

void Section::setCourseName(const string& c) { courseName = c; }

void Section::setUnits(int u) { units = u; }

void Section::setFaculty(Faculty* f) { faculty = f; }

void Section::setGradeScales(vector<GradeScale*> g) { gradeScales = g; }

void Section::addGradeScale(GradeScale* g) { gradeScales.push_back(g); }

istream& operator>>(istream& in, Section& course) {
    //TODO:
    // cout << "Enter the department: ";
    // in >> course.department;
    // cout << "Enter the course number: ";
    // in >> course.course;
    // cout << "Enter the title: ";
    // in.ignore();
    // getline(in, course.title);
    // cout << "Enter the description: ";
    // getline(in, course.description);
    // cout << "Enter the prerequisite: ";
    // in >> course.prereq;
    // cout << "Enter the units: ";
    // in >> course.units;
    return in;
}

ostream& operator<<(ostream& out, Section& course) {
    //TODO:
    // out << "Department: " << course.department << endl;
    // out << "Course: " << course.course << endl;
    // out << "Title: " << course.title << endl;
    // out << "Description: " << course.description << endl;
    // out << "Prerequisite: " << course.prereq << endl;
    // out << "Units: " << course.units << endl;
    return out;
}
