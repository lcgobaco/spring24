#include "DateTime.h"
#include "Menu.h"

using namespace std;

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
