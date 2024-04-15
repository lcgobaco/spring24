/*******************************************************

 * Program Name: UserMenu.h

* Author: Lucas Gobaco

* Date: 14 April 2024

* Description: This program defines a class that displays a menu for a contact in the console.

 *******************************************************/


#ifndef USERMENU_H
#define USERMENU_H

#include "Menu.h"
#include "Contact.h"
#include <string>
#include "ContactList.h"
#include <fstream>
#include <vector>

enum CONTACT_MENU_OPTION
{
    CONTACT_MENU_SIGNIN = '1',
    CONTACT_MENU_SIGNOUT = '2',
    CONTACT_MENU_CREATE = '3',
    CONTACT_MENU_REMOVE = '4',
    CONTACT_MENU_RESET = '5',
    CONTACT_MENU_MANAGE_PROFILE = '6',
    CONTACT_MENU_EXIT = 'x'
};

const string CONTACTS_DATA = "contacts_data.csv";

class ContactMenu : public Menu
    {
    public:
        ContactMenu();
        ~ContactMenu();
    private:
        // Member variables and any other variables if necessary
        ifstream inFile;
        Contact contact;
        ContactList contactList;
        int maxContactId = 0;

    private:
        void initContactData(); // Initialize and read from contacts_data.csv; and populate the list (vector<User> users;)
    public:
        void doList();
        void doListWithIterator();
        void doSortBy(string fieldName, string direction);
        void doView(string id);
        void doAdd();
        void doEdit();
        void doDelete();
        void doExit();
};

    /*
    - Prompt username and password, and authentication
    - Allow 3 retries if the user enters an invalid username and password
    - If the user enters a valid username and password, output a message to indicate successful login or error*/


#endif
