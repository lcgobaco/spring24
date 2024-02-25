#ifndef help_hpp
#define helphpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Help {

public:

    //constructor
    Help(string requests);
    //destructor
    ~Help();

    //accessors
    string getRequests() const;

    //mutators
    void setRequests(string requests);

private:
    string requests;
};


#endif /* help_hpp */