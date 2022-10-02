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
        for (int i = size - 1; i >= index; --i) {
            Array[i + 1] = Array[i];
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

template<typename T>
void DynamicArray<T>::removeAt(int index) {
    if (index < size) {
        for (int i = index; i < size; ++i) {
            Array[i] = Array[i + 1];
        }
        --size;
    } else
        cout << "Index out of bound!" << endl;
}

template<typename T>
void DynamicArray<T>::remove(T element) {
    if (search(element) > -1)
        removeAt(search(element));
    else
        cout << "Element not Found!" << endl;
}

template<typename T>
void DynamicArray<T>::sort() {
    // loop to access each array element
    for (int step = 0; step < size - 1; ++step) {
        // check if swapping occurs
        int swapped = 0;

        // loop to compare array elements
        for (int i = 0; i < (size - 1) - step; ++i) {
            // compare two adjacent elements
            // change > to < to sort in descending order
            if (Array[i] > Array[i + 1]) {

                // swapping elements if elements
                // are not in the intended order
                T temp = Array[i];
                Array[i] = Array[i + 1];
                Array[i + 1] = temp;

                swapped = 1;
            }
        }
        // no swapping means the array is already sorted
        // so no need of further comparison
        if (swapped == 0)
            break;
    }
}

template<typename T>
int DynamicArray<T>::search(T element) {
    sort();
    int low, mid, high;

    low = 0;
    high = size - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        if (Array[mid] == element)
            return mid;
        if (Array[mid] < element)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}