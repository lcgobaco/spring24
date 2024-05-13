/*******************************************************

 * Program Name: ArrayList.cpp

 * Author: Lucas Gobaco

 * Date: 9 March 2024

 * Description: This program implements a class manages an array list.

 *******************************************************/

#include "ArrayList.h"
#include <stdexcept> // for std::out_of_range

template <typename T>
ArrayList<T>::ArrayList() : capacity(INITIAL_CAPACITY), array_size(0) {
    elements = new T[capacity];
}

template <typename T>
ArrayList<T>::~ArrayList() {
    delete[] elements;
}

template <typename T>
void ArrayList<T>::add(const T& element) {
    if (array_size == capacity) {
        resize();
    }
    elements[array_size] = element;
    array_size++;
}

template <typename T>
T& ArrayList<T>::get(int index) {
    if (index < 0 || index >= array_size) {
        throw std::out_of_range("Index out of range");
    }
    return elements[index];
}

template <typename T>
void ArrayList<T>::set(int index, const T& element) {
    if (index < 0 || index >= array_size) {
        throw std::out_of_range("Index out of range");
    }
    elements[index] = element;
}

template <typename T>
int ArrayList<T>::size() const {
    return array_size;
}

template <typename T>
void ArrayList<T>::clear() {
    array_size = 0;
}

template <typename T>
T& ArrayList<T>::operator[](int index) {
    if (index < 0 || index >= array_size) {
        throw std::out_of_range("Index out of range");
    }
    return elements[index];
}

template <typename T>
void ArrayList<T>::remove(int index) {
    if (index < 0 || index >= array_size) {
        throw std::out_of_range("Index out of range");
    }
    for (int i = index; i < array_size - 1; ++i) {
        elements[i] = elements[i + 1];
    }
    array_size--;
}

template <typename T>
void ArrayList<T>::resize() {
    capacity *= 2;
    T* newElements = new T[capacity];
    for (int i = 0; i < array_size; ++i) {
        newElements[i] = elements[i];
    }
    delete[] elements;
    elements = newElements;
}

template <typename T>
const int ArrayList<T>::INITIAL_CAPACITY;
