#include <iostream>

using namespace std;

struct node {
    int data;
    node *left;
    node *right;
};

struct node *createNode(int data) {
    node *newNode = new node;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void preOrder(node *root) {
    if (root == nullptr) return; // Returning condition for recursion

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node *root) {
    if (root == nullptr) return; // Returning condition for recursion

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(node *root) {
    if (root == nullptr) return; // Returning condition for recursion

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

bool isBST(node *root) {
    if (root == nullptr) return true; // Returning condition for recursion
    static node *prev = nullptr; // Previous node or parent node of current node static means remain same for all recursive calls

    if (!isBST(root->left)) {
        return false;
    }
    if (prev != nullptr && root->data <= prev->data) {
        return false;
    }
    prev = root;
    return isBST(root->right);
}

struct node *searchBST(node *root, int key) {
    if (root == nullptr) return nullptr;

    if (key == root->data)
        return root;
    else if (key < root->data)
        return searchBST(root->left, key);
    else
        return searchBST(root->right, key);
}

void insert(node *root, int key) {
    if (key < root->data) {
        if (root->left == nullptr) {
            root->left = createNode(key);
            cout << "Inserted: " << key << endl;
        } else {
            insert(root->left, key);
        }
    } else if (key > root->data) {
        if (root->right == nullptr) {
            root->right = createNode(key);
            cout << "Inserted: " << key << endl;
        } else {
            insert(root->right, key);
        }
    } else {
        cout << "DISCARDED! This Value already exists" << endl;
    }
}

int main() {
    node *root = createNode(5);
    insert(root, 2);
    insert(root, 11);
    insert(root, 25);
    insert(root, 27);
    insert(root, 27);

    // Checking if BST or NOT
    if(isBST(root)) {
        cout << "Is a BST with Inorder Traversal given: ";
        inOrder(root);
        cout << endl;
    } else {
        cout << "Not a BST" << endl;
    }

    node *searchedNode = searchBST(root, 27);
    cout << "Searching in BST: " << endl;
    if (searchedNode == nullptr) {
        cout << "Element not found." << endl;
    } else {
        cout << "Found: " <<  searchedNode->data << endl;
    }
    return 0;
}
