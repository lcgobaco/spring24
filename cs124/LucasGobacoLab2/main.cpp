#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Course.h"

int main() {
    std::vector<Course> courses;
    std::ifstream file("cs_transfer_courses.dat");

    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue; // Skip empty lines

        std::string department = line;
        int courseNumber;
        std::getline(file, line);
        std::istringstream(line) >> courseNumber;

        std::string title;
        std::getline(file, title);

        std::string description;
        std::getline(file, description);

        std::string prerequisite;
        std::getline(file, prerequisite);

        int units;
        std::getline(file, line);
        std::istringstream(line) >> units;

        Course course(department, courseNumber, title, description, prerequisite, units);
        courses.push_back(course);
    }

    file.close();

    // Print all courses
    for (const auto& course : courses) {
        std::cout << course << "\n";
    }

    return 0;
}

int main1() {
    // Creating Course objects
    Course course1("CS", 101, "Introduction to Computer Science", "This course introduces the basics of computer science.", "None", 3);
    Course course2("MATH", 201, "Calculus", "This course covers calculus topics such as limits, derivatives, and integrals.", "MATH 101", 4);

    // Printing Course objects
    std::cout << "Course 1:\n" << course1 << "\n";
    std::cout << "Course 2:\n" << course2 << "\n";

    // Testing the equality operator
    if (course1 == course2) {
        std::cout << "Course 1 and Course 2 are the same.\n";
    } else {
        std::cout << "Course 1 and Course 2 are different.\n";
    }

    return 0;
}
