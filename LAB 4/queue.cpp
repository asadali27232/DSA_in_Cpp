#include "iostream"

using namespace std;

template<typename T>
class MyLinearQueue {
private:
    T arr[3];
    int size;
    int R;
    int F;
public:
    MyLinearQueue() {
        this->size = 3;
        this->R = -1;
        this->F = -1;
    }

    bool isEmpty() {
        if (F == -1 && R == -1)
            return true;
        else if (R < F)
            return true;
        else
            return false;
    }

    bool isFull() {
        if (F == 0 && R == size - 1)
            return true;
        else
            return false;
    }

    void insertion(T value) {
        if (R == -1 && F == -1) {
            R++;
            arr[R] = value;
            cout << "Element Inserted" << endl;
            F++;
        } else if (!isFull()) {
            R++;
            arr[R] = value;
            cout << "Element Inserted" << endl;
        } else {
            cout << "Queue is Full. Overflow Condition!" << endl;
        }
    }

    T deletion() {
        if (isEmpty()) {
            cout << "Queue is Empty. Underflow Condition! ";
            return arr[9];
        } else {
            T value = arr[F];
            if (F == size - 1) {
                F = -1;
                R = -1;
            } else
                F++;
            return value;
        }
    }

    void print() {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << "    ";
        }
        cout << endl;
    }
};

template<typename T>
class MyCircularQueue {
private:
    T arr[3];
    int size;
    int R;
    int F;
public:
    MyCircularQueue() {
        this->size = 3;
        this->R = -1;
        this->F = -1;
    }

    void insertion(T value) {
        if ((F == 0 && R == size - 1) || (R == F - 1)) {
            cout << "Queue is Full" << endl;
        } else if (R == size - 1 && F != 0) {
            R = 0;
            arr[R] = value;
        } else if (F == -1) {
            F++;
            R++;
            arr[R] = value;
        } else {
            R++;
            arr[R] = value;
        }
    }

    T deletion() {
        if (F == -1) {
            cout << "Queue is Empty! Garbage = ";
            return INT_MIN;
        }
        T element = arr[F];
        if (F == R) {
            F = -1;
            R = -1;
        } else if (F == size - 1) {
            F = 0;
        } else {
            F++;
        }
        return element;
    }

    void print() {
        if (R == -1 && F == -1) {
            cout << "Queue is Empty" << endl;
        } else if (F == 0 && R == size - 1) {
            for (int i = 0; i < size; ++i) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        if (F >= R) {
            for (int i = F; i < size; ++i) {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= R; ++i) {
                cout << arr[i] << " ";
            }
        }
        if (R >= F) {
            for (int i = R; i <= F; ++i) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    MyCircularQueue<int> queue;

    cout << "Insertion " << endl;
    queue.insertion(12);

    cout << "Insertion " << endl;
    queue.insertion(92);

    cout << "Deletion ";
    cout << queue.deletion() << endl;

    cout << "Insertion " << endl;
    queue.insertion(88);

    cout << "Insertion " << endl;
    queue.insertion(86);

    queue.print();

    cout << "Deletion ";
    cout << queue.deletion() << endl;

    cout << "Deletion ";
    cout << queue.deletion() << endl;

    cout << "Deletion ";
    cout << queue.deletion() << endl;

    cout << "Deletion ";
    cout << queue.deletion() << endl;
}