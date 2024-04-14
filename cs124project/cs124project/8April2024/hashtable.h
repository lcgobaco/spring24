/*******************************************************

 * Program Name: hashtable.h

 * Author: Lucas Gobaco

 * Date: 8 April 2024

 * Description: This program defines a hash table class and an iterator class.

 *******************************************************/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <vector>

using namespace std; 

/**
   Computes the hash code for a string.
   @param str a string
   @return the hash code
*/
int hash_code(const string& str);

template<typename T>
class HashTable;
template<typename T>
class Iterator;

template<typename T>
class Node
{
private:
   T data;
   Node<T>* next;

friend class HashTable<T>;
friend class Iterator<T>;
};

template<typename T>
class Iterator
{
public:
   /**  
      Looks up the value at a position.
      @return the value of the node to which the iterator points
   */
   T get() const;
   /**
      Advances the iterator to the next node.
   */
   void next();
   /**
      Compares two iterators.
      @param other the iterator to compare with this iterator
      @return true if this iterator and other are equal
   */
   bool equals(const Iterator& other) const;
private:
   const HashTable<T>* container;
   int bucket_index;
   Node<T>* current;
   
friend class HashTable<T>;
};

/**
   This class implements a hash table using separate chaining.
*/
template<typename T>
class HashTable
{
public:
   /**
      Constructs an empty hash table.
   */
   HashTable() : HashTable(10) {}

   /**
      Constructs a hash table.
      @param nbuckets the number of buckets
   */
   HashTable(int nbuckets);

   /**
      Tests for set membership.
      @param x the potential element to test
      @return 1 if x is an element of this set, 0 otherwise
   */
   int count(const T& x);

   /**
      Adds an element to this hash table if it is not already present.
      @param x the element to add
   */
   void insert(const T& x);

   /**
      Removes an element from this hash table if it is present.
      @param x the potential element to remove
   */
   void erase(const T& x);

   /**
      Returns an iterator to the beginning of this hash table.
      @return a hash table iterator to the beginning
   */
   Iterator<T> begin() const;

   /**
      Returns an iterator past the end of this hash table.
      @return a hash table iterator past the end
   */
   Iterator<T> end() const;

   /**
      Gets the number of elements in this set.
      @return the number of elements
   */
   int size() const;

private:
   vector<Node<T>*> buckets;
   int current_size;   

friend class Iterator<T>;
};

#endif