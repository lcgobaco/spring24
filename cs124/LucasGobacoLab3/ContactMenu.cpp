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

    file << "id,first_name,middle_name,last_name,role,company_name,address,city,county,state,zip,phone1,phone,email" << std::endl;

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
        std::cout << "First Name: " << contact.getFirstName() << std::endl;
        std::cout << "Middle Name: " << contact.getMiddleName() << std::endl;
        std::cout << "Last Name: "  << contact.getLastName() << std::endl;
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
    contact.setId(std::to_string(++maxContactId));
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
};

    // Destructor
ContactMenu::~ContactMenu() {
}


