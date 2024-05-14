/*******************************************************

 * Program Name: assignment.cpp

 * Author: Lucas Gobaco

 * Date: 22 April 2024

 * Description: This program implements a class that stores an assignment's ID, group, title, description, and maximum score.

 *******************************************************/

#include "common.h"

Assignment::Assignment(int id, GradeScale* gradeScale, const string& title, const string& description, double maxScore)
    : assignmentId(id), gradeScale(gradeScale), title(title), description(description), maxScore(maxScore) {}

int Assignment::getAssignmentId() const { return assignmentId; }

GradeScale* Assignment::getGradeScale() const { return gradeScale; }

string Assignment::getTitle() const { return title; }

string Assignment::getDescription() const { return description; }

double Assignment::getMaxScore() const { return maxScore; }

void Assignment::setAssignmentId(int id) { assignmentId = id; }

void Assignment::setGradeScale(GradeScale* g) { gradeScale = g; }

void Assignment::setTitle(const string& t) { title = t; }

void Assignment::setDescription(const string& d) { description = d; }

void Assignment::setMaxScore(double m) { maxScore = m; }
