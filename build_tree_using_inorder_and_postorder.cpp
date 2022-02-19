#include "bits/stdc++.h"
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;

    node(int val)
    {
        data = val;
        left=NULL;
        right=NULL;
    }
};

void inorderPrint(struct node* root)