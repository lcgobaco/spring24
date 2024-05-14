/*******************************************************

 * Program Name: assignment.h

 * Author: Lucas Gobaco

 * Date: 22 April 2024

 * Description: This program defines a class that stores an assignment's ID, group, title, description, and maximum score.

 *******************************************************/

#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <iostream>
#include <string>
#include "gradeScale.h"

using namespace std;

class Assignment {
private:
    int assignmentId;
    GradeScale* group;
    string title;
    string description;
    double maxScore;

public:
    /**
     * Constructs an assignment object with a given ID, gradeScale, title, description, and maximum score.
     * @param id the assignment ID
     * @param gradeScale the grade scale
     * @param title the title
     * @param description the description
     * @param maxScore the maximum score
    */
    Assignment(int id, GradeScale* gradeScale, const string& title, const string& description, double maxScore);

    /**
     * Returns the assignment ID.
     * @return the assignment ID
    */
    int getAssignmentId() const;

    /**
     * Returns the grade scale.
     * @return the grade scale
    */
    GradeScale* getGradeScale() const;

    /**
     * Returns the title.
     * @return the title
    */
    string getTitle() const;

    /**
     * Returns the description.
     * @return the description
    */
    string getDescription() const;

    /**
     * Returns the maximum score.
     * @return the maximum score
    */
    double getMaxScore() const;

    /**
     * Sets the assignment ID.
     * @param id the assignment ID
    */
    void setAssignmentId(int id);

    /**
     * Sets the grade scale.
     * @param g the grade scale
    */
    void setGradeScale(GradeScale* g);

    /**
     * Sets the title.
     * @param t the title
    */
    void setTitle(const string& t);

    /**
     * Sets the description.
     * @param d the description
    */
    void setDescription(const string& d);

    /**
     * Sets the maximum score.
     * @param m the maximum score
    */
    void setMaxScore(double m);
};

#endif
