#ifndef announcements_hpp
#define announcementshpp
#include <string>

using namespace std;

class Announcements {

public:

    //constructor
    Announcements(string announcement);
    //destructor
    ~Announcements();

    //accessors
    string getAnnouncement() const;

    //mutators
    void setAnnouncement(string announcement);

private:
    string announcement;
};

#endif