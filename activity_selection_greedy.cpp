// We are given n activities with their start and end time
// Select maximum number of activites but single at a time only

// 1 :
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.

    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second;
    }

    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++)
        {
            pair<int, int> p = make_pair(start[i], end[i]);
            v.push_back(p);
        }

        sort(v.begin(), v.end(), cmp);

        int ansEnd = v[0].second;

        int count = 1;

        for (int i = 1; i < n; i++)
        {
            if (v[i].first > ansEnd)
            {
                count++;
                ansEnd = v[i].second;
            }
        }

        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}

// 2 :
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool static comp(vector<int> &v1, vector<int> &v2)
    {
        if (v1[1] == v2[1])
            return v1[2] < v2[2];
        return v1[1] < v2[1];
    }

    vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F)
    {
        vector<vector<int>> v;

        for (int i = 0; i < N; i++)
        {
            v.push_back({S[i], F[i], i + 1});
        }

        sort(v.begin(), v.end(), comp);

        int j = 0;

        vector<int> ans;

        ans.push_back(v[j][2]);

        for (int i = 1; i < N; i++)
        {
            if (v[i][0] > v[j][1])
            {
                j = i;
                ans.push_back(v[i][2]);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> S(n), F(n);
        for (int i = 0; i < n; i++)
        {
            cin >> S[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> F[i];
        }
        Solution ob;
        vector<int> ans = ob.maxMeetings(n, S, F);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i];
            if (i != ans.size() - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends