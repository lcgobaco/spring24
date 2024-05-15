/*******************************************************

 * Program Name: menu.h

 * Author: Lucas Gobaco

 * Date: 13 May 2024

 * Description: This program defines a general purpose class menu.

 * Changes:
   * 1. Changed options member from vector to HashTable
   * 2. Changed getName method to use iterator to traverse the hash table

 *******************************************************/

#pragma once

#include <iostream>
#include <string>
#include "hashtable.h"

using namespace std;

/**
   General purpose class menu
*/
class Menu {
public:
    /**
     * Constructs a menu with no options.
    */
    Menu() {};

    /**
       Constructs a menu with no options.
    */
    Menu(string name);

    /**
       Sets the name of this menu.
       @param name the name to set
    */
    void setName(string name) {
        this->name = name;
    }

   /**
      Gets the option at this index.
      @return the name
      Changes: now using iterator to traverse the hash table
   */
    string getName(int index) const {
      HashIterator<string> iter = options.begin();
      for (int i = 0; i < index; i++)
         iter.next();
      return iter.get();
    }

    /**
       Adds an option to the end of this menu.
       @param option the option to add
    */
    void addOption(string option);

    /**
    * Display option menu, option name; and ask users to select a choice
    * @return the number that the user supplied
    */
    int doMenu() const;

    /**
    * Display option menu, option name; and ask users to select a choice by index
    * @return the number that the user supplied
    */
    int doMenuIndex() const;

    /**
    * Display option menu, option name; and ask users to select a choice
    * @return the number that the user supplied
    */
    char doMenuOption() const;

    /**
     * Check if menu has options
     * @return true if menu has options
     */
    bool hasOption() const {
        return options.size() > 0;
    };
private:
    /**
       Displays this menu.
    */
    void display() const;


    void displayPrefixIndex() const;

    string name;

    // Changed from vector to HashTable
    HashTable<string> options;
};
