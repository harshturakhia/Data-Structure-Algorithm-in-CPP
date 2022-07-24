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

    int heightBT(Node *root)
    {
        if (root == NULL)
            return 0;

        int leftHeight = heightBT(root->left);
        int rightHeight = heightBT(root->right);

        return max(leftHeight, rightHeight) + 1;
    }

    int diameterBT(Node *root)
    {
        if (root == NULL)
            return 0;

        int leftHeight = heightBT(root->left);
        int rightHeight = heightBT(root->right);
        int currDiameter = leftHeight + rightHeight + 1;

        int leftDiameter = diameterBT(root->left);
        int rightDiamter = diameterBT(root->right);

        return max(currDiameter, max(leftDiameter, rightDiamter));
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

        cout << "Height of Tree is : " << heightBT(root) << endl;

        cout << "Diameter of Tree is : " << diameterBT(root) << endl;
    }
