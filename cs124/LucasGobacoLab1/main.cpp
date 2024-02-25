/*******************************************************

 * Program Name: main.cpp

 * Author: Lucas Gobaco

 * Date: 24 February 2024

 * Description: This program manages user accounts.

 *******************************************************/

#include "DateTime.h"
#include "UserMenu.h"
#include "User.h"
#include <ctime>

using namespace std;

int main()
{

    int input;
    UserMenu main_menu;
    main_menu.add_option("Sign-in");
    main_menu.add_option("Sign-out");
    main_menu.add_option("Reset Password");
    main_menu.add_option("Create Account");
    main_menu.add_option("Manage Profiles");
    main_menu.add_option("Quit");
    do
    {
        input = main_menu.get_input();

        switch (input)
        {

            case 1:
            {
                int tries = 0;
                while (tries < 3) {
                    cout << "Sign-in" << endl;
                    string username, password;
                    cout << "Enter username: ";
                    cin >> username;
                    cout << "Enter password: ";
                    cin >> password;
                    bool signedIn = main_menu.signIn(username, password);
                    if (signedIn) {
                        break;
                    }
                    tries++;
                }
            }

            case 2:
            {
                cout << "Sign-out" << endl;
                bool signedOut = main_menu.signOut();
                cout << "Signed out: " << signedOut << endl;
                break;
            }

            case 3:
            {
                cout << "Reset Password" << endl;
                cout << "Old Password: ";
                string oldPassword;
                cin >> oldPassword;
                cout << "New Password: ";
                string newPassword;
                cin >> newPassword;
                bool reset = main_menu.resetPassword(oldPassword, newPassword);
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

