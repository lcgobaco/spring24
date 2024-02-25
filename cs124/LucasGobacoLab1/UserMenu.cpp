/*******************************************************

 * Program Name: UserMenu.cpp

 * Author: Lucas Gobaco

 * Date: 24 February 2024

 * Description: This program implements a class that displays a menu for a user.

 *******************************************************/

#include "UserMenu.h"
#include "Utils.h"

using namespace std;

void UserMenu::initUserData() {

    inFile.open(USERS_DATA);

    if (!inFile) {
        std::cerr << "Error: Unable to open the file." << std::endl;
    }

    // Read and print the contents of the file line by line
    std::string line;
    while (std::getline(inFile, line)) {
        cout << line << endl;
        vector<string> tokens = splitString(line, ',');
        User user (std::stoi(tokens[0]), tokens[1], tokens[2], DateTime(tokens[3]), DateTime(tokens[4]));
        users.push_back(user);
    }

    // Close the file
    inFile.close();
}


UserMenu::UserMenu() {
    initUserData();
};

    // Destructor
UserMenu::~UserMenu() {
    std::cout << "UserMenu object is being destroyed" << std::endl;
}

/*
UserMenu::signIn() {
    return true;
}
*/
