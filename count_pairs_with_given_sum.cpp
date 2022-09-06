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