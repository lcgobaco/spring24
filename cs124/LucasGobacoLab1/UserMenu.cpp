/*******************************************************

 * Program Name: UserMenu.cpp

 * Author: Lucas Gobaco

 * Date: 24 February 2024

 * Description: This program implements a class that displays a menu for a user.

 *******************************************************/

#include "UserMenu.h"
#include "Utils.h"

using namespace std;

/*
Id,
Role,
Username,
Password,
Sign-in datetime,
Sign out datetime,
First Name,
Last Name,
Address,
City,
State,
Zip,
Phone,
Email
1001,guess,guess,welcome,1/29/2024 18:30:11,2/10/2024 20:30:14,guess,guess,39399 Cherry St,Fremont,CA,94560,510-7422300,guess@ohlone.edu
1002,admin,admin,welcome1,1/29/2024 17:10:10,2/10/2024 20:35:45,admin,ohlone,43600 Mission Blvd,Fremont,CA,94539,510-659-6000,admin@ohlone.edu
1003,student,john,doe,1/29/2024 18:30:01,2/10/2024 20:45:50,John,Doe,43600 Mission Blvd,Fremont,CA,94539,510-659-6000,jdoe@ohlone.student.edu
1004,admin,jpham,admin,1/29/2024 18:30:01,2/10/2024 20:45:50,James,Pham,43600 Mission Blvd,Fremont,CA,94539,510-659-6000,jpham@ohlone.edu
*/
void UserMenu::initUserData() {

    inFile.open(USERS_DATA);

    if (!inFile) {
        std::cerr << "Error: Unable to open the file." << std::endl;
    }

    // Read and print the contents of the file line by line
    std::string line;
    std::getline(inFile, line);

    while (std::getline(inFile, line)) {
        cout << line << endl;
        vector<string> tokens = splitString(line, ',');
        User user (std::stoi(tokens[0]), tokens[1], tokens[2], tokens[3], DateTime(tokens[4]), DateTime(tokens[5]),
        tokens[6], tokens[7], tokens[8], tokens[9], tokens[10], tokens[11], tokens[12], tokens[13]);
        users.push_back(user);
    }

    for (int i = 0; i < users.size(); i++) {
        cout << users[i].getUserId() << " " << users[i].getUsername() << " " << users[i].getPassword() << endl;
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

/*bool UserMenu::signOut() {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getUsername() == user.getUsername()) {
            users[i] = user;
            cout << "User " << user.getUsername() << " signed out." << endl;
            return true;
        }
    }
    return false;
}
*/
