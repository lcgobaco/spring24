/*******************************************************

 * Program Name: UserMenu.cpp

 * Author: Lucas Gobaco

 * Date: 24 February 2024

 * Description: This program implements a class that displays a menu for a user.

 *******************************************************/

#include "UserMenu.h"
#include "Utils.h"

using namespace std;
void UserMenu::initUserData() {

    inFile.open(USERS_DATA);

    if (!inFile) {
        std::cerr << "Error: Unable to open the file." << std::endl;
    }

    // Read and print the contents of the file line by line
    std::string line;
    std::getline(inFile, line);

    while (std::getline(inFile, line)) {
        vector<string> tokens = splitString(line, ',');
        int userId = stoi(tokens[0]);
        if (userId > maxUserId) {
            maxUserId = userId;
        }
        User user (userId, tokens[1], tokens[2], tokens[3], DateTime(tokens[4]), DateTime(tokens[5]),
        tokens[6], tokens[7], tokens[8], tokens[9], tokens[10], tokens[11], tokens[12], tokens[13]);
        users.push_back(user);
    }

    // Close the file
    inFile.close();
}

void UserMenu::saveUserData() {
    ofstream outFile;
    outFile.open(USERS_DATA);

    if (!outFile) {
        std::cerr << "Error: Unable to open the file." << std::endl;
    }

    outFile << "Id,Role,Username,Password,Sign-in datetime,Sign out datetime,First Name,Last Name,Address,City,State,Zip,Phone,Email" << endl;

    for (int i = 0; i < users.size(); i++) {
        outFile << users[i].getUserId()
        << "," << users[i].getRole() << "," << users[i].getUsername() << "," << users[i].getPassword()
        << "," << users[i].getLoginDateTime().toString() << "," << users[i].getLogoutDateTime().toString()
        << "," << users[i].getFirstName() << "," << users[i].getLastName() << "," << users[i].getAddress()
        << "," << users[i].getCity() << "," << users[i].getState() << "," << users[i].getZip()
        << "," << users[i].getPhone() << "," << users[i].getEmail()
        << endl;
    }

    outFile.close();
}


UserMenu::UserMenu() {
    initUserData();
};

    // Destructor
UserMenu::~UserMenu() {
}

bool UserMenu::signIn(string username, string password) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getUsername() == username && users[i].getPassword() == password) {
            user = users[i];
            users[i].setLoginDateTime(DateTime(std::chrono::system_clock::now()));
            cout << "User " << user.getUsername() << " signed in." << endl;
            saveUserData();
            return true;
        }
    }
    return false;
}

bool UserMenu::signOut() {
    if (user.getUserId() == 0) {
        cout << "No user signed in." << endl;
        return false;
    }

    cout << "Signing out " << user.getUsername() << "..." << endl;

    for (int i = 0; i < users.size(); i++) {
        if (users[i].getUsername() == user.getUsername()) {
            users[i].setLogoutDateTime(DateTime(std::chrono::system_clock::now()));
            saveUserData();
            cout << "User " << user.getUsername() << " signed out." << endl;
            return true;
        }
    }
    return false;
}

bool UserMenu::resetPassword(string oldPassword, string newPassword) {
    if (user.getUserId() == 0) {
        cout << "No user signed in." << endl;
        return false;
    }

    for (int i = 0; i < users.size(); i++) {
        if (users[i].getUsername() == user.getUsername()) {
            if (users[i].getPassword() == oldPassword) {
                users[i].setPassword(newPassword);
                saveUserData();
                cout << "User " << user.getUsername() << " password reset." << endl;
                return true;
            }
            cout << "Incorrect password." << endl;
            return false;
        }
    }

    return true;
}

bool UserMenu::createAccount(string firstName, string lastName, string phone, string email, string password) {

    if (user.getRole() != "admin") {
        cout << "Only admins can create accounts." << endl;
        return false;
    }
    maxUserId++;
    User newUser(maxUserId, "guest", email, password, DateTime(std::chrono::system_clock::now()), DateTime(std::chrono::system_clock::now()),
    firstName, lastName, "", "", "", "", phone, email);
    users.push_back(newUser);
    saveUserData();
    return true;
}

bool UserMenu::isSignedIn() {
    return user.getUserId() != 0;
}

bool UserMenu::isAdmin() {
    return user.getRole() == "admin";
}

bool UserMenu::manageProfile(User user) {
        for (int i = 0; i < users.size(); i++) {
        if (users[i].getUsername() == user.getUsername()) {
            users[i] = user;
            saveUserData();
            cout << "User " << user.getUsername() << " profile updated." << endl;
            return true;
        }
    }
    return false;
}

User UserMenu::getSignedInUser() {
    return user;
}

User UserMenu::getUserByUsername(string username) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getUsername() == username) {
            return users[i];
        }
    }
    return User();
}

void UserMenu::doSignIn() {
    int tries = 0;
    while (tries < 3) {
        cout << "Sign-in" << endl;
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        bool signedIn = signIn(username, password);
        if (signedIn) {
            break;
        }
        tries++;
    }
}

void UserMenu::doSignOut() {
    cout << "Sign-out" << endl;
    bool signedOut = signOut();
    cout << "Signed out: " << signedOut << endl;
}

void UserMenu::doResetPassword() {
    if (!isSignedIn()) {
        cout << "Error: You must be signed in to reset your password." << endl;
        return;
    }
    cout << "Reset Password" << endl;
    cout << "Old Password: ";
    string oldPassword;
    cin >> oldPassword;
    cout << "New Password: ";
    string newPassword;
    cin >> newPassword;
    bool reset = this->resetPassword(oldPassword, newPassword);
}

void UserMenu::doCreateUser() {
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
        return;
    }

    bool created = createAccount(firstName, lastName, phone, email, password);
    cout << "Created: " << created << endl;
}

void UserMenu::doManageUserProfile() {
    cout << "Manage Profile" << endl;

    User userToManage = getSignedInUser();
    if (userToManage.getUsername() == "") {
        cout << "Error: User not found." << endl;
        return;
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
    bool managed = manageProfile(userToManage);
}

void UserMenu::activate() {
    char input;
    add_option("Sign-in");
    add_option("Sign-out");
    add_option("Reset Password");
    add_option("Create Account");
    add_option("Manage Profiles");
    add_option("Quit");
    do
    {
        input = get_input();

        cout << "Option: " << input << endl;
        switch (input)
        {
            case USER_MENU_SIGNIN:
            {
                doSignIn();
                break;
            }

            case USER_MENU_SIGNOUT:
            {
                doSignOut();
                break;
            }

            case USER_MENU_RESET:
            {
                doResetPassword();
                break;
            }

            case USER_MENU_CREATE:
            {
                doCreateUser();
                break;
            }

            case USER_MENU_MANAGE_PROFILE: {

                doManageUserProfile();
                break;
            }

            case USER_MENU_EXIT: {
                cout << "Quit" << endl;
                break;
            }
        }

    } while (input != USER_MENU_EXIT);
}
