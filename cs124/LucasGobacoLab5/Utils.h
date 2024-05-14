/*******************************************************

 * Program Name: Utils.h

 * Author: Lucas Gobaco

 * Date: 6 April 2024

 * Description: This program defines a class that provides utility functions.

 *******************************************************/

#ifndef UTILS_H
#define UTILS_H

#include <string>

using namespace std;

/**
 * Splits a string into tokens using a delimiter.
 * @param str the string to split
 * @param delimiter the character to split the string by
 * @return a vector of tokens
 */
vector<string> splitString(const string str, char delimiter);

/**
 * Splits a string into tokens using a delimiter and ignores tokens inside double quotes.
 * @param str the string to split
 * @param delimiter the character to split the string by
 * @return a vector of tokens
 */
vector<string> splitStringDoubleQuotes(const string& str, char delimiter);

#endif
