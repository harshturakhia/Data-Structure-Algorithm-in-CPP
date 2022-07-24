#include "bits/stdc++.h"
#define MAX_ELEMENT 50
using namespace std;

// merge sort starts
void merge(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int a[n1]; // temporary array
    int b[n2]; // temporary array

    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }

    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = b[j];
            k++;
            i++;
        }
    }

    while (i < n1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[k] = b[j];
        k++;
        i++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }
}

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// quick sort starts
int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;

    for (int j = l; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, r);

    return i + 1;
}

void quickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int pi = partition(arr, l, r);

        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, r);
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
    cout << "1. Merge Sort \n2. Quick Sort \n\n";
    cin >> ch;

    switch (ch)
    {
    case 1:
        mergeSort(arr, 0, n);
        cout << "After Merge Sort : ";
        break;
    case 2:
        quickSort(arr, 0, n);
        cout << "After Quick Sort : ";
        break;

    default:
        cout << "Enter correct choice you..." << endl;
        break;
    }

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}