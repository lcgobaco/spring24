/*******************************************************

 * Program Name: Course.cpp

 * Author: Lucas Gobaco

 * Date: 9 March 2024

 * Description: This program defines a class that stores a course's details.

 *******************************************************/

#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>

class Course {
private:
    std::string department;
    int courseNumber;
    std::string title;
    std::string description;
    std::string prerequisite;
    int units;

public:
    // Constructors
    Course();
    Course(std::string dep, int num, std::string tit, std::string desc, std::string prereq, int u);

    // Destructor
    ~Course();

    // Getter and Setter methods for each field
    std::string getDepartment() const;
    void setDepartment(std::string dep);

    int getCourseNumber() const;
    void setCourseNumber(int num);

    std::string getTitle() const;
    void setTitle(std::string tit);

    std::string getDescription() const;
    void setDescription(std::string desc);

    std::string getPrerequisite() const;
    void setPrerequisite(std::string prereq);

    int getUnits() const;
    void setUnits(int u);

    // Overloading << operator for printing Course object
    friend std::ostream& operator<<(std::ostream& os, const Course& course);

    // Overloading == operator for comparing Course objects
    bool operator==(const Course& other) const;
};

#endif // COURSE_H
