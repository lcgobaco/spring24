/**
* Name: <your name>
* Description: provide a short description of this class
* Date: <2/10/2024>
*/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "menu.h"

using namespace std;

/**
* TODO: provide comment here
*/
Menu::Menu() {
    name = "Undefine menu name";
};

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
    options.push_back(option);
}

/**
* Dipslay option name
*/
void Menu::display() const {
    cout << "***** " << name << " *****" << endl;
    for (int i = 0; i < (int)options.size(); i++) {
        cout << "  " << options[i] << endl;
    }
    cout << "Enter choice: ";
}

/**
* Display ordered index and option name
*/
void Menu::displayIndex() const {
    cout << "***** " << name << " *****" << endl;
    for (int i = 0; i < (int)options.size(); i++) {
        cout << i + 1 << "  ) " << options[i] << endl;
    }
    cout << "Enter choice: ";
}
/**
* Display option menu, option name; and ask users to select a choice by index
*/
int Menu::doMenuIndex() const {
    char ch;
    int input = 0;
    do {
        displayIndex();
        cin >> ch;
        input = static_cast<int>(ch) - 48;
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