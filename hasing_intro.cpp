#include "bits/stdc++.h"
using namespace std;

// Time Complesities of Insertion, Deletion and Searching :

// Linked List = O(n)
// BSt = O(log n)
// Hash = O(1)

// Check mapo_intro.cpp file first to understand this

// 1 = Maximum frequency number
int maxRepeating(int *arr, int n, int k)
{
    // code here

    for (int i = 0; i < n; i++)
        arr[arr[i] % k] += k;

    int res = 0;
    int mx = arr[0] / k;
    for (int i = 1; i < n; i++)
    {
        if (mx < arr[i] / k)
        {
            mx = arr[i] / k;
            res = i;
        }
    }
    return res;
}
