/*******************************************************

 * Program Name: ContactList.h

 * Author: Lucas Gobaco

 * Date: 6 April 2024

 * Description: This program defines a contact list with a linked list of contacts.

 *******************************************************/

#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include "LinkedList.h"
#include "Contact.h"

class ContactList : public LinkedList<Contact> {
public:
    /**
     * Constructs a contact list with no contacts.
    */
    ContactList();

    /**
     * Destructs a contact list.
    */
    ~ContactList();

    /**
     * Uses selection sort to sort the contacts in this list by a field name and direction.
     * @param direction the direction to sort in, either "ascending" or "descending"
    */
    void sortBy(bool direction);

    /**
     * Prints out contactList
    */
    void print();

    /**
     * Searches for a contact by an ID.
     * @param id the ID to search for
     * @return an iterator to the contact with the given ID
    */
    Iterator<Contact> search(string id);

    /**
     * Moves the current contact to the first contact in the list.
    */
    void moveFirst();

    /**
     * Moves the current contact to the last contact in the list.
    */
    void moveLast();

    /**
     * Moves the current contact to the next contact in the list.
    */
    void moveNext();

    /**
     * Moves the current contact to the previous contact in the list.
    */
    void movePrevious();

    /**
     * Returns the current contact.
     * @return an iterator to the current contact
    */
    Iterator<Contact> getCurrent();

private:
    Iterator<Contact> current;
};

#endif