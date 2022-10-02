#include<iostream>
#include "DynamicArray.h"
#include "DynamicArray.cpp"

using namespace std;

void multiplyMatrix();

void transpose();

void student();

struct Student {
    int id;
    string name;
    int semester;
    string course;
    double cgpa;
};

char garbage;

int main() {
//    multiplyMatrix();
//    transpose();
//    student();
    DynamicArray<int> dynamicArray;
    dynamicArray.add(30);
    dynamicArray.add(100);
    dynamicArray.add(0, 45);
    dynamicArray.add(200, 75);
    dynamicArray.add(500);
    dynamicArray.add(100, 85);

    dynamicArray.printArray();
    dynamicArray.sort();

    cout << endl;
    dynamicArray.printArray();
    cout << endl << "Element Found At: " << dynamicArray.search(85) << endl;

    dynamicArray.remove(85);
    dynamicArray.remove(1000);
    dynamicArray.removeAt(0);
    dynamicArray.removeAt(100);

    cout << endl;
    dynamicArray.printArray();

    return 0;
}

void multiplyMatrix() {
    int rowA = 0;
    int colA = 0;

    cout << "Enter TOP of Matrix A:";
    cin >> rowA >> colA;
    double matrixA[rowA][colA];

    cout << "Enter values for Matrix A:";
    for (int i = 0; i < rowA; ++i) {
        for (int j = 0; j < colA; ++j) {
            cin >> matrixA[i][j];
        }

    }

    int rowB = 0;
    int colB = 0;

    cout << "Enter TOP of Matrix B:";
    cin >> rowB >> colB;
    int matrixB[rowB][colB];

    cout << "Enter values for Matrix B:";
    for (int i = 0; i < rowB; ++i) {
        for (int j = 0; j < colB; ++j) {
            cin >> matrixB[i][j];
        }
    }

    double matrixResult[colA][rowB];
    for (int i = 0; i < colA; ++i) {
        for (int j = 0; j < rowB; ++j) {
            matrixResult[i][j] = 0;
        }
    }

    cout << "Matrix A:" << endl;
    for (int i = 0; i < rowA; ++i) {
        for (int j = 0; j < colA; ++j) {
            cout << matrixA[i][j] << "  ";
        }
        cout << endl;
    }
    cout << "Matrix B:" << endl;
    for (int i = 0; i < rowB; ++i) {
        for (int j = 0; j < colB; ++j) {
            cout << matrixB[i][j] << "  ";
        }
        cout << endl;
    }
    if (rowA == colB) {
        for (int i = 0; i < rowA; ++i)
            for (int j = 0; j < colB; ++j)
                for (int k = 0; k < colA; ++k) {
                    matrixResult[i][j] += matrixA[i][k] * matrixB[k][j];
                }
        cout << "Multiplication of two given matrices is:" << endl;
        for (int i = 0; i < colA; ++i) {
            for (int j = 0; j < rowB; ++j) {
                cout << matrixResult[i][j] << "  ";
            }
            cout << endl;
        }
    } else
        cout << "Multiplication is not possible." << endl;
}

void transpose() {
    int rowA = 0;
    int colA = 0;

    cout << "Enter TOP of Matrix A:";
    cin >> rowA >> colA;
    double matrixA[rowA][colA];

    cout << "Enter values for Matrix A:";
    for (int i = 0; i < rowA; ++i) {
        for (int j = 0; j < colA; ++j) {
            cin >> matrixA[i][j];
        }

    }
    cout << "Matrix A:" << endl;
    for (int i = 0; i < rowA; ++i) {
        for (int j = 0; j < colA; ++j) {
            cout << matrixA[i][j] << "  ";
        }
        cout << endl;
    }

    double matrixResult[colA][rowA];
    for (int i = 0; i < colA; ++i) {
        for (int j = 0; j < rowA; ++j) {
            matrixResult[i][j] = 0;
        }
    }

    for (int i = 0; i < rowA; ++i) {
        for (int j = 0; j < colA; ++j) {
            matrixResult[j][i] = matrixA[i][j];
        }
    }

    cout << "Transpose of given matrix is:" << endl;
    for (int i = 0; i < colA; ++i) {
        for (int j = 0; j < rowA; ++j) {
            cout << matrixResult[i][j] << "  ";
        }
        cout << endl;
    }
}

void student() {
    Student students[3];
    for (int i = 0; i < 3; ++i) {
        cout << "Enter Student ID:";
        cin >> students[i].id;
        cin.get(garbage);
        cout << "Enter Student Name:";
        getline(cin, students[i].name);
        cout << "Enter Student Semester:";
        cin >> students[i].semester;
        cin.get(garbage);
        cout << "Enter Student Course:";
        getline(cin, students[i].course);
        cout << "Enter Student CGPA:";
        cin >> students[i].cgpa;
        cout << endl;
    }
    for (int i = 0; i < 3; ++i) {
        if (students[i].course == "DSA" && students[i].cgpa > 3.0) {
            cout << "ID: " << students->id << endl;
            cout << "Name :" << students->name << endl;
            cout << "Semester :" << students->semester << endl;
            cout << "Course :" << students->course << endl;
            cout << "CGPA: " << students->cgpa << endl;
        }

    }
}