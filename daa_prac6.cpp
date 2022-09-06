#include "bits/stdc++.h"
using namespace std;

void indianCoinChange()
{
    int denominations = 10;
    cout << denominations << endl;

    vector<int> arr = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};

    for (auto i : arr)
        cout << arr[i];

    cout << endl;

    int amount = 54;
    cout << "Amount is : " << amount << endl;

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

int main()
{
    int choice;
    cout << "Enter the Greedy program choice to implement : \n";
    cout << "1. Indian Coin Change \n2. Greedy \n3. Greedy \n4.Greedy \n\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        indianCoinChange();
        break;

    default:
        break;
    }
}