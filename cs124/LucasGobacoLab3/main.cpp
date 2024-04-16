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
                sort_menu.add_option("Sort by ID"); // 0
                sort_menu.add_option("Sort by First Name");
                sort_menu.add_option("Sort by Middle Name");
                sort_menu.add_option("Sort by Last Name");
                sort_menu.add_option("Sort by Role"); // 4
                sort_menu.add_option("Sort by Company Name");
                sort_menu.add_option("Sort by Address");
                sort_menu.add_option("Sort by City");
                sort_menu.add_option("Sort by County"); // 8
                sort_menu.add_option("Sort by State");
                sort_menu.add_option("Sort by Zip");
                sort_menu.add_option("Sort by Phone1");
                sort_menu.add_option("Sort by Phone"); // 12
                sort_menu.add_option("Sort by Email"); // 13

                string input =sort_menu.get_input();
                string sort_field = "id";
                switch (std::stoi(input)) {
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

                switch(std::stoi(input)) {
                    case 1:
                        contact_menu.doSortBy(sort_field, "asc");
                        break;
                    case 2:
                        contact_menu.doSortBy(sort_field, "desc");
                        break;
                }

                //contact_menu.doList();
                break;
            }

            case 2:
            {

                contact_menu.doView();
                break;
            }

            case 3: // Add new contact
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

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
