#include "bits/stdc++.h"
#define MAX_ELEMENT 50
using namespace std;

void selectionSort(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[j] < arr[i])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    
    cout<<"After Selection Sort : ";

}

void bubbleSort(int arr[], int n)
{
    int counter = 1;

    while (counter < n)
    {
        for (int i = 0; i < n - counter; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        counter++;
    }
    
    cout<<"After Bubble Sort : ";
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int j = (i - 1);    

        while (arr[j] > current && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
    
    cout<<"After Insertion Sort : ";

}


int main()
{
    int arr[MAX_ELEMENT];
    int n = 10;

    for(int i=0; i<n; i++)
    {
        arr[i] = rand() % MAX_ELEMENT;
    }

    cout<<"Before Sorting : \n";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;

    int ch;
    cout<<"Enter which sorting algo to use : "<<endl;
    cout<<"1. Selection Sort \n2. Bubble Sort \n3. Insertion Sort \n\n";
    cin>>ch;
    
    switch(ch)
    {
        case 1:
            selectionSort(arr, n);
            break;
        case 2:
            bubbleSort(arr, n);
            break;
        case 3:
            insertionSort(arr, n);
            break;
        default:
            cout<<"Enter correct choice you fucker..."<<endl;
            break;
    }

    cout<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
#include "bits/stdc++.h"
#define MAX_ELEMENT 50
using namespace std;

void selectionSort(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[j] < arr[i])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    
    cout<<"After Selection Sort : ";

}

void bubbleSort(int arr[], int n)
{
    int counter = 1;

    while (counter < n)
    {
        for (int i = 0; i < n - counter; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        counter++;
    }
    
    cout<<"After Bubble Sort : ";
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int j = (i - 1);    

        while (arr[j] > current && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
    
    cout<<"After Insertion Sort : ";

}


int main()
{
    int arr[MAX_ELEMENT];
    int n = 10;

    for(int i=0; i<n; i++)
    {
        arr[i] = rand() % MAX_ELEMENT;
    }

    cout<<"Before Sorting : \n";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;

    int ch;
    cout<<"Enter which sorting algo to use : "<<endl;
    cout<<"1. Selection Sort \n2. Bubble Sort \n3. Insertion Sort \n\n";
    cin>>ch;
    
    switch(ch)
    {
        case 1:
            selectionSort(arr, n);
            break;
        case 2:
            bubbleSort(arr, n);
            break;
        case 3:
            insertionSort(arr, n);
            break;
        default:
            cout<<"Enter correct choice you fucker..."<<endl;
            break;
    }

    cout<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
