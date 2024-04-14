#include "Person.h"
#include "UserMenu.h"

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
    UserMenu main_menu;
    main_menu.add_option("Sign-in");
    main_menu.add_option("Sign-out");
    main_menu.add_option("Reset Password");
    main_menu.add_option("Create Account");
    main_menu.add_option("Manage Profiles");
    main_menu.add_option("Quit");

    test();
}
