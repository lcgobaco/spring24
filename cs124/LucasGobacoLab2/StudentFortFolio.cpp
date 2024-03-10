#include <iostream>
#include <vector>
#include "StudentFortFolio.h"
#include "ComputerScienceTransferCourses.h"
#include "Course.h"

StudentFortfolio::StudentFortfolio(ComputerScienceTransferCourses courses) {
    // Load data from file cs_transfer_course.dat
    // Implement loading logic here
    this->courses = courses;
}

void StudentFortfolio::showList() {
    // Sort the courses
    string ascending;
    cout << "Ascending or Descending? (a/d)" << endl;
    cin >> ascending;
    if (ascending == "a") {
        courses.sort(true);
    }
    else {
        courses.sort(false);
    }

    // Print the courses
    for (int i = 0; i < courses.size(); ++i) {
        std::cout << "Course " << i + 1 << ":\n" << courses.get(i) << "\n";
    }

}

void StudentFortfolio::viewCourse() {
    // Search for the course
    string title;
    cout << "Title:";
    cin.ignore();
    std::getline(cin, title);

    int x = courses.search(title);
    if (x >= 0) {
        std::cout << endl << courses.get(x) << endl;
    }
    else {
        std::cout << "Not Found" << endl;
    }
}

void StudentFortfolio::addCourse() {

    string department;
    cout << "Department:" << endl;
    cin >> department;

    int courseNumber;
    cout << "Course Number:" << endl;
    cin >> courseNumber;

    string title;
    cout << "Title:" << endl;
    cin.ignore();
    std::getline(cin, title);
    
    string description;
    cout << "Description:" << endl;
    std::getline(cin, description);

    string prerequisite;
    cout << "Prerequisite:" << endl;
    std::getline(cin, prerequisite);

    int units;
    cout << "Units:" << endl;
    cin >> units;

    Course newCourse = Course(department, courseNumber, title, description, prerequisite, units);
    courses.add(newCourse);
}

void StudentFortfolio::editCourse() {


    string title;
    cout << "Title:";
    cin.ignore();
    std::getline(cin, title);
    int x = courses.search(title);

    
    if (x >= 0) {
        std::cout << "Enter new course details" << std::endl;

        string department;
        cout << "Department:" << endl;
        cin >> department;

        int courseNumber;
        cout << "Course Number:" << endl;
        cin >> courseNumber;

        string title;
        cout << "Title:" << endl;
        cin.ignore();
        std::getline(cin, title);

        string description;
        cout << "Description:" << endl;
        std::getline(cin, description);

        string prerequisite;
        cout << "Prerequisite:" << endl;
        std::getline(cin, prerequisite);

        int units;
        cout << "Units:" << endl;
        cin >> units;

        Course newCourse = Course(department, courseNumber, title, description, prerequisite, units);
        courses.set(x, newCourse);
    }
    else {
        std::cout << "Not Found" << std::endl;
    }
}

void StudentFortfolio::removeCourse() {
    string title;
    cout << "Title:";
    cin.ignore();
    std::getline(cin, title);
    int x = courses.search(title);
    if (x >= 0) {
        courses.remove(x);
    }
    else {
        std::cout << "Not Found" << std::endl;
    }
}

void StudentFortfolio::quit() {
    // Save data to file cs_transfer_course.dat
    // Implement saving logic here
}
