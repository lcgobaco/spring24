#include <iostream>
#include <vector>
#include <algorithm>
#include "StudentFortFolio.h"
#include "Course.h"

    void showList(bool ascending = true) {
        // Implement sorting of courses based on ascending or descending order
        if (ascending)
            std::sort(courses.begin(), courses.end());
        else
            std::sort(courses.rbegin(), courses.rend());
        
        // Display the sorted list
        for (const auto& course : courses) {
            // Display course details
        }
    }

    void viewCourse(const std::string& courseName) {
        // Binary search for the course
        auto it = std::find_if(courses.begin(), courses.end(), [&courseName](const Course& c) {
            return c.getName() == courseName;
        });

        if (it != courses.end()) {
            // Display course details
        } else {
            std::cout << "Course not found." << std::endl;
        }
    }

    void addCourse(const Course& newCourse) {
        // Add the new course
        courses.push_back(newCourse);
    }

    void editCourse(const std::string& courseName) {
        // Binary search for the course
        auto it = std::find_if(courses.begin(), courses.end(), [&courseName](const Course& c) {
            return c.getName() == courseName;
        });

        if (it != courses.end()) {
            // Edit course details
        } else {
            std::cout << "Course not found." << std::endl;
        }
    }

    void removeCourse(const std::string& courseName) {
        // Binary search for the course
        auto it = std::find_if(courses.begin(), courses.end(), [&courseName](const Course& c) {
            return c.getName() == courseName;
        });

        if (it != courses.end()) {
            // Remove the course
            courses.erase(it);
        } else {
            std::cout << "Course not found." << std::endl;
        }
    }

    void quit() {
        // Save data to file cs_transfer_course.dat
        // Implement saving logic here
    }
};