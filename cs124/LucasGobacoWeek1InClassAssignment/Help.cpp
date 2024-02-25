#include "Help.h"
#include <string>
#include <iostream>

using namespace std;

Help::Help(string requests) {
    requests = requests;
}

//destructor
Help::~Help() {}

//accessors
string Help::getRequests() const {
    return requests;
}


//mutators
void Help::setRequests(string requests) {
    requests = requests;
}