#include "bits/stdc++.h"
using namespace std;

// 1st way = O(n^3)

// int threeSum(int arr[], int n, int target)
// {
//     for (int i = 0; i < n - 2; i++)
//     {
//         for (int j = i + 1; j < n - 1; j++)
//         {
//             for (int k = j + 1; k < n; k++)
//             {
//                 if (arr[i] + arr[j] + arr[k] == target)
//                 {
//                     return true;
//                 }
//             }
//         }
//     }
//     return false;
// }

// 2nd way = O(n ^ 2)
int threeSum(int arr[], int n, int target)
{
    sort(arr, arr + n);

    for (int i = 0; i < n; i++)
    {
        int l = i + 1;
        int r = n - 1;

        while (l < r)
        {
            if (arr[i] + arr[l] + arr[r] == target)
            {
                return true;
            }
            else if (arr[i] + arr[l] + arr[r] < target)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
    }
    return false;
}

int main()
{
    int n = 7;
    int arr[n] = {1, 3, 5, 7, 9, 2, 4};
    int target = 12;

    cout << threeSum(arr, n, target) << endl;
}