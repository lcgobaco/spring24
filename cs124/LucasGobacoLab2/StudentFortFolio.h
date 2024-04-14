/*******************************************************

 * Program Name: StudentFortFolio.h

 * Author: Lucas Gobaco

 * Date: 9 March 2024

 * Description: This program defines a class that manages a student's portfolio.

 *******************************************************/

#ifndef STUDENTFORTFOLIO_H
#define STUDENTFORTFOLIO_H

#include <string>
#include <vector>
#include "Course.h"
#include "Menu.h"
#include "ComputerScienceTransferCourses.h"

class StudentFortfolio : public Menu {
private:
    ComputerScienceTransferCourses courses;

public:
    StudentFortfolio(ComputerScienceTransferCourses courses);
    void showList();
    void viewCourse();
    void addCourse();
    void editCourse();
    void removeCourse();
    void quit();
};

#endif // STUDENTFORTFOLIO_H
