/*******************************************************

 * Program Name: group.cpp

 * Author: Lucas Gobaco

 * Date: 22 April 2024

 * Description: This program implements a class that stores a group's ID, section, description, and weight.

 *******************************************************/

#include "group.h"

Group::Group(int id, Section* section, const string& description, double weight)
    : groupId(id), section(section), description(description), weight(weight) {}

int Group::getGroupId() const { return groupId; }

Section* Group::getSection() const { return section; }

string Group::getDescription() const { return description; }

double Group::getWeight() const { return weight; }

vector<Assignment> Group::getAssignments() const { return assignments; }

void Group::setGroupId(int id) { groupId = id; }

void Group::setSection(Section* s) { section = s; }

void Group::setDescription(const string& d) { description = d; }

void Group::setWeight(double w) { weight = w; }

void Group::setAssignments(vector<Assignment> a) { assignments = a; }
