#include "ContactList.h"

ContactList::ContactList() {
    current = begin();
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
    current.next();
}

void ContactList::movePrevious() {
    current.previous();
}

Contact ContactList::search(int id) {
    return Contact();
}

void ContactList::sortBy(string fieldName) {
    moveFirst();
    while (!current.equals(end())) {
        moveNext();
    }
}



