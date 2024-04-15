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

    vector<Contact> contacts = contact_menu.getContacts();

    // Iterate through the contact list
    for (int i = 0; i < contact_menu.getContacts().size(); i++) {
        Contact contact = contacts[i];
        std::cout << "ID: " << contact.getId() << std::endl;
        std::cout << "Name: " << contact.getFirstName() << " " << contact.getMiddleName() << " " << contact.getLastName() << std::endl;
        std::cout << "Role: " << contact.getRole() << std::endl;
        std::cout << "Company: " << contact.getCompanyName() << std::endl;
        std::cout << "Address: " << contact.getAddress() << std::endl;
        std::cout << "City: " << contact.getCity() << std::endl;
        std::cout << "County: " << contact.getCounty() << std::endl;
        std::cout << "State: " << contact.getState() << std::endl;
        std::cout << "ZIP: " << contact.getZip() << std::endl;
        std::cout << "Phone 1: " << contact.getPhone1() << std::endl;
        std::cout << "Phone 2: " << contact.getPhone2() << std::endl;
        std::cout << "Email: " << contact.getEmail() << std::endl;
        std::cout << std::endl;
    }

    do
    {
        input = contact_menu.get_input();

        cout << "Input == x " << input << " " << (input == "x") << " " << endl;

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
                int tries = 0;
                while (tries < 3) {
                    cout << "Sign-in" << endl;
                    string username, password;
                    cout << "Enter username: ";
                    cin >> username;
                    cout << "Enter password: ";
                    cin >> password;

                    bool signedIn = contact_menu.signIn(username, password);
                    if (signedIn) {
                        break;
                    }
                    tries++;
                }
                break;
            }

            case 2:
            {
                cout << "Sign-out" << endl;
                bool signedOut = contact_menu.signOut();
                cout << "Signed out: " << signedOut << endl;
                break;
            }

            case 3:
            {
                if (contact_menu.isSignedIn() == false) {
                    cout << "Error: You must be signed in to reset your password." << endl;
                    break;
                }
                cout << "Reset Password" << endl;
                cout << "Old Password: ";
                string oldPassword;
                cin >> oldPassword;
                cout << "New Password: ";
                string newPassword;
                cin >> newPassword;
                bool reset = contact_menu.resetPassword(oldPassword, newPassword);
                break;
            }

            case 4:
            {
                cout << "Create Account" << endl;
                string firstName, lastName, phone, email, password, reEnterPassword;
                cout << "Enter first name: ";
                cin >> firstName;
                cout << "Enter last name: ";
                cin >> lastName;
                cout << "Enter mobile number or email: ";
                cin >> phone;
                cout << "Enter password: ";
                cin >> password;
                cout << "Enter re-enter password: ";
                cin >> reEnterPassword;
                if (password != reEnterPassword)
                {
                    cout << "Passwords do not match." << endl;
                    break;
                }

                bool created = contact_menu.createAccount(firstName, lastName, phone, email, password);
                cout << "Created: " << created << endl;
                break;
            }

            case 5: {
                cout << "Manage Profile" << endl;
                /*

                Contact userToManage = main_menu.getSignedInUser();
                if (userToManage.getUsername() == "") {
                    cout << "Error: User not found." << endl;
                    break;
                }

                string role, firstName, lastName, email, phone, address, city, state, zip;

                cout << "Role:" << userToManage.getRole() << endl;
                cout << "New Role: ";
                cin >> role;
                cout << "First Name: " << userToManage.getFirstName() << endl;
                cout << "New First Name: ";
                cin >> firstName;
                cout << "Last Name: " << userToManage.getLastName() << endl;
                cout << "New Last Name: ";
                cin >> lastName;
                cout << "Email: " << userToManage.getEmail() << endl;
                cout << "New Email: ";
                cin >> email;
                cout << "Phone: " << userToManage.getPhone() << endl;
                cout << "New Phone: ";
                cin >> phone;
                cout << "Address: " << userToManage.getAddress() << endl;
                cout << "New Address: ";
                cin >> address;
                cout << "City: " << userToManage.getCity() << endl;
                cout << "New City: ";
                cin >> city;
                cout << "State: " << userToManage.getState() << endl;
                cout << "New State: ";
                cin >> state;
                cout << "Zip: " << userToManage.getZip() << endl;
                cout << "New Zip: ";
                cin >> zip;

                userToManage.setRole(role);
                userToManage.setFirstName(firstName);
                userToManage.setLastName(lastName);
                userToManage.setEmail(email);
                userToManage.setPhone(phone);
                userToManage.setAddress(address);
                userToManage.setCity(city);
                userToManage.setState(state);
                userToManage.setZip(zip);
                bool managed =main_menu.manageProfile(userToManage);
                break;
                */
            }

            case 6: {
                cout << "Quit" << endl;
                break;
            }
        }

    } while (input != "6" );
}
