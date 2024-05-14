/*******************************************************

 * Program Name: group.h

 * Author: Lucas Gobaco

 * Date: 22 April 2024

 * Description: This program defines a class that stores a group's ID, section, description, and weight.

 *******************************************************/

#ifndef GROUP_H
#define GROUP_H

#include <iostream>
#include <string>
#include "section.h"
#include "assignment.h"

using namespace std;

class Group {
private:
    int groupId;
    Section* section;
    string description;
    double weight;
    vector<Assignment> assignments;

public:
    Group(int id, Section* section, const string& description, double weight);

    /**
     * Returns the group ID.
     * @return the group ID
    */
    int getGroupId() const;

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
     * Sets the group ID.
     * @param id the group ID
    */
    void setGroupId(int id);

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
