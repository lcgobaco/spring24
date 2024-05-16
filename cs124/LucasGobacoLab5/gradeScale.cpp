/*******************************************************

 * Program Name: group.cpp

 * Author: Lucas Gobaco

 * Date: 22 April 2024

 * Description: This program implements a class that stores a group's ID, section, description, and weight.

 *******************************************************/

#include <iostream>
#include "gradeScale.h"

GradeScale::GradeScale(string id, Section* section, const string& description, double weight)
    : gradeScaleId(id), section(section), description(description), weight(weight) {}

GradeScale::GradeScale() {};

string GradeScale::getGradeScaleId() const { return gradeScaleId; }

string GradeScale::getName() const { return gradeScaleId; }

Section* GradeScale::getSection() const { return section; }

string GradeScale::getDescription() const { return description; }

vector<Assignment*> GradeScale::getAssignments() const { return assignments; }

double GradeScale::getWeight() const { return weight; }

void GradeScale::setGradeScaleId(string id) { gradeScaleId = id; }

void GradeScale::setSection(Section* s) { section = s; }

void GradeScale::setDescription(const string& d) { description = d; }

void GradeScale::setWeight(double w) { weight = w; }

void GradeScale::setAssignments(vector<Assignment*> a) { assignments = a; }

void GradeScale::addAssignment(Assignment* a) { assignments.push_back(a); }

istream& operator>>(istream& in, GradeScale& course) {
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

ostream& operator<<(ostream& out, GradeScale& gradeScale) {
    out << "Grade Scale ID: " << gradeScale.getGradeScaleId() << endl;
    out << "Description: " << gradeScale.getDescription() << endl;
    out << "Weight: " << gradeScale.getWeight() << endl;
    out << "Section ID: " << gradeScale.getSection()->getSectionId() << endl;
    return out;
}

bool GradeScale::operator==(const GradeScale& c) {
	return this->getGradeScaleId() == c.getGradeScaleId();
}
