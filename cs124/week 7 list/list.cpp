/*******************************************************

 * Program Name: list.h

 * Author: Lucas Gobaco

 * Date: 6 March 2024

 * Description: This program implements a list class and an iterator class to be used with the list class.

 *******************************************************/

#include <string>
#include "list.h"

using namespace std;

template <typename T>
Node<T>::Node(T element)
{
    data = element;
    previous = nullptr;
    next = nullptr;
}

template <typename T>
List<T>::List()
{
    first = nullptr;
    last = nullptr;
    last_node = nullptr;
    last_index = -1;
}

template <typename T>
void List<T>::push_back(T element)
{
    Node<T>* new_node = new Node<T>(element);
    if (last == nullptr) // List is empty
    {
        first = new_node;
        last = new_node;
    }
    else
    {
        new_node->previous = last;
        last->next = new_node;
        last = new_node;
    }
}

template <typename T>
void List<T>::insert(Iterator<T> iter, T element)
{
    if (iter.position == nullptr)
    {
        push_back(element);
        return;
    }

    Node<T> *after = iter.position;
    Node<T> *before = after->previous;
    Node<T> *new_node = new Node<T>(element);
    new_node->previous = before;
    new_node->next = after;
    after->previous = new_node;
    if (before == nullptr) // Insert at beginning
    {
        first = new_node;
    }
    else
    {
        // Invalidate last access
        last_node = nullptr;
        last_index = -1;
        before->next = new_node;
    }
}

template <typename T>
T List<T>::get(int k)
{
    Node<T> *n;
    if (last_node != nullptr && k >= last_index)
    {
        n =  last_node;
        int t = k;
        k = k - last_index;
        last_index = t;
    }
    else
    {
        n = first;
        last_index = 0;
    }
    k--;
    while (k >= 0 && n != nullptr)
    {
        n = n->next;
        k--;
    }
    last_node = n;
    return n->data;
}

template <typename T>
Iterator<T> List<T>::erase(Iterator<T> iter)
{
    Node<T> *remove = iter.position;
    Node<T> *before = remove->previous;
    Node<T> *after = remove->next;
    if (remove == first)
    {
        first = after;
    }
    else
    {
        before->next = after;
    }
    if (remove == last)
    {
        last = before;
    }
    else
    {
        after->previous = before;
    }
    delete remove;
    Iterator<T> r;
    r.position = after;
    r.container = this;
    // Invalid last access
    last_node = nullptr;
    last_index = -1;
    return r;
}

template <typename T>
Iterator<T> List<T>::begin()
{
    Iterator<T> iter;
    iter.position = first;
    iter.container = this;
    return iter;
}

template <typename T>
Iterator<T> List<T>::end()
{
    Iterator<T> iter;
    iter.position = nullptr;
    iter.container = this;
    return iter;
}

template <typename T>
Iterator<T>::Iterator()
{
    position = nullptr;
    container = nullptr;
}

template <typename T>
T Iterator<T>::get() const
{
    return position->data;
}

template <typename T>
void Iterator<T>::next()
{
    position = position->next;
}

template <typename T>
void Iterator<T>::previous()
{
    if (position == nullptr)
    {
        position = container->last;
    }
    else
    {
        position = position->previous;
    }
}

template <typename T>
bool Iterator<T>::equals(Iterator other) const
{
    return position == other.position;
}