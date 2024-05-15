/*******************************************************

 * Program Name: task.h

 * Author: Lucas Gobaco

 * Date: 13 May 2024

 * Description: This program defines a Task class

 * Changes: 
    * 1. None - taken from Lab 4 template

 *******************************************************/

#ifndef TASK_H
#define TASK_H

#include <string>
#include <iostream>
#include "dateTime.h"

using namespace std;

class Task {
public:
    Task();
    ~Task();

    // friend function to allow ostream << and istream >> operators
    friend ostream& operator<<(ostream& out, const Task& task);
    friend istream& operator>>(istream& in, Task& task);

    void setTerm(string term) { this->term = term; };
    void setName(string name) { this->name = name; };
    void setStatus(int status) { this->status = status; };
    void setStartDate(string date);
    void setEndDate(string date);

    string getTerm() const { return term; };
    string getName() const { return name; };
    DateTime getStartDate() const;
    DateTime getEndDate() const;    

    bool isCompleted() const;
    bool operator >= (const Task& task) const;
    bool operator == (const Task& task) const;
    Task& operator = (const Task& task);    

private:
    string term;
    string name;
    DateTime startDate;
    DateTime endDate;
    int status;  // value =1 means DONE! and value = 0 is pending
};

#endif // TASK_H