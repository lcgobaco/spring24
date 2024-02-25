#include "Home.h"
#include <string>
#include <iostream>

Home::Home(string modules) {
    modules = modules;
}

//destructor
Home::~Home() {}

//accessors
string Home::getModules() const {
    return modules;
}


//mutators
void Home::setModules(string modules) {
    modules = modules;
}