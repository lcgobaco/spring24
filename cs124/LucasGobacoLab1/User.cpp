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
