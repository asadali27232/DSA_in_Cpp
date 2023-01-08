#include<iostream>
#include <algorithm>

using namespace std;
const int size = 20;

// Utility functions
void cpyArr(const int sourceArr[], int destArr[]) {
    for (int i = 0; i < size; i++) {
        destArr[i] = sourceArr[i];
    }
}

void printArr(int arr[]) {
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
    cout << endl;
}

// Searching Functions
void linearSearch(const int arr[], int key) {
    cout << "linear Search:" << endl;

    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            cout << "Key: " << key << " founded in array at index: " << i << endl;
            return;
        }
    }
    cout << "Key: " << key << " not founded in array!" << endl;
}

void binarySearch(const int arr[], int key) {
    cout << "Binary Search:" << endl;

    int newArray[size];
    cpyArr(arr, newArray);

    // Selection Sort
    for (int i = 0; i < size; ++i) {
        int smallestElement = newArray[i];
        int smallestIndex = i;

        for (int j = i + 1; j < size; ++j) {
            if (newArray[j] < smallestElement) {
                smallestElement = newArray[j];
                smallestIndex = j;
            }
        }
        newArray[smallestIndex] = newArray[i];
        newArray[i] = smallestElement;
    }

    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (key == newArray[mid]) {
            cout << "Key: " << key << " founded in array at index: " << mid << endl;
            return;
        } else if (key < newArray[mid]) {
            high = mid - 1;
            continue;
        } else if (key > newArray[mid]) {
            low = mid + 1;
            continue;
        }
    }
    cout << "Key: " << key << " not founded in array!" << endl;
}

// Sorting Functions
void bubbleSort(int arr[]) {
    int newArray[size];
    cpyArr(arr, newArray);

    for (int i = 0; i < size - 1; ++i) {
        int temp;
        bool isSorted = true;

        for (int j = 0; j < size - 1 - i; ++j) {
            if (newArray[j] > newArray[j + 1]) {
                isSorted = false;
                temp = newArray[j];
                newArray[j] = newArray[j + 1];
                newArray[j + 1] = temp;
            }
        }
        if (isSorted) {
            break;
        }
    }
    cout << "Sorted by Bubble Sort: ";
    printArr(newArray);
}

void selectionSort(const int arr[]) {

    int newArray[size];
    cpyArr(arr, newArray);

    for (int i = 0; i < size; ++i) {
        int smallest = newArray[i];
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
    printArr(newArray);
}

void insertionSort(const int arr[]) {
    int newArray[size];
    cpyArr(arr, newArray);

    for (int i = 1; i < size; ++i) {
        int key = newArray[i];
        int j = i - 1;

        while (j >= 0 && key < newArray[j]) {
            newArray[j + 1] = newArray[j];
            --j;
        }
        newArray[j + 1] = key;
    }
    cout << "Sorted by Insertion Sort: ";
    printArr(newArray);
}

void quickSort(int arr[], int low, int high) {
    if (high <= low) {
        return;
    }
    int pivot = low;
    int i = low + 1;
    int j = high;
    int temp;

    do {
        while (arr[i] <= arr[pivot]) // Find the index of element greater than pivot
            i++; // Otherwise move forward
        while (arr[j] > arr[pivot]) // Find the index of element smaller or equal to pivot
            j--; // Otherwise move backwards

        if (i < j) { // When we found greater than pivot and smaller or equal to pivot at i and j respectively
            temp = arr[i]; // Then swap i and j
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i <= j);

    temp = arr[pivot]; // j becomes less than i, swap pivot and j
    arr[pivot] = arr[j];
    arr[j] = temp;
    pivot = j;

    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);

}

void merge(int arr[], int low, int mid, int high) {
    int i, j, k;
    i = low;
    j = mid + 1;
    k = low;
    int newArray[size];

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            newArray[k] = arr[i];
            i++;
            k++;
        } else {
            newArray[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid) {
        newArray[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high) {
        newArray[k] = arr[j];
        j++;
        k++;
    }
    for (i = low; i <= high; i++) {
        arr[i] = newArray[i];
    }
}

void mergeSort(int arr[], int low, int high) {
    if (high <= low) {
        return;
    }
    int mid = (low + high) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main() {
    int arr[size] = {5, 14, 8, 3, 15,
                     12, 9, 2, 1, 6,
                     4, 11, 13, 7, 10,
                     15, 5, 8, 1, 3};

    int choice = 0;
    do {
        cout << endl << "Given Array: ";
        printArr(arr);

        cout << "What you want me to do:" << endl;
        cout << "1. Searching" << endl;
        cout << "2. Sorting" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice:";
        cin >> choice;

        if (choice == 1) {
            int searchChoice = 0;
            cout << endl << "Searching Given Array:" << endl;
            cout << "1. For Linear Search" << endl;
            cout << "2. For Binary Search" << endl;
            cout << "Enter your choice:";
            cin >> searchChoice;

            int key;
            cout << "Enter Key:";
            cin >> key;

            if (searchChoice == 1) {
                linearSearch(arr, key);
            } else if (searchChoice == 2) {
                binarySearch(arr, key);
            } else {
                cout << "ERROR: Unknown Choice" << endl;
            }
        } else if (choice == 2) {
            int sortingChoice = 0;
            cout << endl << "Sorting Given Array:" << endl;
            cout << "1. For Bubble Sort" << endl;
            cout << "2. For Selection Sort" << endl;
            cout << "3. For Insertion Sort" << endl;
            cout << "4. For Quick Sort" << endl;
            cout << "5. For Merge Sort" << endl;
            cout << "Enter your choice:";
            cin >> sortingChoice;

            if (sortingChoice == 1) {
                bubbleSort(arr);
            } else if (sortingChoice == 2) {
                selectionSort(arr);
            } else if (sortingChoice == 3) {
                insertionSort(arr);
            } else if (sortingChoice == 4) {
                int newArray[size];
                cpyArr(arr, newArray);

                quickSort(newArray, 0, size - 1);

                cout << "Sorted by Quick Sort: ";
                printArr(newArray);
            } else if (sortingChoice == 5) {
                int newArray[size];
                cpyArr(arr, newArray);

                mergeSort(newArray, 0, size - 1);

                cout << "Sorted by Merge Sort: ";
                printArr(newArray);
            } else {
                cout << "ERROR: Unknown Choice" << endl;
            }
        } else if (choice == 3) {
            exit(0);
        }
    } while (choice != 3);

    return 0;
}


