#include "iostream"

using namespace std;

struct node {
    int info;
    node *next;
};

node *list = nullptr;

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
        while (p != NULL) {
            if (p->info == atValue) {
                cout << "Inserted Value " << infoValue << " at " << p->info << endl;
                p->info = infoValue;
            }
            p = p->next;
        }
    }
}

void insertEnd(int infoValue) {
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
        p->next = NULL;
        node *q;
        q = list;
        while (q->next != NULL) {
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
        p = list;
        cout << "Deleted node info is :" << p->info << endl;
        list = p->next;
    }
}

void deleteAt(int atValue) {
    node *p;
    if (list == NULL) {
        cout << "List is Empty!" << endl;
    } else {
        p = list;
        node *pointOfDeletion = NULL;
        while (p != NULL) {
            if (p->info == atValue) {
                pointOfDeletion = p;
            }
            p = p->next;
        }

        node *pointBeforeDeletion = NULL;
        p = list;
        while (p != NULL) {
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
    } else if (p->next == NULL) {
        free(p);
    } else {
        node *q;
        while (p->next != NULL) {
            q = p;
            p = p->next;
        }
        q->next = NULL;
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
    while (p != NULL) {
        cout << p->info << " ";
        p = p->next;
    }
    cout << "]" << endl;
}

void count() {
    node *p;
    p = list;
    if (p == NULL) {
        cout << "List is Empty!" << endl;
    }
    int counter = 0;
    while (p != NULL) {
        counter++;
        p = p->next;
    }
    cout << "Number of nodes in Linked list = " << counter << endl;
}

node *linkTwoLists(struct node *firstList, struct node *secList) {
    if (firstList == NULL && secList == NULL) {
        cout << "Both lists are empty." << endl;
        return NULL;
    } else if (firstList == NULL) {
        cout << "First list is empty." << endl;
        return NULL;
    } else if (secList == NULL) {
        cout << "First list is empty." << endl;
        return NULL;
    }
    node *p;
    p = firstList;
    while (p != NULL) {
        p = p->next;
    }
    p->next = secList;

    return firstList;
}

void search(int value) {
    node *p;
    p = list;
    int count = 1;
    while (p != NULL) {
        if (p->info == value) {
            cout << value << " is found at " << count << endl;
            return;
        }
        p = p->next;
        count++;
    }
}

void sort() {
    struct node *p;
    struct node *q;
    p = list;
    q = list;
    int temp;

    while (p->next != nullptr) {
        bool isSorted = true;
        while (q->next != nullptr) {
            if (q->info > q->next->info) {
                temp = q->info;
                q->info = q->next->info;
                q->next->info = temp;
                isSorted = false;
            }
            q = q->next;
        }
        if (isSorted)
            return;
        p = p->next;
    }
}

int main() {
    insertStart(12);
    insertStart(44);
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
    sort();
    displayList();
    return 0;
}