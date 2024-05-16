#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <string>
#include "gradeScale.h"

using namespace std;

class Assignment {
private:
    string assignmentId;
    GradeScale* gradeScale;
    string description;
    string startDate;
    string endDate;
    double possiblePoints;
    double points;

public:
    // Constructor
    Assignment(string id, GradeScale* gradeScale, const string& description,
               const string& startDate, const string& endDate,
               double possiblePoints, double points);

    Assignment();

    // Getter methods
    string getAssignmentId() const;
    GradeScale* getGradeScale() const;
    string getDescription() const;
    string getStartDate() const;
    string getEndDate() const;
    double getPossiblePoints() const;
    double getPoints() const;

    // Setter methods
    void setAssignmentId(string id);
    void setGradeScale(GradeScale* g);
    void setDescription(const string& d);
    void setStartDate(const string& startDate);
    void setEndDate(const string& endDate);
    void setPossiblePoints(double m);
    void setPoints(double p);

    bool operator==(const Assignment&) const;
    bool operator>(const Assignment&) const;
    bool operator<(const Assignment&) const;

    friend istream& operator>>(istream& in, Assignment&);
    friend ostream& operator<<(ostream& out, Assignment&);
};

#endif // ASSIGNMENT_H
