/*******************************************************

 * Program Name: assignment.cpp

 * Author: Lucas Gobaco

 * Date: 22 April 2024

 * Description: This program implements a class that stores an assignment's ID, group, title, description, and maximum score.

 *******************************************************/

#include "assignment.h"
#include <iostream>

using namespace std;


Assignment::Assignment(string id, GradeScale* gradeScale,
const string& description,
const string& startDate, const string& endDate,
double possiblePoints, double points)
    : assignmentId(id), gradeScale(gradeScale),
    description(description),
    startDate(startDate), endDate(endDate),
    possiblePoints(possiblePoints), points(points) {}

Assignment::Assignment() {
    assignmentId = "";
    gradeScale = nullptr;
    description = "";
    startDate = "";
    endDate = "";
    possiblePoints = 0;
    points = 0;
}

string Assignment::getAssignmentId() const { return assignmentId; }

GradeScale* Assignment::getGradeScale() const { return gradeScale; }

string Assignment::getDescription() const { return description; }

string Assignment::getStartDate() const { return startDate; }

string Assignment::getEndDate() const { return endDate; }

double Assignment::getPossiblePoints() const { return possiblePoints; }

double Assignment::getPoints() const { return points; }

void Assignment::setAssignmentId(string id) { assignmentId = id; }

void Assignment::setGradeScale(GradeScale* g) { gradeScale = g; }

void Assignment::setDescription(const string& d) { description = d; }

void Assignment::setStartDate(const string& s) { startDate = s; }

void Assignment::setEndDate(const string& e) { endDate = e; }

void Assignment::setPossiblePoints(double m) { possiblePoints = m; }

void Assignment::setPoints(double p) { points = p; }

bool Assignment::operator==(const Assignment& c) const {
	return stoi(this->getAssignmentId()) == stoi(c.getAssignmentId());
}

bool Assignment::operator>(const Assignment& c) const {
	return stoi(this->getAssignmentId()) > stoi(c.getAssignmentId());
}

bool Assignment::operator<(const Assignment& c) const {
	return stoi(this->getAssignmentId()) < stoi(c.getAssignmentId());
}

istream& operator>>(istream& in, Assignment& assignment) {
    cout << "Enter the assignment ID: ";
    in >> assignment.assignmentId;
    cout << "Enter the description: ";
    in >> assignment.description;
    cout << "Enter the start date: ";
    in >> assignment.startDate;
    cout << "Enter the end date: ";
    in >> assignment.endDate;
    cout << "Enter the possible points: ";
    in >> assignment.possiblePoints;
    cout << "Enter the points: ";
    in >> assignment.points;
    return in;
}

ostream& operator<<(ostream& out, Assignment& assignment) {

    // out << "Assignment ID: " << assignment.assignmentId << endl;
    // out << "Description: " << assignment.description << endl;
    // out << "Start Date: " << assignment.startDate << endl;
    // out << "End Date: " << assignment.endDate << endl;
    // out << "Possible Points: " << assignment.possiblePoints << endl;
    // out << "Points: " << assignment.points << endl;

    out << assignment.assignmentId << ",";
    out << assignment.description << ",";
    out << assignment.startDate << ",";
    out << assignment.endDate << ",";
    out << assignment.possiblePoints << ",";
    out << assignment.points << ",";
    return out;
}
