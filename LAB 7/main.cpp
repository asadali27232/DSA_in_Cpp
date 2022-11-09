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
        list = p;
        p->next = list;
    } else {
        node *q;
        q = list;
        while (q->next != list) q = q->next;

        p = new node;
        p->info = infoValue;
        cout << "Inserted Value :" << p->info << endl;
        p->next = list;
        list = p;
        q->next = list;
    }
}

void insertAt(int atValue, int infoValue) {
    node *p;
    if (list == NULL) {
        p = new node;
        p->info = infoValue;
        cout << "Inserted Value :" << p->info << endl;
        p->next = NULL;
        list = p;
    } else {
        p = list;
        do {
            if (p->info == atValue) {
                cout << "Inserted Value " << infoValue << " at " << p->info << endl;
                p->info = infoValue;
            }
            p = p->next;
        } while (p->next != list);
    }
}

void insertEnd(int infoValue) {
    node *p;
    if (list == NULL) {
        p = new node;
        p->info = infoValue;
        cout << "Inserted Value :" << p->info << endl;
        list = p;
        p->next = list;
    } else {
        p = new node;
        p->info = infoValue;
        p->next = list;
        node *q;
        q = list;

        while (q->next != list) {
            q = q->next;
        }
        q->next = p;
        cout << "Inserted Value :" << p->info << endl;
    }
}

void deleteStart() {
    node *p;
    if (list == NULL) {
        cout << "List is Empty!" << endl;
    } else {
        node *q;

        q = list;
        while (q->next != list) q = q->next;

        p = list;
        list = p->next;
        q->next = list;

        cout << "Deleted node info is :" << p->info << endl;
        free(p);
    }
}

void deleteAt(int atValue) {
    node *p;
    if (list == NULL) {
        cout << "List is Empty!" << endl;
    } else {
        p = list;
        node *pointOfDeletion = NULL;
        while (p->next != list) {
            if (p->info == atValue) {
                pointOfDeletion = p;
            }
            p = p->next;
        }

        node *pointBeforeDeletion = NULL;
        p = list;
        while (p->next != list) {
            if (p->next == pointOfDeletion) {
                pointBeforeDeletion = p;
                break;
            }
            p = p->next;
        }
        pointBeforeDeletion->next = pointOfDeletion->next;
        free(pointOfDeletion);
    }
}

void deleteEnd() {
    node *p;
    p = list;
    if (list == NULL) {
        cout << "List is Empty!" << endl;
    } else if (p->next == list) {
        cout << "Deleted node info is :" << p->info << endl;
        free(p);
    } else {
        node *q;
        while (p->next != list) {
            q = p;
            p = p->next;
        }
        q->next = list;
        cout << "Deleted node info is :" << p->info << endl;
        free(p);
    }
}

void displayList() {
    node *p;
    p = list;
    if (p == NULL) {
        cout << "List is Empty!" << endl;
    }
    cout << "[ ";
    do {
        cout << p->info << " ";
        p = p->next;
    } while (p != list);
    cout << "]" << endl;
}

void count() {
    node *p;
    p = list;
    if (p == NULL) {
        cout << "List is Empty!" << endl;
    }
    int counter = 0;
    do {
        counter++;
        p = p->next;
    } while (p != list);
    cout << "Number of nodes in Linked list = " << counter << endl;
}

void search(int value) {
    node *p;
    p = list;
    int count = 1;
    do {
        if (p->info == value) {
            cout << value << " is found at " << count << endl;
            return;
        }
        p = p->next;
        count++;
    } while (p != list);
    cout << "Element not found." << endl;
}

void sort() {

}

int main() {

    insertStart(12);
    insertStart(44);
    insertStart(23);

    insertEnd(333);
    insertEnd(444);
    insertEnd(444);

    displayList();

    deleteStart();
    deleteEnd();

    insertAt(444, 555);


    displayList();
    count();
    search(12);

    return 0;
}