#include "bits\stdc++.h"
using namespace std;

int main()
{
    int n, target;
    cout << "Enter limit : ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    //sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout << "Enter target : ";
    cin >> target;

    bool found = false;

    for (int i = 0; i < n; i++)
    {
        int lo = i + 1;
        int hi = n - 1;

        while (lo < hi)
        {

            {
                int current = arr[lo] + arr[hi] + arr[i];

                if (current == target)
                {
                    found = true;
                }
                else if (current < target)
                {
                    lo++;
                }
                else
                {
                    hi--;
                }
            }
        }
        if (found)
        {
            cout << "true";
        }
        else
        {
            cout << "False";
        }
    }
}