#include "iostream"

using namespace std;

struct node {
    int info;
    node *next;
};
node *list = NULL;
node *primeList = NULL;

void insert(int infoValue) {
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

void insertPrime(int infoValue) {
    node *p;
    if (primeList == NULL) {
        p = new node;
        p->info = infoValue;
        cout << "Inserted Value :" << p->info << endl;
        p->next = NULL;
        primeList = p;
    } else {
        p = new node;
        p->info = infoValue;
        cout << "Inserted Value :" << p->info << endl;
        p->next = primeList;
        primeList = p;
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

void displayPrimeList() {
    node *p;
    p = primeList;
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

bool isPrime(int n) {
    bool is_prime = true;

    // 0 and 1 are not prime numbers
    if (n == 0 || n == 1) {
        is_prime = false;
    }

    // loop to check if n is prime
    for (int i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            is_prime = false;
            break;
        }
    }
    return is_prime;
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
void deletePrimeNodes() {
    node *ptr = list;

    while (ptr != NULL) {
        // if true, delete node 'ptr'
        if (isPrime(ptr->info)) {
            insertPrime(ptr->info);
            ptr = ptr->next;
            deleteAt(ptr->info);
            continue;
        }
        ptr = ptr->next;
    }
}

int main() {

    insert(11);
    insert(10);
    insert(9);
    insert(8);
    insert(7);
    insert(5);
    insert(5);
    insert(4);
    insert(3);
    insert(2);
    insert(1);

    cout << "Given List" << endl;
    displayList();

    deletePrimeNodes();

    cout << "Given List After Separation" << endl;
    displayList();

    cout << "Prime Number's list" << endl;
    displayPrimeList();

    return 0;
}