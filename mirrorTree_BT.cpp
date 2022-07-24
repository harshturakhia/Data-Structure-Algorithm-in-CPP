#include "bits/stdc++.h"
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node *mirrorTree(Node *root)
{
    if (root == NULL)
        return root;

    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    if (root->left)
        mirrorTree(root->left);

    if (root->right)
        mirrorTree(root->right);

    return root;
}
int main()
{
    Node *root = new Node(3);
    root->left = new Node(2);
    root->right = new Node(1);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "\nInorder of Mirror tree: ";
    inorder(root);

    mirrorTree(root);

    cout << "\nInorder of Mirror tree: ";
    inorder(root);
}
