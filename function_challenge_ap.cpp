//print prime number between two
#include <iostream>
#include <math.h>
using namespace std;

bool prime(int num)
{
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int a, b;
    cin >> a >> b;

    for (int i = a; i <= b; i++)
    {
        if (prime(i))
        {
            cout << i << endl;
        }
    }
}

//fibonacci series
#include "bits/stdc++.h"
using namespace std;
void fibonacci(int num1)
{
    int t1 = 0;
    int t2 = 1;
    int nextTerm;

    for (int i = 0; i < num1; i++)
    {
        cout << t1;
        nextTerm = t1+t2;   
        t1 = t2;
        t2 = nextTerm;
    }
    return;
}
int main()
{
    int a;
    cin >> a;

    fibonacci(a);
}

//factorial series
#include "bits/stdc++.h"
using namespace std;

int fact(int n1)
{
    int ans = 1;
    for(int i=2; i<=n1; i++)
    {
        ans = ans * i;
    }
    return ans;
}
int main()
{
    int a;
    cin>>a;

    cout<<fact(a);
}