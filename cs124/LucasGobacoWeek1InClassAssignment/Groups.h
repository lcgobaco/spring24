#ifndef groups_hpp
#define groupshpp
#include <string>

using namespace std;

class Groups {

public:

    //constructor
    Groups(string groupName);
    //destructor
    ~Groups();

    //accessors
    string getGroupName() const;

    //mutators
    void setGroupName(string groupName);

private:
    string groupName;
};

#endif