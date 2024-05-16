#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <string>

using namespace std;
class GradeScale;

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

    bool operator==(const Assignment&);
};

#endif // ASSIGNMENT_H
