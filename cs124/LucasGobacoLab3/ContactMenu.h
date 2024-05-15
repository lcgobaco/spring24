/*******************************************************

 * Program Name: ContactMenu.h

 * Author: Lucas Gobaco

 * Date: 6 April 2024

 * Description: This program defines a contact menu with options to sign in, sign out, create, remove, reset, manage profile, and exit.

 *******************************************************/

#ifndef CONTACTMENU_H
#define CONTACTMENU_H

#include "Menu.h"
#include "Contact.h"
#include <string>
#include "ContactList.h"
#include <fstream>
#include <vector>

enum CONTACT_MENU_OPTION
{
    CONTACT_MENU_LIST = '1',
    CONTACT_MENU_VIEW = '2',
    CONTACT_MENU_ADD = '3',
    CONTACT_MENU_EDIT = '4',
    CONTACT_MENU_DELETE = '5',
    CONTACT_MENU_EXIT = 'x'
};

const string CONTACTS_DATA = "contacts_data.csv";

class ContactMenu : public Menu
    {
    public:
        /**
         * Constructs a contact menu with options to sign in, sign out, create, remove, reset, manage profile, and exit.
        */
        ContactMenu();

        /**
         * Destructs a contact menu.
        */
        ~ContactMenu();

    private:
        ifstream inFile;
        Contact contact;
        ContactList contactList;
        int maxContactId = 0;

    private:
        /**
         * Initializes the contact data by reading from contacts_data.csv and populating the list.
        */
        void initContactData();

        /**
         * Displays the contact menu.
        */
        void doList();

        /**
         * Displays the contact menu with an iterator.
        */
        void doListWithIterator();

        /**
         * Uses selection sort to sort the contacts in this list by a field name and direction.
        */
        void doSortBy(bool direction);

        /**
         * Selects a contact from the list and shows the contact details.
        */
        void doView();

        /**
         * Adds a new contact to the list.
        */
        void doAdd();

        /**
         * Edits an existing contact in the list.
        */
        void doEdit();

        /**
         * Deletes an existing contact from the list.
        */
        void doDelete();

        /**
         * Exits the contact menu.
        */
        void doExit();

    public:

        void activate();
};

#endif
