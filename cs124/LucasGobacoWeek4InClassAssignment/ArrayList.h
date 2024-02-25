/*******************************************************

 * Program Name: ArrayList.h

 * Author: Lucas Gobaco

 * Date: 14 February 2024

 * Description: This program defines a class that implements a 

 *******************************************************/

template <typename T> 
class ArrayList
{
public:
    //Constructor
    //Creates an array of the size specified by the 
    //parameter size. The default array size is 100.
    //Postcondition: The list points to the array, length = 0,
    //               and maxSize = size;
    ArrayListType(int size = 100);
      
    
    //Destructor
    //Deallocate the memory occupied by the array.
    ~ArrayListType();

    //Function to determine whether the list is empty
    //Postcondition: Returns true if the list is empty;
    //               otherwise, returns false.
    bool isEmpty() const;
      
    //Function to determine whether the list is full
    //Postcondition: Returns true if the list is full; 
    //               otherwise, returns false.
    bool isFull() const;
      
    //Function to output the elements of the list
    //Postcondition: Elements of the list are output on the 
    //               standard output device.
    void print() const;
      
      
    //Function to insert insertItem an item at the end of 
    //the list. Note that this is an abstract function.
    //Postcondition: list[length] = insertItem; and length++;
    //               If the list is full, an appropriate 
    //               message is displayed.
    virtual void insert(const T& insertItem);
      
    //Function to retrieve the element from the list at the  
    //position specified by location 
    //Postcondition: retItem = list[location] 
    //               If location is out of range, an 
    //               appropriate message is displayed.
    void retrieve(int location, T& retItem) const;
      
    //Function to search the list for searchItem.
    //Note that this is an abstract function.
    //Postcondition: If the item is found, returns the 
    //               location in the array where the item is  
    //               found; otherwise, returns -1.
    virtual int search(const T& searchItem);
      
    //Function to remove removeItem from the list.
    //Note that this is an abstract function.
    //Postcondition: If removeItem is found in the list,
    //               it is removed from the list and length 
    //               is decremented by one.
    virtual void remove(const T& removeItem);
      
protected:
    T *list; //array to hold the list elements
    int length;     //variable to store the length of the list
    int maxSize;    //variable to store the maximum 
                    //size of the list
};