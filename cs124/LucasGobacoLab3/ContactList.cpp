/*******************************************************

 * Program Name: ContactList.cpp

 * Author: Lucas Gobaco

 * Date: 6 April 2024

 * Description: This program implements a contact list with a linked list of contacts.

 *******************************************************/

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
    ++current;
    //current.next();
}

void ContactList::movePrevious() {
    --current;
    //current.previous();
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

bool compareContacts(Contact a, Contact b, string fieldName, string direction) {
    bool result = false;

    string aId = a.getId();
    string bId = b.getId();

    string aValue = aId;
    string bValue = bId;

    if (fieldName.compare("first_name") == 0) {
        aValue = a.getFirstName();
        bValue = b.getFirstName();
    } else if (fieldName.compare("middle_name") == 0) {
        aValue = a.getMiddleName();
        bValue = b.getMiddleName();
    } else if (fieldName.compare("last_name") == 0) {
        aValue = a.getLastName();
        bValue = b.getLastName();
    } else if (fieldName.compare("role") == 0) {
        aValue = a.getRole();
        bValue = b.getRole();
    } else if (fieldName.compare("company_name") == 0) {
        aValue = a.getCompanyName();
        bValue = b.getCompanyName();
    } else if (fieldName.compare("address") == 0) {
        aValue = a.getAddress();
        bValue = b.getAddress();
    } else if (fieldName.compare("city") == 0) {
        aValue = a.getCity();
        bValue = b.getCity();
    } else if (fieldName.compare("county") == 0) {
        aValue = a.getCounty();
        bValue = b.getCounty();
    } else if (fieldName.compare("state") == 0) {
        aValue = a.getState();
        bValue = b.getState();
    } else if (fieldName.compare("zip") == 0) {
        aValue = a.getZip();
        bValue = b.getZip();
    } else if (fieldName.compare("phone1") == 0) {
        aValue = a.getPhone1();
        bValue = b.getPhone1();
    } else if (fieldName.compare("phone") == 0) {
        aValue = a.getPhone2();
        bValue = b.getPhone2();
    } else if (fieldName.compare("email") == 0) {
        aValue = a.getEmail();
        bValue = b.getEmail();
    }

    if (direction.compare("asc") == 0) {
        result = aValue.compare(bValue) >= 0;
    } else if (direction.compare("desc") == 0) {
        result = aValue.compare(bValue) < 0;
    }

    return result;
}

void ContactList::sortBy(string fieldName, string direction) {

    Iterator<Contact> b = begin();

    while (!b.equals(end())) {
        Iterator<Contact> r = Iterator<Contact>(b.getPosition(), b.getContainer());
        Node<Contact> *minContact = b.getPosition();
        while (!r.equals(end())) {
            bool res = compareContacts(minContact->getData(), r.get(), fieldName, direction);
            if (res) {
                minContact = r.getPosition();
            }
            r.next();
        }

        if (b.getPosition() != minContact) {
            Contact c1 = b.getPosition()->getData();
            Contact c2 = minContact->getData();
            b.getPosition()->setData(c2);
            minContact->setData(c1);
        }
        b.next();
    }
}
