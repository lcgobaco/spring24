/*******************************************************

 * Program Name: Course.cpp

 * Author: Lucas Gobaco

 * Date: 9 March 2024

 * Description: This program implements a class that stores a course's details.

 *******************************************************/

#include "Course.h"

// Constructors
Course::Course() {}
Course::Course(std::string dep, int num, std::string tit, std::string desc, std::string prereq, int u)
    : department(dep), courseNumber(num), title(tit), description(desc), prerequisite(prereq), units(u) {}

// Destructor
Course::~Course() {}

// Getter and Setter methods for each field
std::string Course::getDepartment() const { return department; }
void Course::setDepartment(std::string dep) { department = dep; }

int Course::getCourseNumber() const { return courseNumber; }
void Course::setCourseNumber(int num) { courseNumber = num; }

std::string Course::getTitle() const { return title; }
void Course::setTitle(std::string tit) { title = tit; }

std::string Course::getDescription() const { return description; }
void Course::setDescription(std::string desc) { description = desc; }

std::string Course::getPrerequisite() const { return prerequisite; }
void Course::setPrerequisite(std::string prereq) { prerequisite = prereq; }

int Course::getUnits() const { return units; }
void Course::setUnits(int u) { units = u; }

/*
CS 101
Introduction to Computers and Information Technology
This course is a general introduction to the area of computers and information\
technology, and is designed for all students. This survey course examines a broad\
overview of topics including software, hardware, the networking of computer systems,\
information technology, and survey of programming languages. Students explore the\
implications of this technology with regard to today's information society.
ENGL 151B
3
*/
// Overloading << operator for printing Course object
std::ostream& operator<<(std::ostream& os, const Course& course) {
    os << course.department << " " << course.courseNumber << "\n";
    os << course.title << "\n";
    os << course.description << "\n";
    os << course.prerequisite << "\n";
    os << course.units << "\n";
    return os;
}

// Overloading == operator for comparing Course objects
bool Course::operator==(const Course& other) const {
    return (department == other.department &&
            courseNumber == other.courseNumber &&
            title == other.title &&
            description == other.description &&
            prerequisite == other.prerequisite &&
            units == other.units);
}
