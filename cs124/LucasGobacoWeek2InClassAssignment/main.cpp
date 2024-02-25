/*******************************************************

 * Program Name: main.cpp

 * Author: Lucas Gobaco

 * Date: 31 January 2024

 * Description: This program tests a class that displays a menu into the console.

 *******************************************************/

#include "Menu.h"

int main()
{
   Menu main_menu;
   main_menu.add_option("Sign-in");
   main_menu.add_option("Sign out");
   main_menu.add_option("Reset Password");
   main_menu.add_option("Create Account");
   main_menu.add_option("Manage Profiles");
   main_menu.add_option("Quit");
   int input = main_menu.get_input();
   cout << "Input: " << input << endl;
   return 0;
}