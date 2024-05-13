/*******************************************************

 * Program Name: main.cpp

 * Author: Lucas Gobaco

 * Date: 6 April 2024

 * Description: This program is a contact manager that allows the user to list, view, add, edit, and delete contacts.

 *******************************************************/

#include "Person.h"
#include "ContactMenu.h"

using namespace std;

int main() {
    ContactMenu menu;
    menu.activate();
    return 0;
}

/**
 * Determines if a string is a number.
 * @param s the string to check
 * @return true if the string is a number, false otherwise
*/
bool is_number(const string& s)
{
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
