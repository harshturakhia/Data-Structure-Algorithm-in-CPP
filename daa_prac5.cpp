#include "bits/stdc++.h"
#define MAX_ELEMENT 50
using namespace std;

void selectionSort(int arr[], int n)
{
    cout << "Before Sorting : \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    cout << "After Sorting : \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void binarySearch(int arr[], int n)
{
    selectionSort(arr, n);

    int key;
    cout << "Enter which element to find : ";
    cin >> key;

    int s = 0;
    int e = n;

    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (arr[mid] == key)
        {
            cout << "Array element present at : " << mid;
            break;
        }
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
}

int main()
{
    int arr[MAX_ELEMENT];
    int n = 20;

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % MAX_ELEMENT;
    }

    binarySearch(arr, n);
}