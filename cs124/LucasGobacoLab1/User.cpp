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
    userId = id;
    role = role;
    username = name;
    password = pass;
    loginDateTime = loginDT;
    logoutDateTime = logoutDT;
    firstName = fName;
    lastName = lName;
    address = address;
    city = city;
    state = state;
    zip = zip;
    phone = phone;
    email = email;
}
User::User() {};

// Destructor
User::~User() {}
