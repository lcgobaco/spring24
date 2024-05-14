/*******************************************************

 * Program Name: group.h

 * Author: Lucas Gobaco

 * Date: 22 April 2024

 * Description: This program defines a class that represents a group in a course.

 *******************************************************/

#ifndef GROUP_H
#define GROUP_H

#include <iostream>
#include <string>
#include "section.h"

using namespace std;

class GradeScale {
private:
    int groupId;
    Section section;
    string description;
    double weight;

public:
    /**
     * Constructs a group with a unique identifier, section, description, and weight percentage.
     * @param id the unique identifier
     * @param sec the section
     * @param desc the description
     * @param w the weight percentage
    */
    GradeScale(int id, const Section& sec, const string& desc, double w);

    /**
     * Returns the unique identifier of this group.
     * @return the unique identifier
    */
    int getGroupId() const;

    /**
     * Returns the section of this group.
     * @return the section
    */
    Section getSection() const;

    /**
     * Returns the description of this group.
     * @return the description
    */
    string getDescription() const;

    /**
     * Returns the weight percentage of this group.
     * @return the weight percentage
    */
    double getWeight() const;

    /**
     * Sets the unique identifier of this group.
     * @param id the unique identifier
    */
    void setGroupId(int id);

    /**
     * Sets the section of this group.
     * @param sec the section
    */
    void setSection(const Section& sec);

    /**
     * Sets the description of this group.
     * @param desc the description
    */
    void setDescription(const string& desc);

    /**
     * Sets the weight percentage of this group.
     * @param w the weight percentage
    */
    void setWeight(double w);

    /**
     * Displays the group's information.
    */
    void display() const;
};

#endif
