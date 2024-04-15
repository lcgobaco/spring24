/*******************************************************

 * Program Name: UserMenu.cpp

 * Author: Lucas Gobaco

 * Date: 14 April 2024

 * Description: This program implements a class that displays a menu for a contact.

 *******************************************************/

#include "ContactMenu.h"
#include "Contact.h"
#include "Utils.h"
#include <fstream>

using namespace std;
void ContactMenu::initContactData() {

    inFile.open(CONTACTS_DATA);

    if (!inFile) {
        std::cerr << "Error: Unable to open the file." << std::endl;
    }

    // Read and print the contents of the file line by line
    std::string line;
    std::getline(inFile, line);

    while (std::getline(inFile, line)) {
        vector<string> tokens = splitStringDoubleQuotes(line, ',');
        int contactId = stoi(tokens[0]);
        if (contactId > maxContactId) {
            maxContactId = contactId;
        }

        Contact contact (tokens[0],
        tokens[1], tokens[2], tokens[3],
        tokens[6], tokens[7], tokens[8], tokens[9], tokens[10],
        tokens[11], tokens[12], tokens[13],
        tokens[4], tokens[5]);
        contactList.push_back(contact);
    }

    // Close the file
    inFile.close();
}

// Function to save contacts from a ContactList to a CSV file
void ContactMenu::doExit() {
    std::ofstream file(CONTACTS_DATA);

    // Check if the file is opened successfully
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << CONTACTS_DATA << " for writing." << std::endl;
        return;
    }

    file << "id,first_name,middle_name,last_name,role,company_name,address,city,county,state,zip,phone1,phone,email";

    // Iterate through the contact list
    for (Iterator<Contact> itr = contactList.begin(); !itr.equals(contactList.end()); itr.next()) {
        Contact contact = itr.get();
        file << contact.getId() << ","
             << contact.getFirstName() << ","
             << contact.getMiddleName() << ","
             << contact.getLastName() << ","
             << contact.getRole() << ","
             << contact.getCompanyName() << ","
             << contact.getAddress() << ","
             << contact.getCity() << ","
             << contact.getCounty() << ","
             << contact.getState() << ","
             << contact.getZip() << ","
             << contact.getPhone1() << ","
             << contact.getPhone2() << ","
             << contact.getEmail() << std::endl;
    }

    // Close the file
    file.close();
}

void printContact(Contact contact) {
    std::cout << "ID: " << contact.getId() << std::endl;
        std::cout << "Name: " << contact.getFirstName() << " " << contact.getMiddleName() << " " << contact.getLastName() << std::endl;
        std::cout << "Role: " << contact.getRole() << std::endl;
        std::cout << "Company: " << contact.getCompanyName() << std::endl;
        std::cout << "Address: " << contact.getAddress() << std::endl;
        std::cout << "City: " << contact.getCity() << std::endl;
        std::cout << "County: " << contact.getCounty() << std::endl;
        std::cout << "State: " << contact.getState() << std::endl;
        std::cout << "ZIP: " << contact.getZip() << std::endl;
        std::cout << "Phone 1: " << contact.getPhone1() << std::endl;
        std::cout << "Phone 2: " << contact.getPhone2() << std::endl;
        std::cout << "Email: " << contact.getEmail() << std::endl;
        std::cout << std::endl;
}
void ContactMenu::doList() {
    contactList.moveFirst();

    Iterator<Contact> current = contactList.getCurrent();
    while (!current.equals(contactList.end())) {
        Contact contact = current.get();
        printContact(contact);
        contactList.moveNext();
        current = contactList.getCurrent();
    }

}

void ContactMenu::doListWithIterator() {
    // Iterate through the contact list
    for (Iterator<Contact> itr = contactList.begin(); !itr.equals(contactList.end()); itr.next())
    {
    //for (int i = 0; i < contactList.size(); i++) {
        Contact contact = itr.get();
        printContact(contact);
        itr.next();
    }
}

void ContactMenu::doAdd() {
    // TODO: Add new contact
}

void ContactMenu::doEdit() {
    // TODO: Edit contact
}

void ContactMenu::doDelete() {
    // TODO: Delete contact
}

void ContactMenu::doView(string id) {

    Contact found = Contact();
    contactList.moveFirst();
    Iterator<Contact> current = contactList.getCurrent();
    while (!current.equals(contactList.end())) {
        Contact contact = current.get();
        if (contact.getId().compare(id) == 0) {
            found = contact;
            break;
        }
        contactList.moveNext();
        current = contactList.getCurrent();
    }
    printContact(found);

}

void ContactMenu::doSortBy(string fieldName) {
    contactList.sortBy(fieldName);
}



ContactMenu::ContactMenu() {
    initContactData();
};

    // Destructor
ContactMenu::~ContactMenu() {
}


