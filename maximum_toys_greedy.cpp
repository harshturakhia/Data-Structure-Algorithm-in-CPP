int toyCount(int N, int K, vector<int> arr)
{
    int ans = 0;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < N; i++)
    {
        if (arr[i] <= K)
        {
            ans++;
            K = K - arr[i];
        }
        else
        {
            break;
        }
    }
    return ans;
}