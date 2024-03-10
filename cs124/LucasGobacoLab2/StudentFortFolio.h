#ifndef STUDENTFORTFOLIO_H
#define STUDENTFORTFOLIO_H

#include <string>
#include <vector>
#include "Course.h"
#include "Menu.h"
#include "ComputerScienceTransferCourses.h"

class StudentFortfolio : public Menu {
private:
    ComputerScienceTransferCourses<Course> courses;

public:
    StudentFortfolio(ComputerScienceTransferCourses<Course> courses);
    void showList(bool ascending = true);
    void viewCourse(const std::string& courseName);
    void addCourse(const Course& newCourse);
    void editCourse(const std::string& courseName);
    void removeCourse(const std::string& courseName);
    void quit();
};

#endif // STUDENTFORTFOLIO_H
