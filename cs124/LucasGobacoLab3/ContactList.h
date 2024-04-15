#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include "LinkedList.h"
#include "Contact.h"

class ContactList : public LinkedList<Contact> {
public:
    // Constructor
    ContactList();

    // Destructor
    ~ContactList();

};

#endif // CONTACTLIST_H
