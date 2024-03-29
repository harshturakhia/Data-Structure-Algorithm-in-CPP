#include <iostream>
#include <queue>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size = size + 1;
        int index = size;

        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;

            // For Max Heap property
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deleteFromHeap()
    {
        if (size == 0)
        {
            cout << "Nothing to delete";
            return;
        }

        // swap first and last
        arr[1] = arr[size];

        // not want to access last node
        size = size - 1;

        // take to its right position
        int i = 1;
        while (i < size)
        {
            int leftIndex = i * 2;
            int rightIndex = (2 * i) + 1;

            if (leftIndex < size && arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
    }

    void heapifys(int arr[], int n, int i)
    {
        if (n == 0)
            return;

        int largest = i;
        int left = 2 * i;
        int right = (2 * i) + 1;

        if (left <= n && arr[largest] < arr[left])
            largest = left;

        if (right <= n && arr[largest] < arr[right])
            largest = right;

        if (largest != i)
        {
            swap(arr[largest], arr[i]);
            heapifys(arr, n, largest);
        }
    }

    void heapSort(int arr[], int n)
    {
        int size = n;

        while (size > 1)
        {
            // step1 : swap
            swap(arr[size], arr[1]);
            size--;

            // step2 : correct position
            heapifys(arr, size, 1);
        }
    }
};

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    // h.print();
    h.deleteFromHeap();
    h.print();

    int n = 5;
    int arr[6] = {-1, 54, 53, 55, 52, 50};

    //build heap or heap creation
    for (int i = n / 2; i > 0; i--)
    {
        h.heapifys(arr, n, i);
    }

    h.heapSort(arr, n);

    cout << "Printing the sorted array elements : \n";
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Priority Queue... \n";
    cout << "Max heap via Priority Queue : \n";

    priority_queue<int> pq;

    pq.push(3);
    pq.push(5);
    pq.push(4);
    pq.push(6);

    cout << "Size is : " << pq.size() << endl;
    cout << "Top element  is : " << pq.top() << endl;

    pq.pop();
    cout << "Top element is : " << pq.top() << endl;

    cout << "Min heap via Priority Queue : \n";

    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(3);
    minHeap.push(5);
    minHeap.push(4);
    minHeap.push(6);

    cout << "Size is : " << minHeap.size() << endl;
    cout << "Top element  is : " << minHeap.top() << endl;

    minHeap.pop();
    cout << "Top element is : " << minHeap.top() << endl;
}