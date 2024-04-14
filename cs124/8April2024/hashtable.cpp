/*******************************************************

 * Program Name: hashtable.cpp

 * Author: Lucas Gobaco

 * Date: 8 April 2024

 * Description: This program implements a hash table class and an iterator class.

 *******************************************************/

#include "hashtable.h"

int hash_code(const string& str)
{
   int h = 0;
   for (int i = 0; i < str.length(); i++)
   {
      h = 31 * h + str[i];
   }
   return h;
}

template<typename T>
HashTable<T>::HashTable(int nbuckets)
{
   for (int i = 0; i < nbuckets; i++)
   {
      buckets.push_back(nullptr);
   }
   current_size = 0;
}

template<typename T>
int HashTable<T>::count(const T& x)
{
   int h = hash_code(x);
   h = h % buckets.size();
   if (h < 0) { h = -h; }
      
   Node<T>* current = buckets[h];
   while (current != nullptr)
   {
      if (current->data == x) { return 1; }
      current = current->next;
   }
   return 0;
}

template<typename T>
void HashTable<T>::insert(const T& x)
{
   int h = hash_code(x);
   h = h % buckets.size();
   if (h < 0) { h = -h; }
      
   Node<T>* current = buckets[h];
   while (current != nullptr)
   {
      if (current-> data == x) { return; }
         // Already in the set
      current = current->next;
   }
   Node<T>* new_node = new Node<T>;
   new_node->data = x;
   new_node->next = buckets[h];
   buckets[h] = new_node;
   current_size++;
}

template<typename T>
void HashTable<T>::erase(const T& x)
{
   int h = hash_code(x);
   h = h % buckets.size();
   if (h < 0) { 
       h = -h; 
   }
      
   Node<T>* current = buckets[h];
   Node<T>* previous = nullptr;
   while (current != nullptr)
   {
      if (current->data == x) 
      {
         if (previous == nullptr)
         {
            buckets[h] = current->next;
         }
         else
         {
            previous->next = current->next;
         }
         delete current;
         current_size--;
         return;
      }
      previous = current;
      current = current->next;
   }
}

template<typename T>
int HashTable<T>::size() const
{
   return current_size;
}

template<typename T>
Iterator<T> HashTable<T>::begin() const
{
   Iterator<T> iter;
   iter.current = nullptr;
   iter.bucket_index = -1;
   iter.container = this;
   iter.next();
   return iter;
}

template<typename T>
Iterator<T> HashTable<T>::end() const
{
   Iterator<T> iter;
   iter.current = nullptr;
   iter.bucket_index = (int) buckets.size();
   iter.container = this;
   return iter;
}

template<typename T>
T Iterator<T>::get() const
{
   return current->data;
}

template<typename T>
bool Iterator<T>::equals(const Iterator& other) const
{
   return current == other.current;
}

template<typename T>
void Iterator<T>::next()
{
   if (bucket_index >= 0 && current->next != nullptr)
   {
      // Advance in the same bucket
      current = current->next;
   }   
   else 
   {
      // Move to the next bucket
      do
      {
         bucket_index++;
      }
      while (bucket_index < container->buckets.size()
         && container->buckets[bucket_index] == nullptr);
      if (bucket_index < container->buckets.size())
      {
         // Start of next bucket
         current = container->buckets[bucket_index];         
      }
      else 
      {
         // No more buckets
         current = nullptr;
      }
   }
}