void inorder(Node *node, vector<int> &res)
{
    if (node == NULL)
        return;

    inorder(node->left, res);
    res.push_back(node->data);
    // cout<<root->data<<" ";
    inorder(node->right, res);
}
int KthSmallestElement(Node *root, int K)
{
    // add code here

    vector<int> ans;
    inorder(root, ans);

    if (K > ans.size())
        return -1;

    return ans[K - 1];
}