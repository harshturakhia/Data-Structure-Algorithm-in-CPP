int Maximize(int a[], int n)
{

    sort(a, a + n);

    long prodSum = 0;
    int c = pow(10, 9) + 7;

    for (int i = 0; i < n; i++)
        prodSum += ((long)a[i] * i) % c;

    return prodSum % c;
}