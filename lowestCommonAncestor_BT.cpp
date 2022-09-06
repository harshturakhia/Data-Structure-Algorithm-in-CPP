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

// 1st method
//  TC = O(n)
bool getPath(Node *root, int key, vector<int> &path)
{
    if (root == NULL)
        return false;

    path.push_back(root->data);

    if (root->data == key)
        return true;

    if (getPath(root->left, key, path) || getPath(root->right, key, path))
    {
        return true;
    }

    path.pop_back();
    return false;
}

int LCA(Node *root, int n1, int n2)
{
    vector<int> path1, path2;

    if (!getPath(root, n1, path1) || !getPath(root, n2, path2))
    {
        return -1;
    }

    // pc = path change
    int pc;

    for (pc = 0; pc < path1.size() && path2.size(); pc++)
    {
        if (path1[pc] != path2[pc])
            break;
    }
    return path1[pc - 1];
}

// 2nd method
// TC = O(n)
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

// 3rd method
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
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    // root->left->right = new Node(5);

    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);

    // 1st method
    /*
    int n1 = 7;
    int n2 = 6;
    int lca = LCA(root, n1, n2);

    if (lca == -1)
        cout << "Doesn't exist";
    else
        cout << "LCA is : " << lca;
    */

    // 2nd method
    int n1 = 7;
    int n2 = 6;
    Node *lca = LCA2(root, n1, n2);

    if (lca == NULL)
        cout << "Doesn't exist";
    else
        cout << "LCA is : " << lca->data;
}