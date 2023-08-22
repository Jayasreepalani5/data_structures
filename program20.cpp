#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int key;
    int height;
    struct TreeNode *left;
    struct TreeNode *right;
};
int height(struct TreeNode *node) {
    if (node == NULL)
        return 0;
    return node->height;
}
int balanceFactor(struct TreeNode *node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}
struct TreeNode *rotateRight(struct TreeNode *y) {
    return newRoot;
}
struct TreeNode *rotateLeft(struct TreeNode *x) {
    return newRoot;
}
struct TreeNode *insert(struct TreeNode *root, int key) {
    if (root == NULL)
        return createNode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root;
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = balanceFactor(root);
    return root;
}
struct TreeNode *delete(struct TreeNode *root, int key) {
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = delete(root->left, key);
    else if (key > root->key)
        root->right = delete(root->right, key);
    else {
        if (root->left == NULL || root->right == NULL) {
            struct TreeNode *temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            free(temp);
        } else {
            struct TreeNode *temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = delete(root->right, temp->key);
        }
    }
    if (root == NULL)
        return root;
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = balanceFactor(root);
    return root;
}
struct TreeNode *search(struct TreeNode *root, int key) {
    if (root == NULL || root->key == key)
        return root;
    if (key < root->key)
        return search(root->left, key);
    else
        return search(root->right, key);
}
int main() {
    struct TreeNode *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    struct TreeNode *foundNode = search(root, 20);
    if (foundNode)
        printf("Element found: %d\n", foundNode->key);
    else
        printf("Element not found.\n");
    root = delete(root, 20);
    return 0;
}
