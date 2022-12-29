#include<iostream>
#include <iomanip>

using namespace std;

// My Stack ADT Class
template<typename T>
class Stack {
private:
    int TOP{};
    int size{};
    T *stack;
public:
    explicit Stack(int size);

    ~Stack();

    int getTOP();

    void setTop(int top);

    void print();

    void push(T element);

    T pop();

    T peek(int index);

    bool equals(Stack<T> savedWinSate);

    bool isEmpty();

    bool isFull();
};

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
void Stack<T>::setTop(int top) {
    this->TOP = top;
}

template<typename T>
void Stack<T>::print() {
    if (isEmpty()) {
        cout << "Empty Stack!" << endl;
    } else {
        for (int i = TOP; i >= 0; --i) {
            cout << stack[i];
        }
    }
}

template<typename T>
void Stack<T>::push(T element) {
    TOP += 1;
    stack[TOP] = element;
}

template<typename T>
T Stack<T>::pop() {
    TOP -= 1;
    return stack[TOP + 1];
}

template<typename T>
bool Stack<T>::isEmpty() {
    if (TOP <= 0)
        return true;
    else
        return false;
}

template<typename T>
bool Stack<T>::isFull() {
    if (TOP < size)
        return false;
    else
        return true;
}

template<typename T>
T Stack<T>::peek(int index) {
    T temp = stack[index];
    return temp;
}

template<typename T>
bool Stack<T>::equals(Stack<T> savedWinSate) {
    bool isEqual = false;
    for (int i = 0; i < size - 1; ++i) {
        if (this->stack[i] == savedWinSate.stack[i])
            isEqual = true;
        else {
            isEqual = false;
            return isEqual;
        }
    }
    return isEqual;
}

//---------------------------------------------------------------------------------------------
void printStacks(Stack<int> &startStack, Stack<int> &middleStack, Stack<int> &winStack, int numberOfDisk);

int main() {
    int numberOfDisk = 0;

    cout << endl << "-----------------Tower of Hanoi-----------------" << endl << endl;
    cout << "How many disks you want to use (1-9):";
    cin >> numberOfDisk;

    while (numberOfDisk >= 10) {
        cout << "Disk should be less then 10. Enter number of Disk (1-9):";
        cin >> numberOfDisk;
    }

    Stack<int> startStack(numberOfDisk);
    Stack<int> middleStack(numberOfDisk);
    Stack<int> winStack(numberOfDisk);

    for (int i = 0; i < numberOfDisk; ++i) {
        int randomInteger = 1 + rand() % 9;

        startStack.push(randomInteger);

        middleStack.push(0);
        winStack.push(0);
    }
    middleStack.setTop(0);
    winStack.setTop(0);

//    Stack<int> savedWinState(numberOfDisk);
//    savedWinState = startStack;

    printStacks(startStack, middleStack, winStack, numberOfDisk);
    cout << endl << "'0' means EMPTY SPACE to play your move...!" << endl;

    // Playing
    while (true) {
        cout << endl << "DEFINE YOUR MOVE" << endl;
        cout << "Start Rod = 1 Middle Rod = 2 Win Rod = 3" << endl;
        cout << "From which Rod where you want to move?" << endl;
        cout << "[1 2] means you want to move from Rod-1 to Rod-2...!" << endl;
        cout << "ENTER YOUR MOVE:";

        int moveFrom, moveTo;
        cin >> moveFrom >> moveTo;
        cout << middleStack.isFull() << endl;
        if (moveFrom == 1 && moveTo == 2 && !middleStack.isFull()) {
            int startDisk = startStack.pop();
            int midDisk = middleStack.pop();

            cout << startDisk << endl;
            cout << midDisk << endl;

            if (startDisk < midDisk || midDisk == 0) {
                startStack.push(0);
                startStack.setTop(startStack.getTOP() - 1);
                cout << "gdfgg" << middleStack.isEmpty() << endl;
                cout << "lll" << middleStack.getTOP();
                middleStack.push(midDisk);
                middleStack.push(startDisk);
                cout << "Move Done. Congrats!" << endl;
            } else {
                startStack.push(startDisk);
                middleStack.push(midDisk);
                cout << "Can NOT move!" << endl;
            }
            middleStack.print();
        }
        if (moveFrom == 1 && moveTo == 3) {

        }
        if (moveFrom == 2 && moveTo == 1) {

        }
        if (moveFrom == 2 && moveTo == 3) {

        }
        if (moveFrom == 3 && moveTo == 1) {

        }
        if (moveFrom == 3 && moveTo == 2) {

        }
        printStacks(startStack, middleStack, winStack, numberOfDisk);
    }

    return 0;
}

void printStacks(Stack<int> &startStack, Stack<int> &middleStack, Stack<int> &winStack, int numberOfDisk) {
    cout << endl << "-----------------Tower of Hanoi-----------------" << endl << endl;
    cout << setw(0) << setfill(' ') << " "
         << setw(20) << setfill(' ') << left << "Start Rod"
         << setw(20) << setfill(' ') << left << "Middle Rod"
         << setw(20) << setfill(' ') << left << "Win Rod"
         << endl;

    for (int i = numberOfDisk - 1; i >= 0; --i) {
        cout << setw(5) << setfill(' ') << " "
             << setw(20) << setfill(' ') << startStack.peek(i)
             << setw(20) << setfill(' ') << middleStack.peek(i)
             << setw(20) << setfill(' ') << winStack.peek(i)
             << endl;
    }


}