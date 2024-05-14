/*******************************************************

 * Program Name: Utils.cpp

 * Author: Lucas Gobaco

 * Date: 6 April 2024

 * Description: This program implements a class that provides utility functions.

 *******************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> splitString(const string str, char delimiter) {
    vector<string> tokens;
    int start = 0;
    int end = str.find(delimiter);

    while (end != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
        end = str.find(delimiter, start);
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

vector<string> splitStringDoubleQuotes(const string& input, char delimiter) {
    vector<string> tokens;
    string token;
    bool insideQuotes = false;

    for (char c : input) {
        if (c == '"') {
            insideQuotes = !insideQuotes;
        }

        if (c == delimiter && !insideQuotes) {
            tokens.push_back(token);
            token.clear();
        } else {
            token += c;
        }
    }

    tokens.push_back(token);

    return tokens;
}