#include "iostream"

using namespace std;

struct node {
    int info;
    node *next;
};
node *list = NULL;

void insertStart(int infoValue) {
    node *p;
    if (list == NULL) {
        p = new node;
        p->info = infoValue;
        cout << "Inserted Value :" << p->info << endl;
        p->next = NULL;
        list = p;
    } else {
        p = new node;
        p->info = infoValue;
        cout << "Inserted Value :" << p->info << endl;
        p->next = list;
        list = p;
    }
}

void deleteStart() {
    node *p;
    if (list == NULL) {
        cout << "List is Empty!" << endl;
    } else {
        p = list;
        cout << "Deleted node info is :" << p->info << endl;
        list = p->next;
    }
}

void displayList() {
    node *p;
    p = list;
    if (p == NULL) {
        cout << "List is Empty!" << endl;
    }
    cout << "[ ";
    while (p != NULL) {
        cout << p->info << " ";
        p = p->next;
    }
    cout << "]" << endl;
}

int main() {

    insertStart(10);
    insertStart(20);
    insertStart(30);
    insertStart(40);

    displayList();

    deleteStart();
    deleteStart();
    deleteStart();

    displayList();

    return 0;
}