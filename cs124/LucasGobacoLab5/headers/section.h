/*******************************************************

 * Program Name: section.h

 * Author: Lucas Gobaco

 * Date: 22 April 2024

 * Description: This program defines a class that stores a section's ID, term, course name, and faculty members.

 *******************************************************/

#ifndef SECTION_H
#define SECTION_H

#include <iostream>
#include <string>
#include <vector>
#include "faculty.h"

using namespace std;

class GradeScale;

class Section {
private:
    string sectionId;
    string term;
    string courseName;
    int units;
    Faculty* faculty;
    vector<GradeScale> gradeScales;

public:
    /**
     * Constructs a section object with a given ID, term, course name, and faculty member.
     * @param id the section ID
     * @param term the term
     * @param courseName the course name
     * @param faculty the faculty member
    */
    Section(string id, const string& term, const string& courseName, int units, Faculty* faculty);

    /**
     * Returns the section ID.
     * @return the section ID
    */
    string getSectionId() const;

    /**
     * Returns the term.
     * @return the term
    */
    string getTerm() const;

    /**
     * Returns the course name.
     * @return the course name
    */
    string getCourseName() const;

    /**
     * Returns the number of units.
     * @return the number of units
    */
    int getUnits() const;

    /**
     * Returns the groups.
     * @return the groups
    */
    vector<GradeScale> getGroups() const;

    /**
     * Returns the faculty member.
     * @return the faculty member
    */
    Faculty* getFaculty() const;

    /**
     * Sets the section ID.
     * @param id the section ID
    */
    void setSectionId(int id);

    /**
     * Sets the term.
     * @param t the term
    */
    void setTerm(const string& t);

    /**
     * Sets the course name.
     * @param c the course name
    */
    void setCourseName(const string& c);

    /**
     * Sets the number of units.
     * @param u the number of units
    */
    void setUnits(const int u);

    /**
     * Sets the faculty member.
     * @param f the faculty member
    */
    void setFaculty(Faculty* f);

    /**
     * Sets the groups.
     * @param g the groups
     */
    void setGradeScales(vector<GradeScale> g);

};

#endif
