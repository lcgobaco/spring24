/*******************************************************

 * Program Name: User.h

 * Author: Lucas Gobaco

 * Date: 24 February 2024

 * Description: This program defines a class that stores a user's account.

 *******************************************************/

#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <fstream>
#include "DateTime.h"

using namespace std;

// User class definition
class User {
private:
    int userId;
    std::string username;
    std::string password;
    DateTime loginDateTime;
    DateTime logoutDateTime;

public:
    // Constructor
    User(int id, string name, string pass, DateTime loginDT, DateTime logoutDT);

    // Destructor
    ~User();

    // Getter methods
    int getUserId() const { return userId; }
    std::string getUsername() const { return username; }
    std::string getPassword() const { return password; }
    DateTime getLoginDateTime() const { return loginDateTime; }
    DateTime getLogoutDateTime() const { return logoutDateTime; }

    // Other methods...
};

#endif