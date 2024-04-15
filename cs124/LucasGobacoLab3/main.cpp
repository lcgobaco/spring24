#include "Person.h"
#include "ContactMenu.h"

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

        int option = std::stoi(input);

        cout << "Option: " << option << endl;
        switch (option)
        {
            case 1:
            {
                cout << "List of contacts:" << endl;
                cout << "Sort by:" << endl;
                Menu sort_menu;
                contact_menu.add_option("Sort by ID");
                contact_menu.add_option("View a contact");
                contact_menu.add_option("Add new contact");
                contact_menu.add_option("Edit contact");
                contact_menu.add_option("Delete contact");

                contact_menu.doSortBy("first_name");
                contact_menu.doList();
                break;
            }

            case 2:
            {
                cout << "View Contact:" << endl;
                cout << "Enter Contact ID: ";
                string contact_id;
                cin >> contact_id;
                contact_menu.doView(contact_id);
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
