#include <iostream>
#include <string>

class User {
private:
    std::string UserId;
    std::string FirstName;
    std::string LastName;
    std::string Department;
    std::string Address;
    std::string City;
    std::string State;
    std::string Zip;
    std::string Email;
    std::string Phone;

public:
    // Constructor
    User(const std::string& userId, const std::string& firstName, const std::string& lastName,
         const std::string& department, const std::string& address, const std::string& city,
         const std::string& state, const std::string& zip, const std::string& email,
         const std::string& phone)
        : UserId(userId), FirstName(firstName), LastName(lastName), Department(department),
          Address(address), City(city), State(state), Zip(zip), Email(email), Phone(phone) {}

    // Accessor methods
    std::string getUserId() const { return UserId; }
    std::string getFirstName() const { return FirstName; }
    std::string getLastName() const { return LastName; }
    std::string getDepartment() const { return Department; }
    std::string getAddress() const { return Address; }
    std::string getCity() const { return City; }
    std::string getState() const { return State; }
    std::string getZip() const { return Zip; }
    std::string getEmail() const { return Email; }
    std::string getPhone() const { return Phone; }

    // Mutator methods (if needed)
    // void setUserId(const std::string& userId) { UserId = userId; }
    // void setFirstName(const std::string& firstName) { FirstName = firstName; }
    // void setLastName(const std::string& lastName) { LastName = lastName; }
    // void setDepartment(const std::string& department) { Department = department; }
    // void setAddress(const std::string& address) { Address = address; }
    // void setCity(const std::string& city) { City = city; }
    // void setState(const std::string& state) { State = state; }
    // void setZip(const std::string& zip) { Zip = zip; }
    // void setEmail(const std::string& email) { Email = email; }
    // void setPhone(const std::string& phone) { Phone = phone; }
};

int main() {
    // Creating a user object
    User user("12345", "John", "Doe", "IT", "123 Main St", "Anytown", "CA", "12345", "john.doe@example.com", "123-456-7890");

    // Accessing user information
    std::cout << "User ID: " << user.getUserId() << std::endl;
    std::cout << "First Name: " << user.getFirstName() << std::endl;
    std::cout << "Last Name: " << user.getLastName() << std::endl;
    std::cout << "Department: " << user.getDepartment() << std::endl;
    std::cout << "Address: " << user.getAddress() << std::endl;
    std::cout << "City: " << user.getCity() << std::endl;
    std::cout << "State: " << user.getState() << std::endl;
    std::cout << "Zip: " << user.getZip() << std::endl;
    std::cout << "Email: " << user.getEmail() << std::endl;
    std::cout << "Phone: " << user.getPhone() << std::endl;

    return 0;
}
