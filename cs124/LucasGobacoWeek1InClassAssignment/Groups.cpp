#include "Groups.h"
#include <string>

//constructor
Groups::Groups(string groupName) {
    groupName = groupName;
}

//destructor
Groups::~Groups() {}

//accessors
string Groups::getGroupName() const {
    return groupName;
}

//mutators
void Groups::setGroupName(string name) {
    groupName = groupName;
}