/*******************************************************

 * Program Name: Menu.h

 * Author: Lucas Gobaco

 * Date: 9 March 2024

 * Description: This program defines a class that displays a menu into the console.

 *******************************************************/

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <vector>

template <typename T>
class ArrayList {
private:
    std::vector<T> elements;

public:
    ArrayList();
    ~ArrayList();

    void add(const T& element);
    T& get(int index);
    int size() const;
    void clear();
    T& operator[](int index);
};

#endif // ARRAYLIST_H
