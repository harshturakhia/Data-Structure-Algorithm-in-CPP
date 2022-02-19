//Time - Complexity = O(n`2)

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int flag;

    for (int i = 0; i < n - 1; i++)
    {
        flag = 0;

        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
            flag = 1;
        }
        if (flag == 0)
        {
            cout << "No swapping done!";
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
}