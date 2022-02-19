/*
    Dutch Nucher Flag Sort
    Only 3 element which are 0,1,2
*/

#include <iostream>
using namespace std;

void dnfSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int low = 0;
        int high = n - 1;
        int check = 0;

        while (check <= high)
        {
            if (arr[check] == 0)
            {
                int temp = arr[low];
                arr[low] = arr[check];
                arr[check] = temp;
                low++;
                check++;
            }
            else if (arr[check] == 1)
            {
                check++;
            }
            else
            {
                int temp = arr[check];
                arr[check] = arr[high];
                arr[high] = temp;
                high--;
            }
        }
    }
}

int main()
{
    int n = 9;
    int arr[] = {1, 2, 0, 0, 2, 2, 1, 1, 2};
    dnfSort(arr, n);

    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << "   ";
    }
}