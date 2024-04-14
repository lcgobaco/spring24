#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string first_name;
    string middle_name;
    string last_name;
    string birthdate;
    string address;
    string city;
    string county;
    string state;
    string zip;
    string phone1;
    string phone2;
    string pronouns;
    string email;

public:
    // Constructor
    Person(string first, string middle, string last, DateTime dob, string addr, string cty, string cnty, string st, string zp, string ph1, string ph2, string pro, string em)
        : first_name(first), middle_name(middle), last_name(last), birthdate(dob), address(addr), city(cty), county(cnty), state(st), zip(zp), phone1(ph1), phone2(ph2), pronouns(pro), email(em) {}

    // Destructor
    ~Person() {}

    // Other member functions can be added as needed
    // For brevity, I'm not implementing accessor and mutator functions for each data member
};

