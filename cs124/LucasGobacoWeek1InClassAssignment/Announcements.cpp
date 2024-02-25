#include "Announcements.h"
#include <string>

//constructor
Announcements::Announcements(string announcement) {
    announcement = announcement;
}

//destructor
Announcements::~Announcements() {}

//accessors
string Announcements::getAnnouncement() const {
    return announcement;
}

//mutators
void Announcements::setAnnouncement(string announcement) {
    announcement = announcement;
}