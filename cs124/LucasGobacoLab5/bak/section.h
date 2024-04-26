#ifndef SECTION_H
#define SECTION_H

#include <iostream>
#include <string>
#include "user.h"

using namespace std;

class Section {
private:
    string term;
    string sectionId;
    string courseName;
    int units;
    User userId;

public:
    /**
     * Constructs a section with a term, section, course name, units, and user ID.
     * @param t the term
     * @param sec the section
     * @param name the course name
     * @param u the units
     * @param id the user ID
    */
    Section(const string& t, const string& sec, const string& name, int u, const UserID& id);

    /**
     * Returns the term of this section.
     * @return the term
    */
    string getTerm() const;

    /**
     * Returns the section of this section.
     * @return the section
    */
    string getSection() const;
    UserID getCourseName() const;
    int getUnits() const;
    UserID getUserId() const;

    // Setters
    void setTerm(const string& t);
    void setSection(const string& sec);
    void setCourseName(const string& name);
    void setUnits(int u);
    void setUserId(const UserID& id);

    // Display function
    void display() const;
};

#endif
