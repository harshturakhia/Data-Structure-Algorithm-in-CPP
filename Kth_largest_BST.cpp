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

vector<int> ans;
void inorder(Node *node)
{
    if (node == NULL)
        return;

    inorder(node->left);
    ans.push_back(node->data);
    inorder(node->right);
}

int kthLargest(Node *root, int K)
{
    // Your code here
    inorder(root);
    sort(ans.begin(), ans.end(), greater<int>());
    return ans[K - 1];
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

    kthLargest(root);
}
