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



enum STUDENT_FORTFOLIO_MENU {
    STUDENT_FORTFOLIO_MENU_LIST = '1',
    STUDENT_FORTFOLIO_MENU_VIEW = '2',
    STUDENT_FORTFOLIO_MENU_ADD = '3',
    STUDENT_FORTFOLIO_MENU_EDIT = '4',
    STUDENT_FORTFOLIO_MENU_REMOVE = '5',
    STUDENT_FORTFOLIO_MENU_QUIT = 'x'
};


class StudentFortfolio : public Menu {
private:
    ComputerScienceTransferCourses courses;
    void initData();
    void showList();
    void viewCourse();
    void addCourse();
    void editCourse();
    void removeCourse();
    void quit();

public:
    StudentFortfolio();
    void activate();
};

#endif // STUDENTFORTFOLIO_H
