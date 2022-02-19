//#1 = printing larger number

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int mx = -19999;
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        mx = max(mx, arr[i]);
        cout << mx;
    }
}

//#2 = sum of all sub-array elements of array

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
    }

    int current = 0;

    for (int i = 0; i < n - 1; i++)
    {
        current = 0;

        for (int j = i; j < n - 1; j++)
        {
            current = current + arr[j];
            cout << arr[j];
        }
    }
}

//#3 = longest arithmatic sub-array
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int ans = 2;
    int pd = a[1] - a[0];
    int current = 2;
    int j = 2;

    while (j < n)
    {
        if (pd == a[j] - a[j - 1])
        {
            current++;
        }
        else
        {
            pd = a[j] - a[j - 1];
            current = 2;
        }

        ans = max(ans, current);
        j++;
    }
    cout << ans << endl;
}

//#4 = maximum 

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];

    int count=0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i < n+1; i++)
    {
            if (a[i] > a[i - 1] && a[i] > a[i + 1])
            {
                count++;
            }
    }
    cout<<count<<endl;
}

//#4 = maximum 

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n+1];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if(n == 1)
    {
        cout<<"1"<<endl;
        return 0;
    }

    int ans = 0;
    int mx = -1;

    for(int i=0; i<n; i++)
    {
        if(a[i]>mx && a[i]>a[i+1])
        {
            ans++;
        }
        mx = max(mx, a[i]);
    }
    cout<<ans<<endl;
    return 0;
}

//#5 = find first repeating element
//doubt
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    const int N = 1e6+2;

    int idx[N];

    for(int i=0; i<N; i++)
    {
        idx[i] = -1;
    }

    int minidx = INT_MAX;

    for(int i=0; i<n; i++)
    {
        if(idx[a[i]] != -1)
        {
            minidx = min(minidx, idx[a[i]]);
        }
        else
        {
            idx[a[i]] = i;
        }
    }
    if(minidx == INT_MAX)
    {
        cout<<"-1"<<endl;
    }
    else
    {
        cout<<minidx+1<<endl;
    }
}

//#6 = find maximum number of sub-array of arrays

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j;k++)
            {
                cout<<a[k]<<" ";
            }
            cout<<endl;
        }
    }
}

//#7 =  find maximum sum of sub-array of array

#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
             int sum = 0;
            for (int k = i; k <= j;k++)
            {
                sum = sum + a[k];
            }
            maxSum = max(maxSum,sum);
        }
    }
        cout<<maxSum;
}

//#8 =  find maximum sum of sub-array of array (Cummalative approach)

#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    int maxSum = INT_MIN;

    int currsum[n+1];
    currsum[0] = 0;

    for(int i=1; i<=n; i++)
    {
        currsum[i] = currsum[i-1] = a[i-1];
    }

    int maxSum = INT_MIN;

    for(int i=1; i<=n; i++)
    {
        int sum=0;
        for(int j=0; j=i-1;j++)
        {
            sum = currsum[i] - currsum[j];
            maxSum = max(maxSum, sum);
        }
    }
        cout<<maxSum;
}

//#9 =  find maximum sum of sub-array of array (Kadane's Algorithm)

#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    int maxSum = INT_MIN;
    int currSum = 0;

    for(int i=0; i<n; i++)
    {
        currSum = currSum + a[i];
        if(currSum < 0)
        {
            currSum = 0;
        }
        maxSum = max(maxSum, currSum);
    }
    cout<<maxSum;
}

//#10 =   
