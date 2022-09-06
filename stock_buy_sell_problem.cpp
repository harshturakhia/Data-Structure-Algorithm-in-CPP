#include "bits/stdc++.h"
using namespace std;

vector<int> stockSpan(vector<int> prices)
{
    vector<int> ans;

    stack<pair<int, int>> s;

    for (auto i : prices)
    {
        int days = 1;
        while (!s.empty() && s.top().first <= i)
        {
            days += s.top().second;
            s.pop();
        }
        s.push(make_pair(i, days));
        ans.push_back(days);
    }
    return ans;
}

int main()
{
    // int n = 7;
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};

    vector<int> res = stockSpan(prices);

    for (auto i : res)
    {
        cout << "No of previous days on which prices were lesser or equal :  " << i << endl;
    }
    cout << endl;
}

// 2nd way
vector<vector<int>> stockBuySell(vector<int> A, int n)
{
    int s = 0, e = 0;
    vector<vector<int>> res;
    for (int i = 1; i < n; i++)
    {
        if (A[i - 1] < A[i])
        {
            e = i;
        }
        else
        {
            res.push_back({s, e});
            s = i;
            e = i;
        }
    }

    if (e == n - 1)
        res.push_back({s, e});
    if (res.size() == n)
        return {};

    return res;
}