//1st Approach but higher TC
// TC = O(n*k)

vector<int> max_of_subarrays(int *arr, int n, int k)
{
    // your code here
    vector<int> ans;
    int max = 0;

    for (int i = 0; i <= n - k; i++)
    {
        max = arr[i];

        for (int j = 1; j < k; j++)
        {
            if (arr[i + j] > max)
                max = arr[i + j];
        }
        ans.push_back(max);
    }
    return ans;
}

//2nd Approach but lower TC
// TC = O(n * logk)

