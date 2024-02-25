/*******************************************************

 * Program Name: main.cpp

 * Author: Lucas Gobaco

 * Date: 24 February 2024

 * Description: This program manages user accounts.

 *******************************************************/

#include "DateTime.h"
#include "UserMenu.h"
#include "User.h"

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

        switch (input)
        {

            case 1:
            {
                cout << "Sign-in" << endl;
                string username, password;
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                bool signedIn = main_menu.signIn(username, password);
                cout << "Signed in: " << signedIn << endl;
                break;
            }

            case 2:
            {
                cout << "Sign-out" << endl;
                break;
            }

            case 3:
            {
                cout << "Reset Password" << endl;
                break;
            }

            case 4:
            {
                cout << "Create Account" << endl;
                break;
            }

            case 5: {
                cout << "Manage Profiles" << endl;
                break;
            }

            case 6: {
                cout << "Quit" << endl;
                break;
            }
        }

    } while (input != 6);
    return 0;
}

