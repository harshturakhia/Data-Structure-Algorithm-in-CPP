long long trappingWater(int arr[], int n)
{
    long long maxLeft = 0;
    long long maxRight = 0;
    long long l = 0;
    long long r = n - 1;
    long long res = 0;

    while (l <= r)
    {
        if (arr[l] <= arr[r])
        {
            if (arr[l] >= maxLeft)
                maxLeft = arr[l];
            else
                res += maxLeft - arr[l];

            l++;
        }
        else
        {
            if (arr[r] >= maxRight)
                maxRight = arr[r];
            else
                res += maxRight - arr[r];

            r--;
        }
    }
    return res;
}