#include <iostream>
#include <string>
#include <vector>
using namespace std;

std::vector<std::string> splitString(const std::string str, char delimiter) {
    std::vector<std::string> tokens;
    int start = 0;
    int end = str.find(delimiter);

    while (end != std::string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
        end = str.find(delimiter, start);
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

std::vector<std::string> splitStringDoubleQuotes(const std::string& input, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
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

    tokens.push_back(token); // Add the last token

    return tokens;
}

