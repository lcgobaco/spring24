#include "Discussions.h"
#include <string>

//constructor
Discussions::Discussions(string discussion) {
    discussion = discussion;
}

//destructor
Discussions::~Discussions() {}

//accessors
string Discussions::getDiscussion() const {
    return discussion;
}

//mutators
void Discussions::setDiscussion(string discussion) {
    discussion = discussion;
}