#ifndef MENU_H
#define MENU_H
enum USER_MENU_OPTION {
USER_MENU_SIGNIN = '1',
USER_MENU_CREATE = '2',
USER_MENU_CREATE = '3',
USER_MENU_REMOVE = '4',
USERMENU_RESET = '5',
USERMENU_MANAGE_PROFILE = '6',
USER_MENU_EXIT = 'x'
};
class UserMenu : public Menu {
private:
// Member variables and any other variables if necessary
fstream inFile;
User user;
vector<User> users;
}

#endif // MENU_H
