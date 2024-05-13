/*******************************************************

 * Program Name: User.cpp

 * Author: Lucas Gobaco

 * Date: 24 February 2024

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

// Overloaded << operator to enable printing User object to ostream
ostream& operator<<(ostream& os, const User& user) {
    os << "User ID: " << user.userId << endl;
    os << "Role: " << user.role << endl;
    os << "Username: " << user.username << endl;
    os << "Password: " << user.password << endl;
    os << "Login Date/Time: " << user.loginDateTime.toString() << endl;
    os << "Logout Date/Time: " << user.logoutDateTime.toString() << endl;
    os << "First Name: " << user.firstName << endl;
    os << "Last Name: " << user.lastName << endl;
    os << "Address: " << user.address << endl;
    os << "City: " << user.city << endl;
    os << "State: " << user.state << endl;
    os << "ZIP: " << user.zip << endl;
    os << "Phone: " << user.phone << endl;
    os << "Email: " << user.email << endl;
    return os;
}

// Overloaded == operator to compare two User objects for equality
bool operator==(const User& user1, const User& user2) {
    return (user1.userId == user2.userId) && (user1.username == user2.username);
}
