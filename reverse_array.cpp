#include <iostream>
using namespace std;

int main()
{
    int n;

    for (int i<(n-1), int j=0 ; i >= 0; i--, j++)
    {
        while (i>0)
        {
            int temp = 0;
            temp = arr[n];
            arr[n] = arr[i];
            arr[i] = temp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
}