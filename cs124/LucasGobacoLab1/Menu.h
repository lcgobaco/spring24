/*******************************************************

 * Program Name: Menu.h

 * Author: Lucas Gobaco

 * Date: 24 February 2024

 * Description: This program defines a class that displays a menu into the console.

 *******************************************************/

#ifndef MENU_H
#define MENU_H
#include <string>
#include <vector>
#include <iostream>

using namespace std;

/**
   Outlines a class that displays a menu in the console.
*/
class Menu
{
public:
   /**
      Constructor for menu class with no options
   */
   Menu();

   /**
      Adds an option to the end of the menu.
      @param option the option to add to the menu
   */
   void add_option(string option);

   /**
      Displays the menu, with options numbered starting with 1,
      and prompts the user for input. Repeats until a valid input 
      is supplied.
      @return the number that the user supplied
   */
   int get_input() const;
private:
    /**
      Displays the menu, with options numbered starting with 1.
   */
   void display() const;

   vector<string> options;
};

#endif