// 1st approach
void immediateSmaller(vector<int> &arr, int n)
{
    //  code here
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[i + 1])
            arr[i] = arr[i + 1];
        else
            arr[i] = -1;
    }
    arr[n - 1] = -1;
}

// 2nd approach
void immediateSmaller(vector<int> &arr, int n)
{
    //  code here
    stack<int> s;
    s.push(-1);

    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];

        while (s.top() >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }

    return ans;
}