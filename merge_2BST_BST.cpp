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

void inorder(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

vector<int> merge(Node *root1, Node *root2)
{
    // Your code here
    vector<int> ans;

    inorder(root1, ans);
    inorder(root2, ans);

    sort(ans.begin(), ans.end());

    return ans;
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    root->right->left = new Node(6);
    root->right->right = new Node(8);

    Node *root2 = new Node(5);
    root2->left = new Node(2);
    root2->right = new Node(7);
    root2->left->left = new Node(1);
    root2->left->right = new Node(3);

    root2->right->left = new Node(6);
    root2->right->right = new Node(8);

    merge(root, root2);
}