#include "Stack.h"
#include "iostream"

using namespace std;

template<typename T>
Stack<T>::Stack(int size) {
    this->size = size;
    this->TOP = -1;
    this->stack = new T[this->size];
}

template<typename T>
Stack<T>::~Stack() {
    delete stack;
}

template<typename T>
int Stack<T>::getTOP() {
    return TOP;
}

template<typename T>
void Stack<T>::print() {
    if (isEmpty()) {
        cout << "Empty Stack!" << endl;
    } else {
        for (int i = TOP; i >= 0; --i) {
            cout << stack[i] << " ";
        }
    }
}

template<typename T>
void Stack<T>::push(T element) {
    if (isFull()) {
        cout << "OverFlow Condition i.e Stack is Full." << endl;
    } else {
        TOP += 1;
        stack[TOP] = element;
    }
}

template<typename T>
T Stack<T>::pop() {
    if (!isEmpty()) {
        TOP -= 1;
        return stack[TOP + 1];
    }
    cout << "UnderFlow Condition i.e Stack is Empty." << endl;
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
