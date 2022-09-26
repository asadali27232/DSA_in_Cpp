//
// Created by asada on 9/26/2022.
//
#include "iostream"
#include "Stack.h"

using namespace std;

template<typename T>
Stack<T>::Stack(int size) {
    this->size = size;
    this->TOP = -1;
    stack = new T[this->size];
}

template<typename T>
void Stack<T>::print() {
    if (isEmpty()) {
        cout << "Empty Stack!" << endl;
    }
    else {
        cout << "Stack" << endl;
        for (int i = TOP; i >= 0; --i) {
            cout << stack[i] << endl;
        }
    }
}

template<typename T>
void Stack<T>::push(T element) {
    if (isFull()) {
        cout << "OverFlow Condition i.e Stack is Full." << endl;
    } else {
        stack[++TOP] = element;
        cout << "Element Pushed!" << endl;
    }
}

template<typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        cout << "UnderFlow Condition i.e Stack is Empty." << endl;
    } else {
        cout << "Element Pop!" << endl;
        return stack[TOP--];
    }
}

template<typename T>
bool Stack<T>::isEmpty() {
    if (TOP < 0)
        return true;
    else
        return false;
}

template<typename T>
bool Stack<T>::isFull() {
    if (TOP >= size)
        return true;
    else
        return false;
}

