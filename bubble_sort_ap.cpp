//They should be in ascending order...
//If n elements then do (n-1)tries
//Time - Complexity = O(n`2)
//Repeatedly swap two adjacent numbers if they are in wrong number...

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter limit : ";
    cin >> n;

    int arr[n];
    cout<<"Enter elements of array : "<<endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

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

    cout<<"Displaying the array after sorting... "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

