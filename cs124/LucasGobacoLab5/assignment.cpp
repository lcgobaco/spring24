/*******************************************************

 * Program Name: assignment.cpp

 * Author: Lucas Gobaco

 * Date: 22 April 2024

 * Description: This program implements a class that stores an assignment's ID, group, title, description, and maximum score.

 *******************************************************/

#include "assignment.h"

Assignment::Assignment(int id, Group* group, const string& title, const string& description, double maxScore)
    : assignmentId(id), group(group), title(title), description(description), maxScore(maxScore) {}

int Assignment::getAssignmentId() const { return assignmentId; }

Group* Assignment::getGroup() const { return group; }

string Assignment::getTitle() const { return title; }

string Assignment::getDescription() const { return description; }

double Assignment::getMaxScore() const { return maxScore; }

void Assignment::setAssignmentId(int id) { assignmentId = id; }

void Assignment::setGroup(Group* g) { group = g; }

void Assignment::setTitle(const string& t) { title = t; }

void Assignment::setDescription(const string& d) { description = d; }

void Assignment::setMaxScore(double m) { maxScore = m; }