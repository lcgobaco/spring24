/*******************************************************

 * Program Name: ContactList.cpp

 * Author: Lucas Gobaco

 * Date: 6 April 2024

 * Description: This program implements a contact list with a linked list of contacts.

 *******************************************************/

#include "ContactList.h"
#include <vector>

ContactList::ContactList() {
    current = begin();

    vector<Contact> contacts;
    Iterator<Contact> itr = begin();

    int i = 0;
    while (!itr.equals(end())) {
        contacts.push_back(itr.get());
        itr.next();
        i++;
    }
}

ContactList::~ContactList() {}

Iterator<Contact> ContactList::getCurrent() {
    return current;
}

void ContactList::moveFirst() {
    current = begin();
}

void ContactList::moveLast() {
    current = end();
}

void ContactList::moveNext() {
    cout << "ContactList.moveNext" << endl;
    current++;
}

void ContactList::movePrevious() {
    current--;
}

Iterator<Contact> ContactList::search(string id) {
    Iterator<Contact> current = begin();
    while (!current.equals(end())) {
        if (current.get().getId().compare(id) == 0) {
            return current;
            break;
        }
        current.next();
    }
    return Iterator<Contact>(nullptr, this);
}


void ContactList::sortBy(bool direction) {

    this->selectionSort(direction);
    
}

void ContactList::print() {
    Iterator<Contact> current = begin();
    while (!current.equals(end())) {
        cout << current.get() << endl;
        current.next();
    }
}

