#include "Person.h"
int main() {
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
