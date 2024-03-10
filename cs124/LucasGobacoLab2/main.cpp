#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Course.h"
#include "ComputerScienceTransferCourses.h"
#include "StudentFortFolio.h"

/*
    ArrayList<Course> courses;
*/
int main() {
    ComputerScienceTransferCourses<Course> courses;
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
        courses.add(course);
    }

    file.close();

    /*
    // Print all courses
    for (int i = 0; i < courses.size(); ++i) {
        std::cout << "Course " << i + 1 << ":\n" << courses.get(i) << "\n";
    }
    */
    string input;

    /*
    1) List of courses - prompt user for sort preference, default sorting by ascending order, and option to sort by descending order  (see above 5) )
2) View the course details - binary search and view the course details
3) Add a new course - see above 2) for the data format
4) Edit course - binary search and edit course
5) Remove course - binary search and remove course
x) Exit - save data to file cs_transfer_course.dat
*/

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

        cout << "Input == x " << input << " " << (input == "x") << " " << endl;

        if (input == "x") {
            cout << "Quit" << endl;
            break;
        }

        int option = std::stoi(input);

        cout << "Option: " << option << endl;
        switch (option)
        {

            case 1: // List of Courses
            {
                int tries = 0;
                while (tries < 3) {
                    cout << "Sign-in" << endl;
                    string username, password;
                    cout << "Enter username: ";
                    cin >> username;
                    cout << "Enter password: ";
                    cin >> password;
                    main_menu.showList(true);

                    tries++;
                }
                break;
            }

            case 2:
            {
                cout << "Sign-out" << endl;
                main_menu.viewCourse("");
                //cout << "Signed out: " << signedOut << endl;
                break;
            }

            case 3: // Add a new course
            {
                main_menu.addCourse(Course("CS", 124, "Data Structures", "Data Structures and Algorithms", "CS 123", 4));
                break;
            }

            case 4: // Edit course
            {
                main_menu.editCourse("Data Structures");
                break;
            }

            case 5: // Remove course
            {
                main_menu.removeCourse("Data Structures");
                break;
            }
      

            case 6: // Quit
            {
                cout << "Quit" << endl;
                break;
            }
        }

    } while (input != "6" );


    return 0;
}
