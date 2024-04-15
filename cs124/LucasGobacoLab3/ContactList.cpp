#include "ContactList.h"

ContactList::ContactList() {
    current = begin();
}

ContactList::~ContactList() {}

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

