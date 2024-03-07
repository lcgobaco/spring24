/*******************************************************

 * Program Name: list.h

 * Author: Lucas Gobaco

 * Date: 6 March 2024

 * Description: This program defines a list class and an iterator class to be used with the list class.

 *******************************************************/

#ifndef LIST_H
#define LIST_H

#include <string>

using namespace std;

template <typename T>
class List;
template <typename T>
class Iterator;

template <typename T>
class Node
{
public:
    /**
       Constructs a node with a given data value.
       @param element the data to store in this node
    */
    Node(T element);
private:
    T data;
    Node<T>* previous;
    Node<T>* next;
    friend class List<T>;
    friend class Iterator<T>;
};

template <typename T>
class List
{
public:
    /**
       Constructs an empty list.
    */
    List();
    /**
       Appends an element to the list.
       @param element the value to append
    */
    void push_back(T element);
    /**
       Inserts an element into the list.
       @param iter the position before which to insert
       @param element the value to insert
    */
    void insert(Iterator<T> iter, T element);
    /**
       Retrieves the k'th element of the list
       @param k the position to be retrieved (zero-based)
       @return the element at position k, error if no such position
    */
    T get(int k);
    /**
       Removes an element from the list.
       @param iter the position to remove
       @return an iterator pointing to the element after the
       erased element
    */
    Iterator<T> erase(Iterator<T> iter);
    /**
       Gets the beginning position of the list.
       @return an iterator pointing to the beginning of the list
    */
    Iterator<T> begin();
    /**
       Gets the past-the-end position of the list.
       @return an iterator pointing past the end of the list
    */
    Iterator<T> end();
private:
    Node<T> *first;
    Node<T> *last;
    Node<T> *last_node;
    int last_index;
    friend class Iterator<T>;
};

template <typename T>
class Iterator
{
public:
    /**
       Constructs an iterator that does not point into any list.
    */
    Iterator();
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
       Moves the iterator to the previous node.
    */
    void previous();
    /**
       Compares two iterators.
       @param other the iterator to compare with this iterator
       @return true if this iterator and other are equal
    */
    bool equals(Iterator<T> other) const;
private:
    Node<T>* position;
    List<T>* container;
    friend class List<T>;
};

#endif
