#include <iostream>
#include "searchSortAlgorithms.h"
  
using namespace std; 
 
const int SIZE = 10000; 

void fill(int list[], int size);
void copyList(int list[], int temp[], int length); 

int main() {
	int intlist[SIZE];
	int temp[SIZE];
	
	fill(intlist, SIZE);

	copyList(intlist, temp, SIZE);

	//Quick sort: The pivot is the middle element
	quickSort(intlist, SIZE);
	
	return 0;
}

void fill(int list[], int size) {
	int seed = 47;

	int multiplier = 2743;

	int addOn = 5923;

    int index = 0;

	while (index < size) {
	   list[index++] = seed;
	   seed = int(seed * multiplier + addOn);
	}

	cout << endl;
}

void copyList(int list[], int temp[], int length) {
    for (int i = 0; i < length; i++)
        temp[i] = list[i];
}