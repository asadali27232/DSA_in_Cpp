#include "iostream"
#include "DynamicArray.h"

using namespace std;

template<typename T>
DynamicArray<T>::DynamicArray() {
    tSize = 10;
    size = 0;
    Array = new T[this->size];
}

template<typename T>
void DynamicArray<T>::printArray() {
    cout << "[ ";
    for (int i = 0; i < size; ++i) {
        cout << Array[i] << " ";
    }
    cout << "]";
}
