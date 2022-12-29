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

void reverse() {
    node *current = list;
    node *prev = NULL;
    node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list = prev;
}

int main() {

    insertStart(90);
    insertStart(80);
    insertStart(70);
    insertStart(60);
    insertStart(50);
    insertStart(40);
    insertStart(30);
    insertStart(20);
    insertStart(10);

    cout << "Given list" << endl;
    displayList();

    cout << "Reversed List" << endl;
    reverse();
    displayList();

    return 0;
}