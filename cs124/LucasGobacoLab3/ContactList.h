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

    void sortBy();
    Contact search();
    void moveFirst();
    void moveLast();
    void moveNext();
    void movePrevious();

    private:
    Iterator<Contact> current;

};

#endif // CONTACTLIST_H
