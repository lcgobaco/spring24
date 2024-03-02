/*******************************************************

 * Program Name: User.cpp

 * Author: Lucas Gobaco

 * Date: 8 February 2024

 * Description: This program implements a class that stores a user's account.

 *******************************************************/

#include "User.h"
#include "DateTime.h"
#include <string>

using namespace std;

// Constructor
User::User(int id, string role, string name, string pass, DateTime loginDT, DateTime logoutDT, string fName, string lName, string address, string city, string state, string zip, string phone, string email) {
    this->userId = id;
    this->role = role;
    this->username = name;
    this->password = pass;
    this->loginDateTime = loginDT;
    this->logoutDateTime = logoutDT;
    this->firstName = fName;
    this->lastName = lName;
    this->address = address;
    this->city = city;
    this->state = state;
    this->zip = zip;
    this->phone = phone;
    this->email = email;
}

User::User() {};

// Destructor
User::~User() {}

bool operator==(const User&) const {
    return this.userId == User.getUserId();
}

bool operator!=(const User&) const {
    return this.userId != User.getUserId();
}

bool operator>(const User&) const {
    return this.userId > User.getUserId();
}

bool operator<(const User&) const {
    return this.userId < User.getUserId();
}

bool operator>=(const User&) const {
    return this.userId >= User.getUserId();
}

bool operator<=(const User&) const {
    return this.userId <= User.getUserId();
}

friend istream& operator>>(istream& in, User& user) {
    int id;
    string role;
    string username;
    string pass;
    string loginDT;
    string logoutDT;
    string firstName;
    string lastName;
    string address;
    string city;
    string state;
    string zip;
    string phone;
    string email;
    char separator;
    in >> id;
    in.get(separator);
    in >> role;
    in.get(separator);
    in >> username;
    in.get(separator);
    in >> pass;
    in.get(separator);
    in >> loginDT;
    in.get(separator);
    in >> logoutDT;
    in.get(separator);
    in >> firstName;
    in.get(separator);
    in >> lastName;
    in.get(separator);
    in >> address;
    in.get(separator);
    in >> city;
    in.get(separator);
    in >> state;
    in.get(separator);
    in >> zip;
    in.get(separator);
    in >> phone;
    in.get(separator);
    in >> email;
    user = User(id, role, username, pass, DateTime(loginDT), DateTime(logoutDT), firstName, lastName, address, city, state, zip, phone, email);
    return in;
}

friend ostream& operator<<(ostream& out, User& user) {
    out << user.getUserId() << "," << user.getRole() << "," << user.getUsername() << "," << user.getPassword() << "," << user.getLoginDateTime() << "," << user.getLogoutDateTime() << "," << user.getFirstName() << "," << user.getLastName() << "," << user.getAddress() << "," << user.getCity() << "," << user.getState() << "," << user.getZip() << "," << user.getPhone() << "," << user.getEmail();
    return out;
}