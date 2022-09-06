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

bool isIdentical(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    else if (root1 == NULL || root2 == NULL)
        return false;
    else
    {
        bool cond1 = root1->data == root2->data;
        bool cond2 = isIdentical(root1->left, root2->left);
        bool cond3 = isIdentical(root1->right, root2->right);

        if (cond1 && cond2 && cond3)
            return true;
        else
            return false;
    }
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data;
    inOrder(root->right);
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
    inOrder(root1);
    cout << endl;

    Node *root2 = new Node(5);
    root2->left = new Node(2);
    root2->right = new Node(7);
    root2->left->left = new Node(1);
    root2->left->right = new Node(3);
    root2->right->left = new Node(6);
    root2->right->right = new Node(8);
    inOrder(root2);
    cout << endl;

    if (isIdentical(root1, root2))
        cout << "Yes, BSTs are identical";
    else
        cout << "No, BSTs are NOT identical";
}