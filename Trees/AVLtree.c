#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
    int height;
};

// Global root
struct Node *root = NULL;

// Utility
int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node *n) {
    return n ? n->height : 0;
}

int getBalance(struct Node *n) {
    return n ? height(n->left) - height(n->right) : 0;
}

struct Node* newNode(int key) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

struct Node* rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct Node* leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Internal function (returns updated root)
struct Node* insertInternal(struct Node *node, int key) {
    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left = insertInternal(node->left, key);
    else if (key > node->key)
        node->right = insertInternal(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Public void function
void insert(int key) {
    root = insertInternal(root, key);
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left)
        current = current->left;
    return current;
}

struct Node* deleteInternal(struct Node* node, int key) {
    if (node == NULL) return NULL;

    if (key < node->key)
        node->left = deleteInternal(node->left, key);
    else if (key > node->key)
        node->right = deleteInternal(node->right, key);
    else {
        if (node->left == NULL || node->right == NULL) {
            struct Node *temp = node->left ? node->left : node->right;
            free(node);
            return temp;
        } else {
            struct Node* temp = minValueNode(node->right);
            node->key = temp->key;
            node->right = deleteInternal(node->right, temp->key);
        }
    }

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && getBalance(node->left) >= 0)
        return rightRotate(node);
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && getBalance(node->right) <= 0)
        return leftRotate(node);
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Public delete function
void deleteKey(int key) {
    root = deleteInternal(root, key);
}

// Inorder traversal
void inOrder(struct Node* node) {
    if (node) {
        inOrder(node->left);
        printf("%d ", node->key);
        inOrder(node->right);
    }
}

int main() {
    int values[] = {30, 20, 40, 10, 25, 35, 50};
    for (int i = 0; i < 7; i++)
        insert(values[i]);

    printf("Inorder traversal: ");
    inOrder(root);
    printf("\n");

    deleteKey(20);
    printf("After deleting 20: ");
    inOrder(root);
    printf("\n");

    return 0;
}
