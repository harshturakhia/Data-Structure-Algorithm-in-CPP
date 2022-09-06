void heapifys(vector<int> &arr, int n, int i)
{
    if (n == 0)
        return;

    int largest = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    if (left < n && arr[largest] < arr[left])
        largest = left;

    if (right < n && arr[largest] < arr[right])
        largest = right;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapifys(arr, n, largest);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    // your code here

    vector<int> c;

    for (int i = 0; i < a.size(); i++)
    {
        c.push_back(a[i]);
    }
    for (int i = 0; i < b.size(); i++)
    {
        c.push_back(b[i]);
    }

    int p = c.size();

    for (int i = (p / 2) - 1; i >= 0; i--)
    {
        heapifys(c, p, i);
    }

    return c;
}