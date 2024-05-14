/*******************************************************

 * Program Name: section.cpp

 * Author: Lucas Gobaco

 * Date: 22 April 2024

 * Description: This program implements a class that stores a section's ID, term, course name, and faculty members.

 *******************************************************/

#include "common.h"

Section::Section(string id, const string& term, const string& courseName, int units, Faculty* faculty)
    : sectionId(id), term(term), courseName(courseName), units(units), faculty(faculty) {}

string Section::getSectionId() const { return sectionId; }

string Section::getTerm() const { return term; }

string Section::getCourseName() const { return courseName; }

int Section::getUnits() const { return units; }

Faculty* Section::getFaculty() const { return faculty; }

vector<GradeScale*> Section::getGradeScales() const { return gradeScales; }

void Section::setSectionId(int id) { sectionId = id; }

void Section::setTerm(const string& t) { term = t; }

void Section::setCourseName(const string& c) { courseName = c; }

void Section::setUnits(int u) { units = u; }

void Section::setFaculty(Faculty* f) { faculty = f; }

void Section::setGradeScales(vector<GradeScale*> g) { gradeScales = g; }

void Section::addGradeScale(GradeScale* g) { gradeScales.push_back(g); }
