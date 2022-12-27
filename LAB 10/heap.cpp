#include<iostream>

using namespace std;

#include "Stack.h"
#include "Stack.cpp"

Stack<int> sortedStack(100);

// To shiftDown a subtree rooted with node i which is
// an index of arr[] and n is the size of heap
void shiftDown(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        shiftDown(arr, n, largest);
    }
}

void shiftUp(int arr[], int n, int i) {
    // Find parent
    int parent = (i - 1) / 2;

    if (arr[parent] > 0) {
        // For Max-Heap
        // If current node is greater than its parent
        // Swap both of them and call shiftUp again
        // for the parent
        if (arr[i] > arr[parent]) {
            swap(arr[i], arr[parent]);

            // Recursively shiftUp the parent node
            shiftUp(arr, n, parent);
        }
    }
}

// Function to insert a new node to the Heap
void insertNode(int arr[], int &n, int Key) {
    // Increase the size of Heap by 1
    n = n + 1;

    // Insert the element at end of Heap
    arr[n - 1] = Key;

    // Heapify the new node following a
    // Bottom-up approach
    shiftUp(arr, n, n - 1);
}

// Function to delete the root from Heap
void deleteRoot(int arr[], int &n) {
    // Get the last element
    int lastElement = arr[n - 1];

    // Replace root with last element
    sortedStack.push(arr[0]);
    arr[0] = lastElement;

    // Decrease size of heap by 1
    n = n - 1;

    // shiftDown the root node
    shiftDown(arr, n, 0);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

void heapSort(int arr[], int &n) {
    int size = n;
    for (int i = 0; i < size; ++i)
        deleteRoot(arr, n);
}

int main() {
    int arr[100];
    int n = 0;
    int userSize;

    cout << "Enter size of Heap:";
    cin >> userSize;

    for (int i = 0; i < userSize; i++) {
        int key;
        cout << "Enter " << i + 1 << " Element of Heap:";
        cin >> key;
        insertNode(arr, n, key);
    }
    cout << "Heap Tree from given Numbers:" << endl;
    printArray(arr, n);

    heapSort(arr, n);
    cout << "Sorted values using Heap Sort:" << endl;
    sortedStack.print();

    return 0;
}
