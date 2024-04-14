/*******************************************************

 * Program Name: main.cpp

 * Author: Lucas Gobaco

 * Date: 10 April 2024

 * Description: This program implements a program that prompts the user to input the filename and read the list of items from a file. If this function can’t find the file, it should throw an exception.

 *******************************************************/

#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

void loadFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Unable to open file: " + filename);
    }

    // File is open, do something with it
    cout << "File opened successfully." << endl;

    char ch;
    while (file.get(ch)) {
        cout << ch;
    }

    file.close();
}

int main() {
    cout << "Input file name: ";
    string filename;
    cin >> filename;

    try {
        loadFile(filename);
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
