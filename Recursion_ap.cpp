//abdul bari example
#include "bits/stdc++.h"
using namespace std;

void fun(int n)
{
    if (n > 0)
    {
        cout << "Hello : ";
        fun(n - 1);
    }
}
int main()
{
    int a = 4;

    fun(a);
}

//Sum till n
#include "bits\stdc++.h"
using namespace std;

int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int prevSum = sum(n - 1);
    return prevSum + n;
}
int main()
{
    int n;
    cin >> n;
    cout << sum(n);
}

//Print inc and decs number
#include "bits\stdc++.h"
using namespace std;

void inc(int n)
{
    if (n == 1)
    {
        cout << "1" << endl;
        return;
    }
    inc(n - 1);
    cout << n << endl;
}

void dec(int n)
{
    if (n == 1)
    {
        cout << "1" << endl;
        return;
    }

    cout << n << endl;
    dec(n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << endl
         << endl;

    inc(n);
    cout << endl
         << endl;
    dec(n);
}

//Fibonacci series
#include "bits\stdc++.h"
using namespace std;

int fib(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}
int main()
{
    int n;
    cin >> n;

    cout << fib(n);
}

//factorial
#include "bits\stdc++.h"
using namespace std;

int fac(int n)
{
    if (n == 1)
    {
        return n;
    }
    return fac(n - 1) * n;
}
int main()
{
    int n;
    cin >> n;
    cout << fac(n);
}

//pth power of n
#include "bits\stdc++.h"
#include<math.h>
using namespace std;

int pow(int n, int p)

{
    if (p == 0)
    {
        return 1;
    }
    int prevpow = pow(n, p - 1);
    return prevpow * n;
}
int main()
{
    int n, p;
    cin >> n >> p;
    cout<<pow(n, p);
}
