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
        vector<string> tokens = splitString(line, ',');
        int contactId = stoi(tokens[0]);
        if (contactId > maxContactId) {
            maxContactId = contactId;
        }


        /* contacts_data file:
        id,
        first_name,
        middle_name,
        last_name,
        role, 4
        company_name, 5
        address,city,county,state,zip,phone1,phone,email

        */

        /*
            Contact(int id,
            std::string first, std::string middle, std::string last,
            DateTime dob,
            std::string addr, std::string cty, std::string cnty, std::string st, std::string zp,
            std::string ph1, std::string ph2, std::string pro, std::string em,
            std::string role,std::string company_name);
        */
        Contact contact (contactId,
        tokens[1], tokens[2], tokens[3],
        tokens[6], tokens[7], tokens[8], tokens[9], tokens[10],
        tokens[11], tokens[12], "", tokens[13],
        tokens[4], tokens[5]);
        contacts.push_back(contact);
    }

    // Close the file
    inFile.close();
}


// Function to save contacts from a ContactList to a CSV file
void ContactMenu::saveContactsToFile() {
    std::ofstream file(CONTACTS_DATA);

    // Check if the file is opened successfully
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << CONTACTS_DATA << " for writing." << std::endl;
        return;
    }

    file << "id,first_name,middle_name,last_name,role,company_name,address,city,county,state,zip,phone1,phone,email";

    // Iterate through the contact list
for (int i = 0; i < contacts.size(); i++) {
        Contact contact = contacts[i];
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

vector<Contact> ContactMenu::getContacts() {
    return contacts;
}

ContactMenu::ContactMenu() {
    initContactData();
};

    // Destructor
ContactMenu::~ContactMenu() {
}

bool ContactMenu::signIn(string username, string password) {
    /*
    for (int i = 0; i < contacts.size(); i++) {
        if (users[i].getUsername() == username && users[i].getPassword() == password) {
            user = users[i];
            users[i].setLoginDateTime(DateTime(std::chrono::system_clock::now()));
            cout << "User " << user.getUsername() << " signed in." << endl;
            saveUserData();
            return true;
        }
    }
    */
    return false;
}

bool ContactMenu::signOut() {
    /*
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
    */
    return false;
}

bool ContactMenu::resetPassword(string oldPassword, string newPassword) {
    /*
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
    */
    return true;
}

bool ContactMenu::createAccount(string firstName, string lastName, string phone, string email, string password) {
    /*
    if (user.getRole() != "admin") {
        cout << "Only admins can create accounts." << endl;
        return false;
    }
    maxUserId++;
    User newUser(maxUserId, "guest", email, password, DateTime(std::chrono::system_clock::now()), DateTime(std::chrono::system_clock::now()),
    firstName, lastName, "", "", "", "", phone, email);
    users.push_back(newUser);
    saveUserData();
    */
    return true;
}

bool ContactMenu::isSignedIn() {
    return false;
    //return user.getUserId() != 0;
}

bool ContactMenu::isAdmin() {
    return false;
    //return user.getRole() == "admin";
}

bool ContactMenu::manageProfile(Contact user) {
    /*
        for (int i = 0; i < users.size(); i++) {
        if (users[i].getUsername() == user.getUsername()) {
            users[i] = user;
            saveUserData();
            cout << "User " << user.getUsername() << " profile updated." << endl;
            return true;
        }
    }
    */
    return false;
}

Contact ContactMenu::getSignedInUser() {
    return contact;
}

