#ifndef dashboard_hpp
#define dashboardhpp

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Dashboard {

public:

    //constructor
    Dashboard (string item);
    //destructor
    ~Dashboard();

    //accessors
    string getItem() const;

    //mutators
    void setItem(string item);

private:
    string item;
};

#endif