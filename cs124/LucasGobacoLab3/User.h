/*******************************************************

 * Program Name: User.h

 * Author: Lucas Gobaco

 * Date: 24 February 2024

 * Description: This program defines a class that stores a user's account.

 *******************************************************/

#ifndef USER_H
#define USER_H

#include <string>
#include "DateTime.h"

using namespace std;

// User class definition
class User {
private:
    int userId;
    string role;
    string username;
    string password;
    DateTime loginDateTime;
    DateTime logoutDateTime;
    string firstName;
    string lastName;
    string address;
    string city;
    string state;
    string zip;
    string phone;
    string email;

public:
    // Constructor
    User(int id, string role, string name, string pass, DateTime loginDT, DateTime logoutDT,
    string first, string last, string address, string city, string state, string zip, string phone, string email);

    User();

    // Destructor
    ~User();

    // Getter methods
    int getUserId() const { return userId; }
    string getRole() const { return role; }
    string getUsername() const { return username; }
    string getPassword() const { return password; }
    DateTime getLoginDateTime() const { return loginDateTime; }
    DateTime getLogoutDateTime() const { return logoutDateTime; }
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    string getAddress() const { return address; }
    string getCity() const { return city; }
    string getState() const { return state; }
    string getZip() const { return zip; }
    string getPhone() const { return phone; }
    string getEmail() const { return email; }


    void setUserId(int id) { this->userId = id; }
    void setRole(string role) { this->role = role; }
    void setUsername(string name) { this->username = name; }
    void setFirstName(string first) { this->firstName = first; }
    void setLastName(string last) { this->lastName = last; }
    void setAddress(string address) { this->address = address; }
    void setCity(string city) { this->city = city; }
    void setState(string state) { this->state = state; }
    void setZip(string zip) { this->zip = zip; }
    void setPhone(string phone) { this->phone = phone; }
    void setEmail(string email) { this->email = email; }
    void setPassword(string pass) { this->password = pass; }
    void setLoginDateTime(DateTime loginDT) { this->loginDateTime = loginDT; }
    void setLogoutDateTime(DateTime logoutDT) { this->logoutDateTime = logoutDT; }

    // Other methods...
};

#endif // USER_H
