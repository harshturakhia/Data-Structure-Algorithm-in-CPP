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

int countNodeRecursive(Node *root)
{
    if (root == NULL)
        return 0;

    return countNodeRecursive(root->left) + countNodeRecursive(root->right) + 1;
}

int countNode(Node *root)
{
    if (root == NULL)
        return 0;

    int count = 0;
    queue<Node *> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        if (node != NULL)
        {
            count++;
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
    return count;
}

int sumNodeRecursive(Node *root)
{
    if (root == NULL)
        return 0;

    return sumNodeRecursive(root->left) + sumNodeRecursive(root->right) + root->data;
}

int sumNode(Node *root)
{
    if (root == NULL)
        return 0;

    int sum = 0;
    queue<Node *> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        if (node != NULL)
        {
            sum += node->data;
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
    return sum;
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

    cout << "Count of nodes : " << countNode(root) << endl;

    cout << "Sum of nodes : " << sumNode(root);
}
