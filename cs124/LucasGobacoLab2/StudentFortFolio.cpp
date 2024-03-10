#include <iostream>
#include <vector>
#include "StudentFortFolio.h"
#include "ComputerScienceTransferCourses.h"
#include "Course.h"

StudentFortfolio::StudentFortfolio(ComputerScienceTransferCourses<Course> courses) {
    // Load data from file cs_transfer_course.dat
    // Implement loading logic here
    this->courses = courses;
}

void StudentFortfolio::showList(bool ascending) {
    // Sort the courses
    if (ascending) {
        courses.sort();
    }

    // Print the courses
    for (int i = 0; i < courses.size(); ++i) {
        std::cout << "Course " << i + 1 << ":\n" << courses.get(i) << "\n";
    }

}

void StudentFortfolio::viewCourse(const std::string& courseName) {
}

void StudentFortfolio::addCourse(const Course& newCourse) {
}

void StudentFortfolio::editCourse(const std::string& courseName) {
}

void StudentFortfolio::removeCourse(const std::string& courseName) {

}

void StudentFortfolio::quit() {
    // Save data to file cs_transfer_course.dat
    // Implement saving logic here
}