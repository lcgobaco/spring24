/*******************************************************

 * Program Name: menu.cpp

 * Author: Lucas Gobaco

 * Date: 13 May 2024

 * Description: This program implements a general purpose class menu.

 * Changes: 
    * 1. Changed the options.push_back(option) to options.insert(option) in addOption method
    * 2. In display() method, changed the for loop to use an iterator to traverse the hash table
    * 3. In displayPrefixIndex() method, changed the for loop to use an iterator to traverse the hash table

 *******************************************************/

#include <iostream>
#include <string>
#include "menu.h"

using namespace std;

/**
* Initial menu name
*/
Menu::Menu(string name) {
    this->name = name;
}

/**
* Add menu open name
*/
void Menu::addOption(string option) {
    // changed from options.push_back(option) to options.insert(option)
    options.insert(option);
}

/**
* Displays the menu
*/
void Menu::display() const {
    cout << "***** " << name << " *****" << endl;
    // now using iterator to traverse the hash table
    for (Iterator<string> iter = options.begin(); !iter.equals(options.end()); iter.next()) {
        cout << iter.get() << endl;
    }
    cout << "\nEnter choice: ";
}

/**
* Display ordered index and option name
*/
void Menu::displayPrefixIndex() const {
    cout << "***** " << name << " *****" << endl;
    // now using iterator to traverse the hash table
    int i = 0;
    for (Iterator<string> iter = options.begin(); !iter.equals(options.end()); iter.next()) {
        cout << i + 1 << ") " << iter.get() << endl;
        i++;
    }
    cout << "\nEnter choice: ";
}
/**
* Display option menu, option name; and ask users to select a choice by index
*/
int Menu::doMenuIndex() const {
    char ch;
    int input = 0;
    do {
        displayPrefixIndex();
        cin >> ch;
        input = static_cast<int>(ch) - 48;
    } while (input < 1 || input >(int)options.size());
    return input;
}

/**
* Display option menu, option name; and ask users to select a choice
*/
int Menu::doMenu() const {
    int input = 0;
    do {
        display();
        cin >> input;
    } while (input < 1 || input >(int)options.size());
    return input;
}

/**
* Display option menu, option name; and ask users to select a choice
*/
char Menu::doMenuOption() const {
    char input;
    display();
    cin >> input;
    return input;
}