/*******************************************************

 * Program Name: assignment.cpp

 * Author: Lucas Gobaco

 * Date: 22 April 2024

 * Description: This program implements a class that stores an assignment's ID, group, title, description, and maximum score.

 *******************************************************/

#include "common.h"

Assignment::Assignment(int id, GradeScale* gradeScale, const string& title, const string& description, double possiblePoints, double points)
    : assignmentId(id), gradeScale(gradeScale), title(title), description(description), possiblePoints(possiblePoints), points(points) {}

int Assignment::getAssignmentId() const { return assignmentId; }

GradeScale* Assignment::getGradeScale() const { return gradeScale; }

string Assignment::getTitle() const { return title; }

string Assignment::getDescription() const { return description; }

double Assignment::getPossiblePoints() const { return possiblePoints; }

double Assignment::getPoints() const { return points; }

void Assignment::setAssignmentId(int id) { assignmentId = id; }

void Assignment::setGradeScale(GradeScale* g) { gradeScale = g; }

void Assignment::setTitle(const string& t) { title = t; }

void Assignment::setDescription(const string& d) { description = d; }

void Assignment::setPossiblePoints(double m) { possiblePoints = m; }

void Assignment::setPoints(double p) { points = p; }
