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

    void sortBy(string fieldName, string direction);
    Iterator<Contact> search(string id);
    void moveFirst();
    void moveLast();
    void moveNext();
    void movePrevious();
    Iterator<Contact> getCurrent();

    private:
    Iterator<Contact> current;

};

#endif // CONTACTLIST_H
