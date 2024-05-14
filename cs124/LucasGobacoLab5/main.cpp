/*******************************************************

 * Program Name: main.cpp

 * Author: Lucas Gobaco

 * Date: 22 April 2024

 * Description: This program contains the main function to test the classes.

 *******************************************************/

#include <iostream>
#include "faculty.h"
#include "section.h"
#include "group.h"
#include "assignment.h"

int main() {
   Faculty bnguyen("bnguyen", "Bob", "Nguyen", "CNET", "39399 Cherry St", "Fremont", "CA", "94538", "pnguyen@ohlone.edu", "510-742-2300");
   Faculty dtopham("dtopham", "David", "Topham", "CS", "43600 Mission Blvd.", "Fremont", "CA", "94538", "dtopham@ohlone.edu", "510-659-6000");
   Faculty jpham("jpham", "Jim", "Pham", "CS", "39399 Cherry St", "Neward", "CA", "94560", "jpham@ohlone.edu", "510-742-2300");
   Faculty rsha("rsha", "Ron", "Sha", "CNET", "39399 Cherry St", "Fremont", "CA", "94538", "rsha@ohlone.edu", "510-742-2300");
   Faculty schenhansa("schenhansa", "Suporn", "Chenhansa", "CS", "43600 Mission Blvd.", "Fremont", "CA", "94538", "schenhansa@ohlone.edu", "510-659-6000");
   Faculty imalik("imalik", "I", "Malik", "CS", "43600 Mission Blvd.", "Fremont", "CA", "94538", "imalik@ohlone.edu", "510-659-6000");
   Section section1("Spring 2024", "CS-124-01", "Programming W/ Data Structures", 3, &jpham);
   Section section2("Spring 2024", "CS-124-03", "Programming W/ Data Structures", 3, &jpham);
   Group group(1, &section1, "Group 1", 50.0);
   Assignment assignment(1, &group, "Assignment 1", "Description of assignment 1", 100.0);

    return 0;
}
