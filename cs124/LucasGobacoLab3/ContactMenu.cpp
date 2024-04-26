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
        cerr << "Error: Unable to open the file." << endl;
    }

    string line;
    getline(inFile, line);

    while (getline(inFile, line)) {
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

    inFile.close();
}

void ContactMenu::doExit() {
    ofstream file(CONTACTS_DATA);

    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << CONTACTS_DATA << " for writing." << endl;
        return;
    }

    file << "id,first_name,middle_name,last_name,role,company_name,address,city,county,state,zip,phone1,phone,email" << endl;

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
             << contact.getEmail() << endl;
    }

    file.close();
}

/**
 * Prints a contact.
 * @param contact the contact to print
*/
void printContact(Contact contact) {
    cout << "ID: " << contact.getId() << endl;
        cout << "First Name: " << contact.getFirstName() << endl;
        cout << "Middle Name: " << contact.getMiddleName() << endl;
        cout << "Last Name: "  << contact.getLastName() << endl;
        cout << "Role: " << contact.getRole() << endl;
        cout << "Company: " << contact.getCompanyName() << endl;
        cout << "Address: " << contact.getAddress() << endl;
        cout << "City: " << contact.getCity() << endl;
        cout << "County: " << contact.getCounty() << endl;
        cout << "State: " << contact.getState() << endl;
        cout << "ZIP: " << contact.getZip() << endl;
        cout << "Phone 1: " << contact.getPhone1() << endl;
        cout << "Phone 2: " << contact.getPhone2() << endl;
        cout << "Email: " << contact.getEmail() << endl;
        cout << endl;
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
    for (Iterator<Contact> itr = contactList.begin(); !itr.equals(contactList.end()); itr.next())
    {
    //for (int i = 0; i < contactList.size(); i++) {
        Contact contact = itr.get();
        printContact(contact);
        itr.next();
    }
}

/**
 * Prompts the user to input a contact.
 * @param contact the contact to input
 * @return the contact
*/
Contact inputContact(Contact contact) {
    cout << "Adding new contact" << endl;
    cout << "First name: ";
    string firstName;
    cin >> firstName;
    contact.setFirstName(firstName);

    cout << "Middle name: ";
    string middleName;
    cin >> middleName;
    contact.setMiddleName(middleName);

    cout << "Last name: ";
    string lastName;
    cin >> lastName;
    contact.setLastName(lastName);

    cout << "Role: ";
    string role;
    cin >> role;
    contact.setRole(role);

    cout << "Company name: ";
    string companyName;
    cin >> companyName;
    contact.setCompanyName(companyName);

    cout << "Address: ";
    string address;
    cin >> address;
    contact.setAddress(address);

    cout << "City: ";
    string city;
    cin >> city;
    contact.setCity(city);

    cout << "County: ";
    string county;
    cin >> county;
    contact.setCounty(county);

    cout << "State: ";
    string state;
    cin >> state;
    contact.setState(state);

    cout << "ZIP: ";
    string zip;
    cin >> zip;
    contact.setZip(zip);

    cout << "Phone 1: ";
    string phone1;
    cin >> phone1;
    contact.setPhone1(phone1);

    cout << "Phone 2: ";
    string phone2;
    cin >> phone2;
    contact.setPhone2(phone2);

    cout << "Email: ";
    string email;
    cin >> email;
    contact.setEmail(email);

    return contact;
}

void ContactMenu::doAdd() {
    Contact contact = Contact();
    contact.setId(to_string(++maxContactId));
    contact = inputContact(contact);

    cout << "Adding new contact" << endl;
    contactList.insert(contactList.end(), contact);
    cout << "Contact added" << endl;

    printContact(contact);
}

void ContactMenu::doEdit() {
    cout << "Edit Contact:" << endl;
    cout << "Enter Contact ID: ";
    string contact_id;
    cin >> contact_id;
    Iterator<Contact> found = contactList.search(contact_id);

    printContact(found.get());
    cout << "Enter new values" << endl;
    Contact contact = inputContact(found.get());
    found.getPosition()->setData(contact);
}

void ContactMenu::doDelete() {
    cout << "Delete Contact:" << endl;
    cout << "Enter Contact ID: ";
    string contact_id;
    cin >> contact_id;
    Iterator<Contact> found = contactList.search(contact_id);
    printContact(found.get());
    contactList.erase(found);
    cout << "Contact deleted" << endl;
}

void ContactMenu::doView() {
    cout << "View Contact:" << endl;
    cout << "Enter Contact ID: ";
    string contact_id;
    cin >> contact_id;
    Iterator<Contact> found = contactList.search(contact_id);
    printContact(found.get());

}

void ContactMenu::doSortBy(string fieldName, string direction) {
    contactList.sortBy(fieldName, direction);
}

ContactMenu::ContactMenu() {
    initContactData();
}

ContactMenu::~ContactMenu() {}