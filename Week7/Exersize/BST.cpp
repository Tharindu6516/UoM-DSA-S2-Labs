#include <iostream>
using namespace std;

struct node {
    int key;
    struct node* left, * right;
};

// Inorder traversal
void traverseInOrder(struct node* root) {
    if (!root) return;
    traverseInOrder(root->left);
    cout << root->key << " ";
    traverseInOrder(root->right);
}

// Insert a node
struct node* insertNode(struct node* root, int key) {
    if (!root) return new node{ key, NULL, NULL };
    if (root->key < key) root->right = insertNode(root->right, key);
    else root->left = insertNode(root->left, key);

    return root;
}

struct node* leftMostLeaf(struct node* root) {
    if (root->left) return leftMostLeaf(root->left);
    return root;
}

// Deleting a node
struct node* deleteNode(struct node* root, int key) {
    if (!root) return NULL;
    if (root->key < key) root->right = deleteNode(root->right, key);
    else if (root->key > key) root->left = deleteNode(root->left, key);

    else {
        if (root->left && root->right)
        {
            root->right = deleteNode(root->right, root->key = leftMostLeaf(root->right)->key);
            return root;
        }
        if (root->left) return root->left;
        if (root->right) return root->right;
        return NULL;
    }
}

// Driver code
int main() {
    struct node* root = NULL;

    int operation;
    int operand;
    cin >> operation;

    while (operation != -1) {
        switch (operation) {
        case 1: // insert
            cin >> operand;
            root = insertNode(root, operand);
            cin >> operation;
            break;
        case 2: // delete
            cin >> operand;
            root = deleteNode(root, operand);
            cin >> operation;
            break;
        default:
            cout << "Invalid Operator!\n";
            return 0;
        }
    }

    traverseInOrder(root);
}