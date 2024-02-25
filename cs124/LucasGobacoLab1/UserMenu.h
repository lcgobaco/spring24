/*******************************************************

 * Program Name: User
enu.h

     * Author: Lucas Gobaco

     * Date: 24 February 2024

     * Description: This program defines a class that displays a menu for a user in the console.

 *******************************************************/


#ifndef USERMENU_H
#define USERMENU_H

#include "Menu.h"
#include "User.h"
#include <string>
#include <fstream>
#include <vector>

enum USER_MENU_OPTION
{
    USER_MENU_SIGNIN = '1',
    USER_MENU_SIGNOUT = '2',
    USER_MENU_CREATE = '3',
    USER_MENU_REMOVE = '4',
    USER_MENU_RESET = '5',
    USER_MENU_MANAGE_PROFILE = '6',
    USER_MENU_EXIT = 'x'
};

const string USERS_DATA = "users_data.csv";

class UserMenu : public Menu
    {
        public:
            UserMenu();
            ~UserMenu();
    private:
        // Member variables and any other variables if necessary
        ifstream inFile;
        User user;
        vector<User> users;

    private:
        void initUserData(); // Initialize and read from users_data.csv; and populate the list (vector<User> users;)
    public:
        bool signIn(); // Add a member method LoginMenu::signIn definition and implementation
    public:
        bool create(); // Add a member method create user definition and implementation
    public:
        bool remove(); // Add a member method remove user definition and implementation
    public:
        bool reset(); // Add a member method reset user definition and implementation
    public:
        bool manageProfiles(); // Add a member method to manage user definition and implementation
    public:
        void exit();                     // Enter char 'x' to exit Sign Out and update sign out datetime.
    public:
        bool signOut(); // Save loginDateTime and logoutDateTime data to file users_data.csv
};

    /*
    - Prompt username and password, and authentication
    - Allow 3 retries if the user enters an invalid username and password
    - If the user enters a valid username and password, output a message to indicate successful login or error*/


#endif
