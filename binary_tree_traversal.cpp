/*
There are 3 ways to traverse the tree :-
    1) Pre-order :-
        -> Go left everytime from root till NULL then go right everytime till NULL
        -> Root to left tree to right tree
        -> 1 2 4 5 3 6 7

    2) In-Order :-
        -> Go left everytime from root till NULL but write number after you travel full left sub tree
           then go right everytime till NULL & then write number
        -> Left sub tree  to root to right tree to same respectively
        -> 4 2 5 1 6 3 7

    3) Post-order :-
        -> Go left everytime from root till NULL then write number & then go right everytime till NULL
           then write number & after at last write root number
        -> Left sub tree to right tree to root same respectively
        -> 4 5 2 6 7 3 1
*/

#include "bits/stdc++.h"
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preorder(struct node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

/*
void levelOrderTraversal(struct node *root)
{
    if (root == NULL)
        return;

    queue<node *> q;
    q.push(q.front());
    q.push(NULL);

    while (!q.empty())
    {
        struct node *no = q.front();
        q.pop();

        if (node != NULL)
        {
            cout << no->data << " ";

            if (no->left)
                q.push(no->data);
            if (no->right)
                q.push(no->right);
        }
        else
        {
            q.push(NULL);
        }
    }
}*/

int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);

    cout << endl
         << "Pre-order Traversal : " << endl;
    preorder(root);

    cout << endl
         << "In-order Traversal : " << endl;
    inorder(root);

    cout << endl
         << "Post-order Traversal : " << endl;
    postorder(root);
}