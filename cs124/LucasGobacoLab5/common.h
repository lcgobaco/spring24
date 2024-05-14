/*******************************************************

 * Program Name: faculty.h

 * Author: Lucas Gobaco

 * Date: 22 April 2024

 * Description: This program defines a class that stores a faculty member's first name, last name, department, address, city, state, zip code, email, and phone number.

 *******************************************************/

#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Assignment;
class GradeScale;
class Section;

class Faculty {
private:
    string facultyId;
    string firstName;
    string lastName;
    string department;
    string address;
    string city;
    string state;
    string zip;
    string email;
    string phone;

    vector<Section*> sections;

public:
    /**
     * Constructs a faculty object with a given ID, first name, last name, department, address, city, state, zip code, email, and phone number.
     * @param id the faculty ID
     * @param fName the faculty member's first name
     * @param lName the faculty member's last name
     * @param dept the faculty member's department
     * @param addr the faculty member's address
     * @param city the faculty member's city
     * @param state the faculty member's state
     * @param zip the faculty member's zip code
     * @param email the faculty member's email
     * @param phone the faculty member's phone number
    */
    Faculty(string id, const string& fName, const string& lName, const string& dept, const string& addr,
    const string& city, const string& state, const string& zip, const string& email, const string& phone);

    /**
     * Returns the faculty ID.
     * @return the faculty ID
    */
    string getFacultyId() const;

    /**
     * Returns the faculty member's first name.
     * @return the faculty member's first name
    */
    string getFirstName() const;

    /**
     * Returns the faculty member's last name.
     * @return the faculty member's last name
    */
    string getLastName() const;

    /**
     * Returns the faculty member's department.
     * @return the faculty member's department
    */
    string getDepartment() const;

    /**
     * Returns the faculty member's address.
     * @return the faculty member's address
    */
    string getAddress() const;

    /**
     * Returns the faculty member's city.
     * @return the faculty member's city
    */
    string getCity() const;

    /**
     * Returns the faculty member's state.
     * @return the faculty member's state
    */
    string getState() const;

    /**
     * Returns the faculty member's zip code.
     * @return the faculty member's zip code
    */
    string getZip() const;

    /**
     * Returns the faculty member's email.
     * @return the faculty member's email
    */
    string getEmail() const;

    /**
     * Returns the faculty member's phone number.
     * @return the faculty member's phone number
    */
    string getPhone() const;

    /**
     * Returns the sections.
     * @return the sections
    */
    vector<Section*> getSections() const;

    /**
     * Sets the faculty ID.
     * @param id the faculty ID
    */
    void setFacultyId(string id);

    /**
     * Sets the faculty member's first name.
     * @param fName the faculty member's first name
    */
    void setFirstName(const string& fName);

    /**
     * Sets the faculty member's last name.
     * @param lName the faculty member's last name
    */
    void setLastName(const string& lName);

    /**
     * Sets the faculty member's department.
     * @param dept the faculty member's department
    */
    void setDepartment(const string& dept);

    /**
     * Sets the faculty member's address.
     * @param addr the faculty member's address
    */
    void setAddress(const string& addr);

    /**
     * Sets the faculty member's city.
     * @param city the faculty member's city
    */
    void setCity(const string& city);

    /**
     * Sets the faculty member's state.
     * @param state the faculty member's state
    */
    void setState(const string& state);

    /**
     * Sets the faculty member's zip code.
     * @param zip the faculty member's zip code
    */
    void setZip(const string& zip);

    /**
     * Sets the faculty member's email.
     * @param email the faculty member's email
    */
    void setEmail(const string& email);

    /**
     * Sets the faculty member's phone number.
     * @param phone the faculty member's phone number
    */
    void setPhone(const string& phone);

    /**
     * Sets the sections.
     * @param sections the sections
    */
    void setSections(vector<Section*> sections);

    /**
     * Adds a section.
     * @param section the section
    */
    void addSection(Section* section);

};

class Section {
private:
    string sectionId;
    string term;
    string courseName;
    int units;
    Faculty* faculty;
    vector<GradeScale*> gradeScales;

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
     * Returns the faculty member.
     * @return the faculty member
    */
    Faculty* getFaculty() const;

    /**
     * Returns the grade scales.
     * @return the grade scales
    */
    vector<GradeScale*> getGradeScales() const;

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
     * Sets the grade scales.
     * @param gs the grade scales
     */
    void setGradeScales(vector<GradeScale*> gs);

    /**
     * Adds a grade scale.
     * @param gs the grade scale
    */
    void addGradeScale(GradeScale* gs);

};

class GradeScale {
private:
    int gradeScaleId;
    Section* section;
    string description;
    double weight;
    vector<Assignment*> assignments;

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
     * Returns the assignments.
     * @return the assignments
    */
    vector<Assignment*> getAssignments() const;

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
     * Returns the assignments.
     * @return the assignments
    */
    void setAssignments(vector<Assignment*> a);

    /**
     * Adds an assignment.
     * @param a the assignment
    */
    void addAssignment(Assignment* a);

};

class Assignment {
private:
    int assignmentId;
    GradeScale* gradeScale;
    string description;
    string startDate;
    string endDate;
    double possiblePoints;
    double points;

public:
    /**
     * Constructs an assignment object with a given ID, gradeScale, description, and maximum score.
     * @param id the assignment ID
     * @param gradeScale the grade scale
     * @param description the description
     * @param startDate the start date
     * @param endDate the end date
     * @param possiblePoints the possible points
     * @param points the points
    */
    Assignment(int id, GradeScale* gradeScale, const string& description,
    const string& startDate, const string& endDate,
    double possiblePoints, double points);

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
     * Returns the start date.
     * @return the start date
    */
    string getStartDate() const;

    /**
     * Returns the end date.
     * @return the end date
     */
    string getEndDate() const;

    /**
     * Returns the possible points
     * @return the possible points
    */
    double getPossiblePoints() const;

    /**
     * Returns the points.
     * @return the points
     * */
    double getPoints() const;

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
     * Sets the description.
     * @param d the description
    */
    void setDescription(const string& d);

    /**
     * Sets the start date.
     * @param s the start date
     * */
    void setStartDate(const string& s);

    /**
     *  Sets the end date.
     * @param e the end date
     * */
    void setEndDate(const string& e);

    /**
     * Sets the maximum score.
     * @param m the maximum score
    */
    void setPossiblePoints(double m);

    /**
     * Sets the points.
     * @param p the points
     * */
    void setPoints(double p);
};


#endif
