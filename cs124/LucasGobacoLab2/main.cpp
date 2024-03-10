#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Course.h"
#include "ComputerScienceTransferCourses.h"
#include "StudentFortFolio.h"

std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\n\r");
    size_t end = str.find_last_not_of(" \t\n\r");

    if (start == std::string::npos) // No non-whitespace characters found
        return "";

    return str.substr(start, end - start + 1);
}


int main() {


    ComputerScienceTransferCourses courses;
    std::ifstream file("cs_transfer_courses.dat");

    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::string line;

/*
CS 101
Introduction to Computers and Information Technology
This course is a general introduction to the area of computers and information\
technology, and is designed for all students. This survey course examines a broad\
overview of topics including software, hardware, the networking of computer systems,\
information technology, and survey of programming languages. Students explore the\
implications of this technology with regard to today's information society.
ENGL 151B
3*/

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
       //std::getline(file, description);

       //std::string multilineInput;

    // Read lines until a line does not end with backslash
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

    /*
    // Print all courses
    for (int i = 0; i < courses.size(); ++i) {
        std::cout << "Course " << i + 1 << ":\n" << courses.get(i) << "\n";
    }
    */


    /*
    1) List of courses - prompt user for sort preference, default sorting by ascending order, and option to sort by descending order  (see above 5) )
2) View the course details - binary search and view the course details
3) Add a new course - see above 2) for the data format
4) Edit course - binary search and edit course
5) Remove course - binary search and remove course
x) Exit - save data to file cs_transfer_course.dat
*/

    int input;
    StudentFortfolio main_menu(courses);
    main_menu.add_option("List of Courses");
    main_menu.add_option("View the course details");
    main_menu.add_option("Add a new course");
    main_menu.add_option("Edit course");
    main_menu.add_option("Remove course");
    main_menu.add_option("Quit");

    do
    {
        input = main_menu.get_input();

        //cout << "Input == x " << input << " " << (input == "x") << " " << endl;

        if (cin.fail()) {
            cout << "Quit" << endl;
            break;
        }

        //int option = std::stoi(input);

        cout << "Option: " << input << endl;
        switch (input)
        {

            case 1: // List of Courses
            {
                main_menu.showList();

                break;
            }

            case 2:
            {
                main_menu.viewCourse();
                break;
            }

            case 3: // Add a new course
            {
                 main_menu.addCourse();

                break;
            }

            case 4: // Edit course
            {

                main_menu.editCourse();
                break;
            }

            case 5: // Remove course
            {

                main_menu.removeCourse();
                break;
            }


            case 6: // Quit
            {
                cout << "Quit" << endl;
                break;
            }
        }

    } while (input != 6 );


    return 0;
}


