/*
    Strategy:
        1) min in subtree of counting that particular node
        2) max in subtree of counting that particular node
        3) subtree size
        4) size of largest BST
        5) isBST
*/
#include <iostream>
#include <climits>
using namespace std;

struct Node
{
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

struct Info
{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

Info largestBST(Node *root)
{
    // base cases
    if (root == NULL)
        return {0, INT_MIN, INT_MAX, 0, true};

    if (root->left == NULL && root->right == NULL)
        return {1, root->data, root->data, 1, true};

    // getting info of left and right subtres
    Info leftInfo = largestBST(root->left);
    Info rightInfo = largestBST(root->right);

    Info curr;

    curr.size = (1 + leftInfo.size + rightInfo.size);

    // if it forms BST
    if (leftInfo.isBST && rightInfo.isBST && leftInfo.max < root->data && rightInfo.min > root->data)
    {
        curr.max = max(leftInfo.max, max(rightInfo.max, root->data));
        curr.min = min(leftInfo.min, min(rightInfo.min, root->data));
        curr.ans = curr.size;
        curr.isBST = true;

        return curr;
    }

    // If it does not form BST
    curr.ans = max(leftInfo.ans, rightInfo.ans);
    curr.isBST = false;
    return curr;
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

    cout << "Largest BST in BT : ";
    cout << largestBST(root).ans;

    largestBST(root);
}