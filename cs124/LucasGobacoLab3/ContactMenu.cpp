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

/**
 * This function initializes the contact data from contacts_data.csv
*/
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


/**
 * Constructor for ContactMenu.   Initializes the contact data.
*/
ContactMenu::ContactMenu() {
    initContactData();
}

ContactMenu::~ContactMenu() {}

void ContactMenu::activate() {
    char input;
    ContactMenu contact_menu;

    add_option("List of contacts");
    add_option("View a contact");
    add_option("Add new contact");
    add_option("Edit contact");
    add_option("Delete contact");
    //add_option("Exit");

    do
    {
        input = get_input();

        cout << "Option: " << input << endl;
        switch (input)
        {
            case CONTACT_MENU_LIST:
            {
                doList();
                break;
            }

            case CONTACT_MENU_VIEW:
            {

                doView();
                break;
            }

            case CONTACT_MENU_ADD:
            {
                doAdd();
                break;
            }

            case CONTACT_MENU_EDIT:
            {
                doEdit();
                break;
            }

            case CONTACT_MENU_DELETE: {
                doDelete();
                break;
            }

            case CONTACT_MENU_EXIT: {
                doExit();
                cout << "Quit" << endl;
                break;
            }
        }

    } while (input != 'x' );
}


/**
 * This function displays the UI for exiting the program.
*/
void ContactMenu::doExit() {
    ofstream file(CONTACTS_DATA);

    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << CONTACTS_DATA << " for writing." << endl;
        return;
    }

    file << "id,first_name,middle_name,last_name,role,company_name,address,city,county,state,zip,phone1,phone,email" << endl;

    for (Iterator<Contact> itr = contactList.begin(); !itr.equals(contactList.end()); itr.next()) {
        Contact contact = itr.get();
        file << contact << endl;
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

/**
 * This function displays the UI for listing the contacts
*/
void ContactMenu::doList() {

    cout << "List of contacts:" << endl;

    /**
    cout << "Sort by:" << endl;

    Menu sort_menu;
    sort_menu.add_option("Sort by ID");
    sort_menu.add_option("Sort by First Name");
    sort_menu.add_option("Sort by Middle Name");
    sort_menu.add_option("Sort by Last Name");
    sort_menu.add_option("Sort by Role");
    sort_menu.add_option("Sort by Company Name");
    sort_menu.add_option("Sort by Address");
    sort_menu.add_option("Sort by City");
    sort_menu.add_option("Sort by County");
    sort_menu.add_option("Sort by State");
    sort_menu.add_option("Sort by Zip");
    sort_menu.add_option("Sort by Phone1");
    sort_menu.add_option("Sort by Phone");
    sort_menu.add_option("Sort by Email");


    int sm = sort_menu.get_input_int();
    string sort_field = "id";
    switch (sm) {
        case 1:
            sort_field = "id";
            break;
        case 2:
            sort_field = "first_name";
            break;
        case 3:
            sort_field = "middle_name";
            break;
        case 4:
            sort_field = "last_name";
            break;
        case 5:
            sort_field = "role";
            break;
        case 6:
            sort_field = "company_name";
            break;
        case 7:
            sort_field = "address";
            break;
        case 8:
            sort_field = "city";
            break;
        case 9:
            sort_field = "county";
            break;
        case 10:
            sort_field = "state";
            break;
        case 11:
            sort_field = "zip";
            break;
        case 12:
            sort_field = "phone1";
            break;
        case 13:
            sort_field = "phone";
            break;
        case 14:
            sort_field = "email";
            break;

    }
    */

    Menu sort_order;
    sort_order.add_option("Ascending");
    sort_order.add_option("Descending");

    int so = sort_order.get_input_int();

    bool asc = so == 1;
    switch(so) {
        case 1:
            doSortBy(asc);
            break;
        case 2:
            doSortBy(asc);
            break;
    }

    contactList.moveFirst();

    contactList.print();

}

/**
 * This function prints out the contacts with an iterator.
*/
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

/**
 * This function displays the UI for editing a contact.
*/
void ContactMenu::doEdit() {
    cout << "Edit Contact:" << endl;
    cout << "Enter Contact ID: ";
    string contact_id;
    cin >> contact_id;
    Iterator<Contact> found = contactList.search(contact_id);

    printContact(found.get());
    cout << "Enter new values" << endl;
    Contact contact = inputContact(found.get());
    //TODO:
    //found.getPosition()->setData(contact);
}

/**
 * This function displays the UI for deleting a contact.
*/
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

/**
 * This function displays the UI for viewing a contact.
*/
void ContactMenu::doView() {
    cout << "View Contact:" << endl;
    cout << "Enter Contact ID: ";
    string contact_id;
    cin >> contact_id;
    Iterator<Contact> found = contactList.search(contact_id);
    printContact(found.get());

}

/**
 * This function sorts the list of contacts.
*/
void ContactMenu::doSortBy(bool direction) {
    contactList.sortBy(direction);
}
