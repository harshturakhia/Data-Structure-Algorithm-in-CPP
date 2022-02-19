//sum of n number
#include "bits/stdc++.h"
using namespace std;

int_fast32_t sum(int n)
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = ans + i;
    }
    return ans;
}
int main()
{
    int a;
    cin >> a;
    cout<<sum(a);
}

//pythagoras triplet or not

#include "bits/stdc++.h"
using namespace std;

bool check(int x, int y, int z)
{
    int a = max(x, max(y,z));
    int b,c;

    if(a==x)
    {
        b=y;
        c=z;
    }
    else if(a==y)
    {
        b=x;
        c=z;
    }
    else
    {
        b=x;
        c=y;
    }

    if(a*a == b*b + c*c)
        return true;
    else
        return false;
}
int main()
{
    int x,y,z;
    cin >> x >> y >> z;
    
    if(check(x,y,z))
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
}

