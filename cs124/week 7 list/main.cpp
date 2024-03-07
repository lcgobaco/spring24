/*******************************************************

 * Program Name: main.cpp

 * Author: Lucas Gobaco

 * Date: 6 March 2024

 * Description: This program tests a list class and an iterator class that is to be used with the list class.

 *******************************************************/

#include <string>
#include <iostream>
#include "list.h"

int main()
{
    List<std::string> names;

    names.push_back("Tom");
    names.push_back("Diana");
    names.push_back("Harry");
    names.push_back("Juliet");

    // Add a value in fourth place

    Iterator<std::string> pos = names.begin();
    pos.next();
    pos.next();
    pos.next();

    names.insert(pos, "Romeo");

    // Remove the value in second place

    pos = names.begin();
    pos.next();

    names.erase(pos);

    // Print all values

    for (pos = names.begin(); !pos.equals(names.end()); pos.next())
    {
        std::cout << pos.get() << std::endl;
    }

    // Now access using index
    for (int i = 0; i < 4; i++)
    {
        std::cout << i << ": " << names.get(i) << std::endl;
    }
    names.erase(names.begin());
    // Now access using index
    std::cout << "After deleting first element" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << i << ": " << names.get(i) << std::endl;
    }
    Iterator<std::string> iter = names.begin();
    iter.next();
    iter.next();
    names.erase(iter);
    std::cout << "After deleting last element" << std::endl;
    for (int i = 0; i < 2; i++)
    {
        std::cout << i << std::endl;
        std::cout << i << ": " << names.get(i) << std::endl;
    }

    return 0;
}


