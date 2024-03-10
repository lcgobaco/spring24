#ifndef STUDENTFORTFOLIO_H
#define STUDENTFORTFOLIO_H

#include <string>
#include <vector>
#include "Course.h"
#include "Menu.h"

class StudentFortfolio : public Menu {
private:
    std::vector<Course> courses;

public:
    void showList(bool ascending = true);
    void viewCourse(const std::string& courseName);
    void addCourse(const Course& newCourse);
    void editCourse(const std::string& courseName);
    void removeCourse(const std::string& courseName);
    void quit();
};

#endif // STUDENTFORTFOLIO_H
