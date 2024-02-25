#ifndef inbox_hpp
#define inboxhpp

#include <stdio.h>
#include <string>

using namespace std;

class Inbox {

public:

    //constructor
    Inbox(string messages);
    //destructor
    ~Inbox();

    //accessors
    string getMessages() const;

    //mutators
    void setMessages(string messages);

private:
    string messages;
};

#endif