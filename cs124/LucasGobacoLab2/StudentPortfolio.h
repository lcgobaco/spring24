/*******************************************************

 * Program Name: StudentPortFolio.h

 * Author: Lucas Gobaco

 * Date: 9 March 2024

 * Description: This program defines a class that manages a student's portfolio.

 *******************************************************/

#ifndef STUDENTPORTFOLIO_H
#define STUDENTPORTFOLIO_H

#include <string>
#include <vector>
#include "Course.h"
#include "Menu.h"
#include "ComputerScienceTransferCourses.h"



enum STUDENT_PORTFOLIO_MENU {
    STUDENT_PORTFOLIO_MENU_LIST = '1',
    STUDENT_PORTFOLIO_MENU_VIEW = '2',
    STUDENT_PORTFOLIO_MENU_ADD = '3',
    STUDENT_PORTFOLIO_MENU_EDIT = '4',
    STUDENT_PORTFOLIO_MENU_REMOVE = '5',
    STUDENT_PORTFOLIO_MENU_QUIT = 'x'
};


class StudentPortfolio : public Menu {
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
    StudentPortfolio();
    void activate();
};

#endif // STUDENTPORTFOLIO_H
