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

// Overloading << operator for printing Course object
std::ostream& operator<<(std::ostream& os, const Course& course) {
    os << "Department: " << course.department << "\n";
    os << "Course Number: " << course.courseNumber << "\n";
    os << "Title: " << course.title << "\n";
    os << "Description: " << course.description << "\n";
    os << "Prerequisite: " << course.prerequisite << "\n";
    os << "Units: " << course.units << "\n";
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
