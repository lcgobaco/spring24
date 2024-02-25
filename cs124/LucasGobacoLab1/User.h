#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <fstream>
#include "DateTime.h"

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
    User(int id, const std::string& uname, const std::string& pwd, const DateTime& loginDT, const DateTime& logoutDT)
        : userId(id), username(uname), password(pwd), loginDateTime(loginDT), logoutDateTime(logoutDT) {}

    // Getter methods
    int getUserId() const { return userId; }
    std::string getUsername() const { return username; }
    std::string getPassword() const { return password; }
    DateTime getLoginDateTime() const { return loginDateTime; }
    DateTime getLogoutDateTime() const { return logoutDateTime; }

    // Other methods...
};

#endif // USER_H

