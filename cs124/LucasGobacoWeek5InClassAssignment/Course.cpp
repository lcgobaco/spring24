/*******************************************************

 * Program Name: Course.cpp

 * Author: Lucas Gobaco

 * Date: 23 February 2024

 * Description: This program implements a class that stores details about a course.

 *******************************************************/

#include "Course.h"

Course::Course() {
    department = "";
    course = 0;
    title = "";
    description = "";
    prereq = "";
    units = 0;
}

Course::Course(string department, int course, string title, string description, string prereq, int units) {
    this->department = department;
    this->course = course;
    this->title = title;
    this->description = description;
    this->prereq = prereq;
    this->units = units;
}

Course& Course::operator=(const Course& course) {
    if (this != &course) {
        department = course.department;
        this->course = course.course;
        title = course.title;
        description = course.description;
        prereq = course.prereq;
        units = course.units;
    }
    return *this;
}

bool Course::operator==(const Course& course) const {
    return (department == course.department && this->course == course.course);
}

bool Course::operator!=(const Course& course) const {
    return (department != course.department || this->course != course.course);
}

bool Course::operator>(const Course& course) const {
    return (department > course.department || (department == course.department && this->course > course.course));
}

bool Course::operator<(const Course& course) const {
    return (department < course.department || (department == course.department && this->course < course.course));
}

bool Course::operator>=(const Course& course) const {
    return (department > course.department || (department == course.department && this->course >= course.course));
}

bool Course::operator<=(const Course& course) const {
    return (department < course.department || (department == course.department && this->course <= course.course));
}

istream& operator>>(istream& in, Course& course) {
    cout << "Enter the department: ";
    in >> course.department;
    cout << "Enter the course number: ";
    in >> course.course;
    cout << "Enter the title: ";
    in.ignore();
    getline(in, course.title);
    cout << "Enter the description: ";
    getline(in, course.description);
    cout << "Enter the prerequisite: ";
    in >> course.prereq;
    cout << "Enter the units: ";
    in >> course.units;
    return in;
}

ostream& operator<<(ostream& out, Course& course) {
    out << "Department: " << course.department << endl;
    out << "Course: " << course.course << endl;
    out << "Title: " << course.title << endl;
    out << "Description: " << course.description << endl;
    out << "Prerequisite: " << course.prereq << endl;
    out << "Units: " << course.units << endl;
    return out;
}