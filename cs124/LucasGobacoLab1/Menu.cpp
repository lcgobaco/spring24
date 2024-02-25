/*******************************************************

 * Program Name: Menu.cpp

 * Author: Lucas Gobaco

 * Date: 24 January 2024

 * Description: This program implements a class that displays a menu into the console.

 *******************************************************/

#include "Menu.h"
#include <iostream>
#include <string>

using namespace std;

Menu::Menu()
{
}

void Menu::add_option(string option)
{
   options.push_back(option);
}

void Menu::display() const
{
   for (int i = 0; i < options.size(); i++)
   {
      cout << i + 1 << ") " << options[i] << endl; 
   }
}

int Menu::get_input() const
{
   int input;
   do
   {
      display();
      cin >> input;
   }
   while (input < 1 || input > options.size());
   return input;
}