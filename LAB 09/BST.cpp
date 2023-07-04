#include "iostream"

using namespace std;

class BST_Node {
public:
    int data;
    BST_Node *left;
    BST_Node *right;

    explicit BST_Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }

    void dataInsertion(int childData) {
        if (childData < this->data) {
            this->left = new BST_Node(childData);
        } else if (childData > this->data)
            this->right = new BST_Node(childData);
        else
            cout << "DISCARDED! Child already exist in given BST." << endl;
    }
};

void nodeInsertion(BST_Node *root, BST_Node *child) {
    if (child->data < root->data) {
        if (root->left != nullptr) {
            nodeInsertion(root->left, child);
        } else {
            root->left = child;
        }
    } else if (child->data > root->data) {
        if (root->right != nullptr) {
            nodeInsertion(root->right, child);
        } else {
            root->right = child;
        }
    } else
        cout << "DISCARDED! Child already exist in given BST." << endl;
}

void inorderTraversal(BST_Node *root) {
    if (root == nullptr)
        return;
    inorderTraversal(root->left);
    cout << root->data << "  ";
    inorderTraversal(root->right);
}

void preTraversal(BST_Node *root) {
    if (root == nullptr)
        return;
    cout << root->data << "  ";
    preTraversal(root->left);
    preTraversal(root->right);
}

void postTraversal(BST_Node *root) {
    if (root == nullptr)
        return;
    postTraversal(root->left);
    postTraversal(root->right);
    cout << root->data << "  ";
}

BST_Node *search(BST_Node *root, int findData) {
    if (root->data == findData)
        return root;
    else if (root->data < findData)
        search(root->left, findData);
    else if (root->data > findData)
        search(root->right, findData);
    else
        return nullptr;
}

void leftDelete(BST_Node *root, int data) {
    BST_Node *deletingNode = search(root, data);
    if (deletingNode == nullptr) {
        cout << "Value is not available." << endl;
        return;
    }
    if (deletingNode->left == nullptr && deletingNode->right == nullptr) {

    }
}

void rightDelete(BST_Node *root) {

}

int main2() {
    BST_Node root = BST_Node(12);

    nodeInsertion(&root, new BST_Node(12));
    nodeInsertion(&root, new BST_Node(13));
    nodeInsertion(&root, new BST_Node(15));
    nodeInsertion(&root, new BST_Node(15));
    nodeInsertion(&root, new BST_Node(9));
    nodeInsertion(&root, new BST_Node(6));

    inorderTraversal(&root);

    return 0;
}
