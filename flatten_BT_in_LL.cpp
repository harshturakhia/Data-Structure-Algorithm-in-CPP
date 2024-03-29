#include "bits/stdc++.h"
#include <queue>
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

void flattenBT(Node *root)
{

    if (root == NULL || root->left == NULL && root->right == NULL)
    {
        return;
    }

    // step 1 - flatten left and right BT
    if (root->left != NULL)
    {
        flattenBT(root->left);

        Node *temp = root->right;
        root->right = root->left;
        root->left = NULL;

        // here right is that previous left
        Node *t = root->right;

        while (t->right != NULL)
        {
            t = t->right;
        }
        t->right = temp;
    }

    flattenBT(root->right);
}

void inorderPrint(Node *root)
{
    if (root == NULL)
        return;

    inorderPrint(root->left);
    cout << root->data << "  ";
    inorderPrint(root->right);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    // root->right->right = new Node(7);

    flattenBT(root);
    inorderPrint(root);
}
