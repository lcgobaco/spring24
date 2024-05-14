/*******************************************************

 * Program Name: StudentPortfolio.h

 * Author: Lucas Gobaco

 * Date: 9 March 2024

 * Description: This program implements a class that manages a student's portfolio.

 *******************************************************/

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "StudentPortfolio.h"
#include "ComputerScienceTransferCourses.h"
#include "Course.h"

StudentPortfolio::StudentPortfolio() {
    initData();
}

std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\n\r");
    size_t end = str.find_last_not_of(" \t\n\r");

    if (start == std::string::npos) // No non-whitespace characters found
        return "";

    return str.substr(start, end - start + 1);
}
void StudentPortfolio::initData() {

    std::ifstream file("cs_transfer_courses.dat");

    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) continue; // Skip empty lines

        // i.e. CS 101

        std::string department;
        int courseNumber;
        std::istringstream xx(line);

        xx >> department >> courseNumber;

        std::string title;
        std::getline(file, title);
        size_t end = title.find_last_not_of("\r");

        if (end != std::string::npos) {
            title.substr(0, end + 1);
        }

        std::string input;
        std::string description;
        while (true) {
            std::getline(file, input);

            // Check if the line ends with a backslash
            if (!input.empty() && trim(input).back() == '\\') {
                // Remove the backslash at the end and append the input
                description += input.substr(0, input.size() - 1) + "\n";
            } else {
                // Append the input as it is (no backslash at the end)
                description += input;
                break; // Exit the loop since line does not end with backslash
            }
        }


        std::string prerequisite;
        std::getline(file, prerequisite);

        int units;
        std::getline(file, line);
        std::istringstream(line) >> units;

        Course course(department, courseNumber, title, description, prerequisite, units);
        courses.add(course);
    }

    file.close();
    courses.sort(true);
}
void StudentPortfolio::showList() {
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

void StudentPortfolio::viewCourse() {
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

void StudentPortfolio::addCourse() {

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

void StudentPortfolio::editCourse() {

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

void StudentPortfolio::removeCourse() {
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

void StudentPortfolio::exit() {

     ofstream file(STUDENT_PORTFOLIO_FILENAME);
        cerr << "Error: Unable to open file " << STUDENT_PORTFOLIO_FILENAME << " for writing." << endl;
        return;

    for (int i = 0; i < courses.size(); ++i) {
        file << courses.get(i) << endl;
    }

    file.close();
}

void StudentPortfolio::activate() {

    char input;
    add_option("List of Courses");
    add_option("View the course details");
    add_option("Add a new course");
    add_option("Edit course");
    add_option("Remove course");
    //add_option("Exit");

    do
    {
        input = get_input();

        if (cin.fail()) {
            cout << "Exit" << endl;
            break;
        }

        cout << "Option: " << input << endl;
        switch (input)
        {

            case STUDENT_PORTFOLIO_MENU_LIST: // List of Courses
            {
                showList();
                break;
            }

            case STUDENT_PORTFOLIO_MENU_VIEW:
            {
                viewCourse();
                break;
            }

            case STUDENT_PORTFOLIO_MENU_ADD: // Add a new course
            {
                 addCourse();
                break;
            }

            case STUDENT_PORTFOLIO_MENU_EDIT: // Edit course
            {

                editCourse();
                break;
            }

            case STUDENT_PORTFOLIO_MENU_REMOVE: // Remove course
            {

                removeCourse();
                break;
            }


            case STUDENT_PORTFOLIO_MENU_EXIT: // Quit
            {
                exit();
                cout << "Exit" << endl;
                break;
            }
        }

    } while (input != STUDENT_PORTFOLIO_MENU_EXIT);
}
