//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
        long long minCost(long long arr[], long long n)
    {
        long long cost = 0, a, b, sum;

        priority_queue<long long, vector<long long>, greater<long long>> pq;

        for (int i = 0; i < n; i++)
        {
            pq.push(arr[i]);
        }

        while (pq.size() > 1)
        {
            a = pq.top();
            pq.pop();

            b = pq.top();
            pq.pop();

            long long mergeLength = a + b;
            cost += mergeLength;
            pq.push(mergeLength);
        }

        return cost;
    }
};

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
