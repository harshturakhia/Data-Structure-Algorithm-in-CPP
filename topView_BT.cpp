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
void topView(Node *root)
{
    // Your code here

    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);
    cout << root->data;
    cout << " ";

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {

            Node *node = q.front();
            q.pop();

            if (i == 1)
            {
                cout << node->data << " ";
            }
            if (i == i - 1)
            {
                cout << node->data << " ";
            }

            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
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

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    topView(root);
}
