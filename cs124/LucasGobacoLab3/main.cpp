
int main() {
    // Example usage
    //DateTime dob(1990, 5, 15); // Assuming DateTime class is implemented
    Person person("John", "Doe", "", dob, "123 Main St", "Anytown", "Anycounty", "Anystate", "12345", "123-456-7890", "987-654-3210", "he", "john.doe@example.com");

    // Accessing data members
    cout << "First Name: " << person.first_name << endl;
    cout << "Middle Name: " << person.middle_name << endl;
    cout << "Last Name: " << person.last_name << endl;
    // Similarly, access other data members as needed

    return 0;
}
