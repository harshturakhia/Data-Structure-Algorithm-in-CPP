#include "bits/stdc++.h"
#include <queue>
#include <math.h>
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
    //O(n^2)
bool isBalanced(Node *root)
{
    if (root == NULL)
        return true;

    if (isBalanced(root->left) == false)
        return false;

    if (isBalanced(root->right) == false)
        return false;

    int lh = height(root->left);
    int rh = height(root->right);

    if (abs(lh - rh) <= 1)
        return true;
    else
        return false;
}

int height(Node *root)
{
    if (root == NULL)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    return max(lh, rh) + 1;
}

*/

/*
    // O(n)
bool isBalanced(Node *root, int *height)
{
    if (root == NULL)
        return true;

    int lh = 0;
    int rh = 0;

    if (isBalanced(root->left, &lh) == false)
        return false;

    if (isBalanced(root->right, &rh) == false)
        return false;

    // *height = max(lh, rh) + 1;

    if (abs(lh - rh) <= 1)
        return true;
    else
        return false;
}
*/

pair<bool, int> balancedFast(Node *root)
{

    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<int, int> left = balancedFast(root->left);
    pair<int, int> right = balancedFast(root->right);

    // bool left = balancedFast(root->left);
    // bool right = balancedFast(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;

    ans.second = max(left.second, right.second) + 1;

    if (leftAns && rightAns && diff)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }
    return ans;
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

    /*
    if (isBalanced(root))
        cout << "Balanced BT";
    else
        cout << "Not balanced BT";

    cout << endl;

    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->left->left = new Node(3);

    if (isBalanced(root2))
        cout << "Balanced BT";
    else
        cout << "Not balanced BT";

    */

    /*
    int height = 0;

    if (isBalanced(root, &height) == true)
        cout << "Balanced BT";
    else
        cout << "Not balanced BT";

    cout << endl;

    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->left->left = new Node(3);

    if (isBalanced(root2, &height) == true)
        cout << "Balanced BT";
    else
        cout << "Not balanced BT";

    */
}
