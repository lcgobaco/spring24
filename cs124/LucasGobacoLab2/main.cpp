#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Course.h"
#include "ArrayList.h"
#include "ComputerScienceTransferCourses.h"

int main() {
    ArrayList<Course> courses;
    std::ifstream file("sample_data.txt");

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
        courses.add(course);
    }

    file.close();

    // Print all courses
    for (int i = 0; i < courses.size(); ++i) {
        std::cout << "Course " << i + 1 << ":\n" << courses.get(i) << "\n";
    }

    return 0;
}
