#ifndef courses_hpp
#define courseshpp

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Course {

public:

    //constructor
    Course(string name, string instructor);
    //destructor
    ~Course();

    //accessors
    string getName() const;
    string getInstructor() const;

    //mutators
    void setName(string name);
    void setInstructor(string instructor);

private:
    string name;
    string instructor;
};

#endif