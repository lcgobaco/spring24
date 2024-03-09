#include "ArrayList.h"

template <typename T>
ArrayList<T>::ArrayList() {}

template <typename T>
ArrayList<T>::~ArrayList() {}

template <typename T>
void ArrayList<T>::add(const T& element) {
    elements.push_back(element);
}

template <typename T>
T& ArrayList<T>::get(int index) {
    return elements[index];
}

template <typename T>
int ArrayList<T>::size() const {
    return elements.size();
}

template <typename T>
void ArrayList<T>::clear() {
    elements.clear();
}

template <typename T>
T& ArrayList<T>::operator[](int index) {
    return elements[index];
}
