/*******************************************************

 * Program Name: group.cpp

 * Author: Lucas Gobaco

 * Date: 22 April 2024

 * Description: This program implements a class that represents a group in a course.

 *******************************************************/

#include "group.h"

using namespace std;

GradeScale::GradeScale(int id, const Section& sec, const string& desc, double w)
    : groupId(id), section(sec), description(desc), weight(w) {}

int GradeScale::getGroupId() const {
    return groupId;
}

Section GradeScale::getSection() const {
    return section;
}

string GradeScale::getDescription() const {
    return description;
}

double GradeScale::getWeight() const {
    return weight;
}

void GradeScale::setGroupId(int id) {
    groupId = id;
}

void GradeScale::setSection(const Section& sec) {
    section = sec;
}

void GradeScale::setDescription(const string& desc) {
    description = desc;
}

void GradeScale::setWeight(double w) {
    weight = w;
}

void GradeScale::display() const {
    cout << "Group ID: " << groupId << endl;
    cout << "Section: " << section << endl;
    cout << "Description: " << description << endl;
    cout << "Weight: " << weight << endl;
}
