#ifndef home_hpp
#define homehpp

#include <stdio.h>
#include <string>

using namespace std;

class Home {

public:

    //constructor
    Home(string modules);
    //destructor
    ~Home();

    //accessors
    string getModules() const;

    //mutators
    void setModules(string modules);

private:
    string modules;
};


#endif /* home_hpp */