#include <iostream> 
#include "unorderedArrayList.h"

using namespace std;

int main() {

    UnorderedArrayList<int> list1(25);
    UnorderedArrayList<int> list2(25);

    int number;

    //Sample data:  18 42 78 22 42 5 42 57 
    cout << "Enter 8 integers: ";

    for (int count = 0; count < 8; count++) {
        cin >> number;
        list1.insert(number);
    }

    list2 = list1;

    cout << endl;
    cout << "intList: ";
    list2.print();
    cout << endl;

    cout << "Enter the number to be "
        << "deleted: ";
    cin >> number;
    cout << endl;

    list1.remove(number);

    cout << "After removing " << number
        << " intList: ";
    list2.print();
    cout << endl;

    cout << "RetrieveAt: ";
    int x;
    list2.retrieveAt(3, x);

    cout << "Out: " << x << endl;

    cout << "Enter the search item: ";

    cin >> number;
    cout << endl;

    if (list2.search(number) != -1) {
        cout << number << " found in list." << endl;
    }
    else {
        cout << number << " is not in list." << endl;
    }

    return 0;
}