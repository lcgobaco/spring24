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
    std::getline(inFile, line);

    while (std::getline(inFile, line)) {
        vector<string> tokens = splitString(line, ',');
        int userId = stoi(tokens[0]);
        if (userId > maxUserId) {
            maxUserId = userId;
        }
        User user (userId, tokens[1], tokens[2], tokens[3], DateTime(tokens[4]), DateTime(tokens[5]),
        tokens[6], tokens[7], tokens[8], tokens[9], tokens[10], tokens[11], tokens[12], tokens[13]);
        users.push_back(user);
    }

    // Close the file
    inFile.close();
}

void UserMenu::saveUserData() {
    ofstream outFile;
    outFile.open(USERS_DATA);

    if (!outFile) {
        std::cerr << "Error: Unable to open the file." << std::endl;
    }

    outFile << "Id,Role,Username,Password,Sign-in datetime,Sign out datetime,First Name,Last Name,Address,City,State,Zip,Phone,Email" << endl;

    for (int i = 0; i < users.size(); i++) {
        outFile << users[i].getUserId()
        << "," << users[i].getRole() << "," << users[i].getUsername() << "," << users[i].getPassword()
        << "," << users[i].getLoginDateTime().toString() << "," << users[i].getLogoutDateTime().toString()
        << "," << users[i].getFirstName() << "," << users[i].getLastName() << "," << users[i].getAddress()
        << "," << users[i].getCity() << "," << users[i].getState() << "," << users[i].getZip()
        << "," << users[i].getPhone() << "," << users[i].getEmail()
        << endl;
    }

    outFile.close();
}


UserMenu::UserMenu() {
    initUserData();
};

    // Destructor
UserMenu::~UserMenu() {
}

bool UserMenu::signIn(string username, string password) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getUsername() == username && users[i].getPassword() == password) {
            user = users[i];
            users[i].setLoginDateTime(DateTime(std::chrono::system_clock::now()));
            cout << "User " << user.getUsername() << " signed in." << endl;
            saveUserData();
            return true;
        }
    }
    return false;
}

bool UserMenu::signOut() {
    if (user.getUserId() == 0) {
        cout << "No user signed in." << endl;
        return false;
    }

    cout << "Signing out " << user.getUsername() << "..." << endl;

    for (int i = 0; i < users.size(); i++) {
        if (users[i].getUsername() == user.getUsername()) {
            users[i].setLogoutDateTime(DateTime(std::chrono::system_clock::now()));
            saveUserData();
            cout << "User " << user.getUsername() << " signed out." << endl;
            return true;
        }
    }
    return false;
}

bool UserMenu::resetPassword(string oldPassword, string newPassword) {
    if (user.getUserId() == 0) {
        cout << "No user signed in." << endl;
        return false;
    }

    for (int i = 0; i < users.size(); i++) {
        if (users[i].getUsername() == user.getUsername()) {
            if (users[i].getPassword() == oldPassword) {
                users[i].setPassword(newPassword);
                saveUserData();
                cout << "User " << user.getUsername() << " password reset." << endl;
                return true;
            }
            cout << "Incorrect password." << endl;
            return false;
        }
    }

    return true;
}

bool UserMenu::createAccount(string firstName, string lastName, string phone, string email, string password) {

    if (user.getRole() != "admin") {
        cout << "Only admins can create accounts." << endl;
        return false;
    }
    maxUserId++;
    User newUser(maxUserId, "student", email, password, DateTime(std::chrono::system_clock::now()), DateTime(std::chrono::system_clock::now()),
    firstName, lastName, "", "", "", "", phone, email);
    users.push_back(newUser);
    saveUserData();
    return true;
}

bool UserMenu::isSignedIn() {
    if (user.getUserId() == 0) {
        return false;
    }
    return true;
}
