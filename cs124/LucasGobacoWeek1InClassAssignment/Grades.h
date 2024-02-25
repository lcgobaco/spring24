#ifndef grades_hpp
#define grades_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Grades {

public:

    //constructor
    Grades(string grades);
    //destructor
    ~Grades();

    //accessors
    string getGrades() const;

    //mutators
    void setGrades(string grades);

private:
    string grades;
};



#endif /* grades_hpp */