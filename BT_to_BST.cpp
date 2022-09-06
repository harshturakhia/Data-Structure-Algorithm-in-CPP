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

Node *solve2(vector<int> &nums, int l, int r)
{
    if (l > r)
        return NULL;

    int mid = l + (r - l) / 2;

    Node *root = new Node(nums[mid]);

    root->left = solve2(nums, l, mid - 1);
    root->right = solve2(nums, mid + 1, r);

    return root;
}

void solve(Node *root, vector<int> &arr)
{
    if (!root)
        return;

    solve(root->left, arr);
    arr.push_back(root->data);
    solve(root->right, arr);

    return;
}

Node *binaryTreeToBST(Node *root)
{
    // Your code goes here
    vector<int> arr;
    solve(root, arr);
    sort(arr.begin(), arr.end());

    return solve2(arr, 0, arr.size() - 1);
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

    binaryTreeToBST(root);
}
