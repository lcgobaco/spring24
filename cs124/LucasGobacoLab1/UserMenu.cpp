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
        User user (std::stoi(tokens[0]), tokens[2], tokens[3], DateTime(tokens[4]), DateTime(tokens[5]));
        users.push_back(user);
    }

    for (int i = 0; i < users.size(); i++) {
        cout << users[i].getUserId() << " " << users[i].getUsername() << " " << users[i].getPassword() << endl;
    }

    // Close the file
    inFile.close();
}


UserMenu::UserMenu() {
    initUserData();
};

    // Destructor
UserMenu::~UserMenu() {
}

/*
UserMenu::signIn() {
    return true;
}
*/
