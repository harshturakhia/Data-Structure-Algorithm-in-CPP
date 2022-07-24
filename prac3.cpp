#include "bits/stdc++.h"
#define MAX_ELEMENT 50
using namespace std;

void radixSort(int arr[], int n)
{
}

void shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
        }
    }
}

int main()
{
    int arr[MAX_ELEMENT];
    int n = 10;

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % MAX_ELEMENT;
    }

    cout << "Before Sorting : \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl
         << endl;

    int ch;
    cout << "Enter which sorting algo to use : " << endl;
    cout << "1. Radix Sort \n2. Shell Sort \n\n";
    cin >> ch;

    switch (ch)
    {
    case 1:
        radixSort(arr, n);
        break;
    case 2:
        shellSort(arr, n);
        break;

    default:
        cout << "Enter correct choice you fucker..." << endl;
        break;
    }

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}