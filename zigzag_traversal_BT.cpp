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

vector<int> zigZagTraversal(Node *root)
{
    vector<int> result;
    if (root == NULL)
        return result;

    queue<Node *> q;
    q.push(root);

    bool leftToRight = true;

    while (!q.empty())
    {

        int size = q.size();
        vector<int> ans(size);

        // Level Process
        for (int i = 0; i < size; i++)
        {

            Node *frontNode = q.front();
            q.pop();

            // normal insert or reverse insert
            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontNode->data;

            if (frontNode->left)
                q.push(frontNode->left);

            if (frontNode->right)
                q.push(frontNode->right);
        }

        // direction change karni h
        leftToRight = !leftToRight;

        for (auto i : ans)
        {
            result.push_back(i);
        }
    }
    return result;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    return 0;
}