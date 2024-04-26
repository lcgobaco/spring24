/*******************************************************

 * Program Name: group.cpp

 * Author: Lucas Gobaco

 * Date: 22 April 2024

 * Description: This program implements a class that represents a group in a course.

 *******************************************************/

#include "group.h"

using namespace std;

Group::Group(int id, const Section& sec, const string& desc, double w)
    : groupId(id), section(sec), description(desc), weight(w) {}

int Group::getGroupId() const {
    return groupId;
}

Section Group::getSection() const {
    return section;
}

string Group::getDescription() const {
    return description;
}

double Group::getWeight() const {
    return weight;
}

void Group::setGroupId(int id) {
    groupId = id;
}

void Group::setSection(const Section& sec) {
    section = sec;
}

void Group::setDescription(const string& desc) {
    description = desc;
}

void Group::setWeight(double w) {
    weight = w;
}

void Group::display() const {
    cout << "Group ID: " << groupId << endl;
    cout << "Section: " << section << endl;
    cout << "Description: " << description << endl;
    cout << "Weight: " << weight << endl;
}