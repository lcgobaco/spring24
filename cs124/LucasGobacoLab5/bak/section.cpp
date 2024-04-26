#include <iostream>
#include <string>
#include "user.h"

class Section {
private:
    std::string term;
    std::string sectionId;
    std::string courseName;
    int units;
    User user;
    
public:
    // Constructor
    Section(const std::string& t, const std::string& sec, const std::string& name, int u, int id)
        : term(t), sectionId(sec), courseName(name), units(u), userId(id) {}

    // Getters
    std::string getTerm() const {
        return term;
    }

    std::string getSection() const {
        return sectionId;
    }

    std::string getCourseName() const {
        return courseName;
    }

    int getUnits() const {
        return units;
    }

    int getUserId() const {
        return userId;
    }

    // Setters
    void setTerm(const std::string& t) {
        term = t;
    }

    void setSection(const std::string& sec) {
        sectionId = sec;
    }

    void setCourseName(const std::string& name) {
        courseName = name;
    }

    void setUnits(int u) {
        units = u;
    }

    void setUserId(int id) {
        userId = id;
    }

    // Display function
    void display() const {
        std::cout << "Term: " << term << std::endl;
        std::cout << "Section: " << sectionId << std::endl;
        std::cout << "Course Name: " << courseName << std::endl;
        std::cout << "Units: " << units << std::endl;
        std::cout << "User ID: " << userId << std::endl;
    }
};

int main2() {
    // Creating an instance of the Section class
    Section section1("Spring 2024", "A", "Introduction to Programming", 3, 12345);

    // Displaying information about the section
    section1.display();

    return 0;
}
