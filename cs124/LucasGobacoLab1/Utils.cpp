#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * This function splits a string into a vector of tokens based on a delimiter
*/
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
