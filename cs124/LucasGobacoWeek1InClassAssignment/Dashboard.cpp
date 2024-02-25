#include "Dashboard.h"
#include <string>
#include <vector>

//constructor
Dashboard::Dashboard(string item) {
    item = item;
}

//destructor
Dashboard::~Dashboard() {}

//accessors
string Dashboard::getItem() const {
    return item;
}

//mutators
void Dashboard::setItem(string item) {
    item = item;
}