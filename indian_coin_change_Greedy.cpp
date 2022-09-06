#include "bits/stdc++.h"
using namespace std;

int main()
{
    int denominations = 10;

    vector<int> arr = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};

    int amount = 54;

    sort(arr.begin(), arr.end(), greater<int>());
    int ans = 0;

    for (auto i = 0; i < denominations; i++)
    {
        ans = ans + (amount / arr[i]);
        amount = amount - (amount / arr[i]) * (arr[i]);
    }
    cout << "Minimum coins in change will be : ";
    cout << ans;
}