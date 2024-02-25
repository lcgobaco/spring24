/*******************************************************

 * Program Name: UserMenu.cpp

 * Author: Lucas Gobaco

 * Date: 24 February 2024

 * Description: This program implements a class that displays a menu for a user.

 *******************************************************/

#include "UserMenu.h"

UserMenu::UserMenu() {
    inFile.open(USERS_DATA);
    this->user = User(0, "", "", DateTime(), DateTime());
    this->users = vector<User>();
};

    // Destructor
    UserMenu::~UserMenu() {
        std::cout << "UserMenu object is being destroyed" << std::endl;
    }
