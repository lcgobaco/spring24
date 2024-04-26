/*******************************************************

 * Program Name: main.cpp

 * Author: Lucas Gobaco

 * Date: 6 April 2024

 * Description: This program is a contact manager that allows the user to list, view, add, edit, and delete contacts.

 *******************************************************/

#include "Person.h"
#include "ContactMenu.h"

using namespace std;

int main() {
    string input;
    ContactMenu contact_menu;

    contact_menu.add_option("List of contacts");
    contact_menu.add_option("View a contact");
    contact_menu.add_option("Add new contact");
    contact_menu.add_option("Edit contact");
    contact_menu.add_option("Delete contact");
    contact_menu.add_option("Exit");

    do
    {
        input = contact_menu.get_input();

        if (input == "x") {
            cout << "Quit" << endl;
            break;
        }

        int option = stoi(input);

        cout << "Option: " << option << endl;
        switch (option)
        {
            case 1:
            {
                cout << "List of contacts:" << endl;
                cout << "Sort by:" << endl;

                Menu sort_menu;
                sort_menu.add_option("Sort by ID"); 
                sort_menu.add_option("Sort by First Name");
                sort_menu.add_option("Sort by Middle Name");
                sort_menu.add_option("Sort by Last Name");
                sort_menu.add_option("Sort by Role"); 
                sort_menu.add_option("Sort by Company Name");
                sort_menu.add_option("Sort by Address");
                sort_menu.add_option("Sort by City");
                sort_menu.add_option("Sort by County"); 
                sort_menu.add_option("Sort by State");
                sort_menu.add_option("Sort by Zip");
                sort_menu.add_option("Sort by Phone1");
                sort_menu.add_option("Sort by Phone"); 
                sort_menu.add_option("Sort by Email"); 

                string input =sort_menu.get_input();
                string sort_field = "id";
                switch (stoi(input)) {
                    case 1:
                        sort_field = "id";
                        break;
                    case 2:
                        sort_field = "first_name";
                        break;
                    case 3:
                        sort_field = "middle_name";
                        break;
                    case 4:
                        sort_field = "last_name";
                        break;
                    case 5:
                        sort_field = "role";
                        break;
                    case 6:
                        sort_field = "company_name";
                        break;
                    case 7:
                        sort_field = "address";
                        break;
                    case 8:
                        sort_field = "city";
                        break;
                    case 9:
                        sort_field = "county";
                        break;
                    case 10:
                        sort_field = "state";
                        break;
                    case 11:
                        sort_field = "zip";
                        break;
                    case 12:
                        sort_field = "phone1";
                        break;
                    case 13:
                        sort_field = "phone";
                        break;
                    case 14:
                        sort_field = "email";
                        break;

                }

                Menu sort_order;
                sort_order.add_option("Ascending");
                sort_order.add_option("Descending");

                input = sort_order.get_input();

                switch(stoi(input)) {
                    case 1:
                        contact_menu.doSortBy(sort_field, "asc");
                        break;
                    case 2:
                        contact_menu.doSortBy(sort_field, "desc");
                        break;
                }

                contact_menu.doList();
                break;
            }

            case 2:
            {

                contact_menu.doView();
                break;
            }

            case 3:
            {
                contact_menu.doAdd();
                break;
            }

            case 4:
            {
                contact_menu.doEdit();
                break;
            }

            case 5: {
                contact_menu.doDelete();
                break;
            }

            case 6: {
                contact_menu.doExit();
                cout << "Quit" << endl;
                break;
            }
        }

    } while (input != "6" );
}

/**
 * Determines if a string is a number.
 * @param s the string to check
 * @return true if the string is a number, false otherwise
*/
bool is_number(const string& s)
{
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}