/*******************************************************

 * Program Name: group.h

 * Author: Lucas Gobaco

 * Date: 22 April 2024

 * Description: This program defines a class that stores a group's ID, section, description, and weight.

 *******************************************************/

#ifndef GRADESCALE_H
#define GRADESCALE_H

#include <iostream>
#include <string>
#include "section.h"
#include "assignment.h"

using namespace std;

class GradeScale {
private:
    int groupId;
    Section* section;
    string description;
    double weight;
    vector<Assignment> assignments;

public:
    GradeScale(int id, Section* section, const string& description, double weight);

    /**
     * Returns the grade scale ID.
     * @return the grade scale ID
    */
    int getGradeScaleId() const;

    /**
     * Returns the section.
     * @return the section
    */
    Section* getSection() const;

    /**
     * Returns the description.
     * @return the description
    */
    string getDescription() const;

    /**
     * Returns the weight.
     * @return the weight
    */
    double getWeight() const;

    /**
     * Returns the vector of assignments.
     * @return the vector of assignments
     */
    vector<Assignment> getAssignments() const;

    /**
     * Sets the grade scale ID.
     * @param id the grade scale ID
    */
    void setGradeScaleId(int id);

    /**
     * Sets the section.
     * @param s the section
    */
    void setSection(Section* s);

    /**
     * Sets the description.
     * @param d the description
    */
    void setDescription(const string& d);

    /**
     * Sets the weight.
     * @param w the weight
    */
    void setWeight(double w);

    /**
     * Sets the vector of assignments.
     * @param a the vector of assignments
     * */
    void setAssignments(vector<Assignment> a);
};

#endif
