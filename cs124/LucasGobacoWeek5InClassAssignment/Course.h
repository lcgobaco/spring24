/*******************************************************

 * Program Name: Course.h

 * Author: Lucas Gobaco

 * Date: 23 February 2024

 * Description: This program defines a class that stores details about a course.

 *******************************************************/

#ifndef COURSE_H
#define COURSE_H

#include <iostream>

using namespace std;

class Course {
    friend istream& operator>>(istream& in, Course&);
    friend ostream& operator<<(ostream& out, Course&);

public:
    Course();
    Course(string department, int course, string title, string description, string prereq, int units);
// The assignment operator
    Course& operator=(const Course&);
// Logical operators 
    bool operator==(const Course&) const;
    bool operator!=(const Course&) const;
    bool operator>(const Course&) const;
    bool operator<(const Course&) const;
    bool operator>=(const Course&) const;
    bool operator<=(const Course&) const;
private:
// Define these member variable - See your Lab 2
/*
-Department - contains the department(ex.CS)
- Course - contain the course number(ex. 101)
- Title - contains the course description
- Description - contains multiple lines of description.The ending backslash "\" is a special character that indicates the continuation of the next line.
- Prerequisite - contains string value like ENGL 151B
- Units - contains integer value in units
*/
    string department;
    int course;
    string title;
    string description;
    string prereq;
    int units;
};

#endif