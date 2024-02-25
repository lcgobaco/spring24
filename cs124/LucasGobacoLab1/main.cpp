/*******************************************************

 * Program Name: main.cpp

 * Author: Lucas Gobaco

 * Date: 24 February 2024

 * Description: This program manages user accounts.

 *******************************************************/

#include "DateTime.h"
#include "Menu.h"
#include "UserMenu.h"

using namespace std;

int main()
{

    int input;
    do
    {
        UserMenu main_menu;
        main_menu.add_option("Sign-in");
        main_menu.add_option("Sign-out");
        main_menu.add_option("Reset Password");
        main_menu.add_option("Create Account");
        main_menu.add_option("Manage Profiles");
        main_menu.add_option("Quit");
        input = main_menu.get_input();

    } while (input != 6);
    return 0;
}

