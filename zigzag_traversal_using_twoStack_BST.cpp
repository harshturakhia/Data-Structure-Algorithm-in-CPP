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

/*
Node *zigzag(Node *root)
{
    if (root == NULL)
        return NULL;

    deque<Node *> q;

    q.push_back(root);
    q.push_back(NULL);

    bool leftToRight = true;

    while (q.size() > 1)
    {

        if (leftToRight)
        {
            Node *node = q.front();
            if (node)
            {
                cout << node->data << " ";

                if (node->left)
                    q.push_back(node->left);

                if (node->right)
                    q.push_back(node->right);

                q.pop_front();
            }
            else
            {
                leftToRight != leftToRight;
            }
        }
        else
        {
            Node *node = q.back();
            if (node)
            {
                cout << node->data << " ";

                if (node->left)
                    q.push_front(node->left);

                if (node->right)
                    q.push_front(node->right);

                q.pop_back();
            }
            else
            {
                leftToRight != leftToRight;
            }
        }
    }
    cout << "\n";
}
*/

// Stack method
void zigzag(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> currLevel;
    stack<Node *> nextLevel;

    bool leftToRight = true;
    currLevel.push(root);

    while (!currLevel.empty())
    {
        Node *temp = currLevel.top();
        currLevel.pop();

        if (temp)
        {
            cout << temp->data << " ";

            // Left to right
            if (leftToRight)
            {
                if (temp->left)
                    nextLevel.push(temp->left);

                if (temp->right)
                    nextLevel.push(temp->right);
            }
            // Right to left
            else
            {
                if (temp->right)
                    nextLevel.push(temp->right);

                if (temp->left)
                    nextLevel.push(temp->left);
            }
        }

        if (currLevel.empty())
        {
            cout << endl;
            leftToRight = !leftToRight;
            swap(currLevel, nextLevel);
        }
    }
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

    zigzag(root);
    // inorder(root);
}