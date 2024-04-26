/*******************************************************

 * Program Name: Menu.cpp

 * Author: Lucas Gobaco

 * Date: 6 April 2024

 * Description: This program implements a class that displays a menu into the console.

 *******************************************************/

#include "Menu.h"
#include <iostream>
#include <string>

using namespace std;

Menu::Menu() {}

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

string Menu::get_input() const
{
   string input;
   int n = -1;
   do
   {
      display();
      cin >> input;
      n = stoi(input);

   }
   while (n < 1 || n > options.size());
   return input;
}