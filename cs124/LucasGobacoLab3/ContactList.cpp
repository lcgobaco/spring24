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

    Iterator<Contact> b = begin();

    while (!b.equals(end())) {
        Iterator<Contact> r = Iterator<Contact>(b.getPosition(),b.getContainer());
        string minFirstName = r.get().getFirstName();
        Iterator<Contact> minContact = r;
        //find min
        while (!r.equals(end())) {
            string a = r.get().getFirstName();
            if (a.compare(minFirstName) < 0) {
                minContact = r;
                minFirstName = a;
            }
            r.next();
        }
        //swap two iterator values
        Contact c1 = b.getPosition()->getData();
        Contact c2 = minContact.getPosition()->getData();
        b.getPosition()->setData(c2);
        minContact.getPosition()->setData(c1);
        b.next();
    }

}


