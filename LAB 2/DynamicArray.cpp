#include "iostream"
#include "DynamicArray.h"

using namespace std;

template<typename T>
DynamicArray<T>::DynamicArray() {
    tSize = 10;
    this->size = 0;
    this->Array = new T[this->tSize];
}

template<typename T>
DynamicArray<T>::~DynamicArray() {
    delete Array;
}

template<typename T>
int DynamicArray<T>::getSize() {
    return size;
}

template<typename T>
void DynamicArray<T>::printArray() {
    cout << "[ ";
    for (int i = 0; i < size; ++i) {
        cout << this->Array[i] << " ";
    }
    cout << "]";
}

template<typename T>
void DynamicArray<T>::add(T element) {
    if (size == tSize) {
        doubleArray();
    }
    Array[size] = element;
    ++size;
}

template<typename T>
void DynamicArray<T>::add(int index, T element) {
    if (size >= tSize) {
        doubleArray();
    }
    if (index >= size) {
        Array[size] = element;
        ++size;
    } else {
        for (int i = size-1; i >= index; --i) {
            Array[i+1] = Array[i];
        }
        ++size;
        Array[index] = element;
    }
}

template<typename T>
void DynamicArray<T>::doubleArray() {
    tSize *= 2;
    T *newArray = new T[this->tSize];
    for (int i = 0; i < size; ++i) {
        newArray[i] = Array[i];
    }
    delete Array;
    Array = newArray;
}
