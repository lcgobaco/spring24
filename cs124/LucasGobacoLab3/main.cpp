#include "Person.h"
#include "ContactMenu.h"

int test() {
    // Example usage
    DateTime dob(1990, 5, 15); // Assuming DateTime class is implemented
    Person person("John", "Doe", "", dob, "123 Main St", "Anytown", "Anycounty", "Anystate", "12345", "123-456-7890", "987-654-3210", "he", "john.doe@example.com");

    // Accessing data members using accessor functions
    cout << "First Name: " << person.getFirstName() << endl;
    cout << "Middle Name: " << person.getMiddleName() << endl;
    cout << "Last Name: " << person.getLastName() << endl;
    // Similarly, access other data members using accessor functions

    // Modifying data members using mutator functions
    person.setFirstName("Jane");
    person.setEmail("jane.doe@example.com");

    return 0;
}

int main() {
    string input;
    ContactMenu main_menu;

    main_menu.add_option("List of contacts");
    main_menu.add_option("View a contact");
    main_menu.add_option("Add new contact");
    main_menu.add_option("Edit contact");
    main_menu.add_option("Delete contact");
    main_menu.add_option("Exit");

    do
    {
        input = main_menu.get_input();

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
                    bool signedIn = main_menu.signIn(username, password);
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
                bool signedOut = main_menu.signOut();
                cout << "Signed out: " << signedOut << endl;
                break;
            }

            case 3:
            {
                if (main_menu.isSignedIn() == false) {
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
                bool reset = main_menu.resetPassword(oldPassword, newPassword);
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

                bool created = main_menu.createAccount(firstName, lastName, phone, email, password);
                cout << "Created: " << created << endl;
                break;
            }

            case 5: {
                cout << "Manage Profile" << endl;

                User userToManage = main_menu.getSignedInUser();
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
            }

            case 6: {
                cout << "Quit" << endl;
                break;
            }
        }

    } while (input != "6" );

    test();
}
