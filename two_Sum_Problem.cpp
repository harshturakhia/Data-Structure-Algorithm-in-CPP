// TC - O(n^2)

int getPairsCount(int arr[], int n, int k)
{
    int count = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == k)
            {
                count++;
            }
        }
    }
    return count;
}

// TC - O(n)
int getPairsCount(int arr[], int n, int k)
{
    map<int, int> mp;

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int diff = k - arr[i];

        if (mp.find(diff) != mp.end())
            count = count + mp[diff];

        mp[arr[i]]++;
    }
    return count;
}