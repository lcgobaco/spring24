#ifndef assignments_hpp
#define assignmentshpp
#include <string>

using namespace std;

class Assignments {

public:

    //constructor
    Assignments(string assignments);
    //destructor
    ~Assignments();

    //accessors
    string getAssignment() const;

    //mutators
    void setAssignment(string assignment);

private:
    string assignment;
};

#endif