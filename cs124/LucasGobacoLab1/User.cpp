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
User::User(int id, string name, string pass, DateTime loginDT, DateTime logoutDT)
{
    userId = id;
    username = name;
    password = pass;
    loginDateTime = loginDT;
    logoutDateTime = logoutDT;
}

// Destructor
User::~User() {}