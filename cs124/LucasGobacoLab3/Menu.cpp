/*******************************************************

 * Program Name: Menu.cpp

 * Author: Lucas Gobaco

 * Date: 24 February 2024

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

char Menu::get_input() const
{
   char input;
   int n;
   do
   {
      display();
      cin >> input;
      n = input - '0';
   }
   while (n < 1 && n >= options.size() && input != 'x');
   return input;
}

int Menu::get_input_int() const
{
   string input;
   display();
   cin >> input;
   return std::stoi(input);
}

