#include "Inbox.h"
#include <string>

using namespace std;

Inbox::Inbox(string messages) {
    messages = messages;
}

//destructor
Inbox::~Inbox() {}

//accessors
string Inbox::getMessages() const {
    return messages;
}


//mutators
void Inbox::setMessages(string messages) {
    messages = messages;
}