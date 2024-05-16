/*******************************************************

 * Program Name: assignment.cpp

 * Author: Lucas Gobaco

 * Date: 22 April 2024

 * Description: This program implements a class that stores an assignment's ID, group, title, description, and maximum score.

 *******************************************************/

#include "assignment.h"

Assignment::Assignment(string id, GradeScale* gradeScale,
const string& description,
const string& startDate, const string& endDate,
double possiblePoints, double points)
    : assignmentId(id), gradeScale(gradeScale),
    description(description),
    startDate(startDate), endDate(endDate),
    possiblePoints(possiblePoints), points(points) {}

string Assignment::getAssignmentId() const { return assignmentId; }

GradeScale* Assignment::getGradeScale() const { return gradeScale; }

string Assignment::getDescription() const { return description; }

double Assignment::getPossiblePoints() const { return possiblePoints; }

double Assignment::getPoints() const { return points; }

void Assignment::setAssignmentId(string id) { assignmentId = id; }

void Assignment::setGradeScale(GradeScale* g) { gradeScale = g; }

void Assignment::setDescription(const string& d) { description = d; }

void Assignment::setPossiblePoints(double m) { possiblePoints = m; }

void Assignment::setPoints(double p) { points = p; }

bool Assignment::operator==(const Assignment& c) {
	return this->getAssignmentId() == c.getAssignmentId();
}
