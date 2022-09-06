long long getMaxArea(long long arr[], int n)
{
    stack<long long> st;
    long long maxArea = 0;
    long long i = 0;

    while (i < n)
    {
        if (st.empty() or arr[st.top()] <= arr[i])

            st.push(i++);

        else
        {
            long long tp = st.top();
            st.pop();
            long long ans = arr[tp] * (st.empty() ? i : i - st.top() - 1);
            maxArea = max(maxArea, ans);
        }
    }
    while (!st.empty())
    {
        long long tp = st.top();
        st.pop();
        long long ans = arr[tp] * (st.empty() ? i : i - st.top() - 1);
        maxArea = max(maxArea, ans);
    }
    return maxArea;
}