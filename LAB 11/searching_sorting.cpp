#include<iostream>

using namespace std;

void cpyArr(int sourceArr[], int destArr[], int size);

void selectionSort(int arr[], int size);

void printArr(int arr[], int size);

int main() {
    int arr[20] = {11, 33, 44, 56, 87, 94, 23, 65, 78, 23, 42};
    int size = 11;

    cout << "Given Array: ";
    printArr(arr, size);
    cout << endl;

    selectionSort(arr, size);


    return 0;
}

// Copy Array
void cpyArr(int sourceArr[], int destArr[], int size) {
    for (int i = 0; i < size; i++) {
        destArr[i] = sourceArr[i];
    }
}

// Print Array
void printArr(int arr[], int size) {
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

void selectionSort(int arr[], int size) {

    int newArray[size];
    cpyArr(arr, newArray, size);

    for (int i = 0; i < size; ++i) {
        int smallest = arr[i];
        int smallestIndex = i;

        for (int j = i + 1; j < size; j++) {
            if (newArray[j] < smallest) {
                smallest = newArray[j];
                smallestIndex = j;
            }
        }
        newArray[smallestIndex] = newArray[i];
        newArray[i] = smallest;
    }
    cout << "Sorted by Selection Sort: ";
    printArr(newArray, size);
    cout << endl;
}