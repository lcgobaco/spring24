/*******************************************************

 * Program Name: group.cpp

 * Author: Lucas Gobaco

 * Date: 22 April 2024

 * Description: This program implements a class that stores a group's ID, section, description, and weight.

 *******************************************************/

#include "common.h"

GradeScale::GradeScale(int id, Section* section, const string& description, double weight)
    : gradeScaleId(id), section(section), description(description), weight(weight) {}

int GradeScale::getGradeScaleId() const { return gradeScaleId; }

Section* GradeScale::getSection() const { return section; }

string GradeScale::getDescription() const { return description; }

vector<Assignment*> GradeScale::getAssignments() const { return assignments; }

double GradeScale::getWeight() const { return weight; }

void GradeScale::setGradeScaleId(int id) { gradeScaleId = id; }

void GradeScale::setSection(Section* s) { section = s; }

void GradeScale::setDescription(const string& d) { description = d; }

void GradeScale::setWeight(double w) { weight = w; }

void GradeScale::setAssignments(vector<Assignment*> a) { assignments = a; }

void GradeScale::addAssignment(Assignment* a) { assignments.push_back(a); }
