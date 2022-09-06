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

Node *LCA2(Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    Node *leftLCA = LCA2(root->left, n1, n2);
    Node *rightLCA = LCA2(root->right, n1, n2);

    if (leftLCA && rightLCA)
        return root;

    if (leftLCA != NULL && rightLCA == NULL)
        return leftLCA;

    if (rightLCA != NULL && leftLCA == NULL)
        return rightLCA;
}

// TC = O(n)
Node *LCA3(Node *root, int n1, int n2)
{
    while (root != NULL)
    {
        if (root->data < n1 && root->data < n2)
            return LCA3(root->right, n1, n2);

        else if (root->data > n1 && root->data > n2)
            return LCA3(root->left, n1, n2);

        else
            return root;
    }
}

int main()
{
    Node *root1 = new Node(5);
    root1->left = new Node(2);
    root1->right = new Node(7);
    root1->left->left = new Node(1);
    root1->left->right = new Node(3);
    root1->right->left = new Node(6);
    root1->right->right = new Node(8);

    Node *lca = LCA3(root1, 3, 1);

    if (lca == NULL)
        cout << "Doesn't exist";
    else
        cout << "LCA is : " << lca->data;
}
