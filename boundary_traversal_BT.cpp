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

void left(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
        return;

    ans.push_back(root->data);

    if (root->left)
        left(root->left, ans);
    else
        left(root->right, ans);
}

void leaf(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }

    leaf(root->left, ans);
    leaf(root->right, ans);
}

void right(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
        return;

    if (root->right)
        right(root->right, ans);
    else
        right(root->left, ans);

    // wapas
    ans.push_back(root->data);
}

vector<int> boundary(Node *root)
{
    // Your code here
    vector<int> ans;
    if (root == NULL)
        return ans;

    ans.push_back(root->data);

    // left part without leaf node
    left(root->left, ans);

    // leaf nodes
    // for left subtree
    leaf(root->left, ans);
    // for right subtree
    leaf(root->right, ans);

    // right part without leaf nodes and in reverse order too
    right(root->right, ans);

    return ans;
}

void printLevelOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        if (node != NULL)
        {
            cout << node->data << " ";

            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->right->left->left = new Node(10);
    root->right->left->right = new Node(11);

    cout << "Level order traversal : \n";
    printLevelOrderTraversal(root);
    cout << endl;

    vector<int> ans;
    ans = boundary(root);

    cout << "Boundary traversal : \n";

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
