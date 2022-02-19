#include<iostream>
#include<deque>
using namespace std;

int main()
{
    deque <int> dq;
    dq.push_back(1);
    dq.push_back(2);
    
    dq.push_front(3);
    dq.push_front(4);

    for(auto i : dq)
    {
        cout<<i<<endl;
    }

    dq.pop_back();
    dq.pop_front();

    for(auto i : dq)
    {
        cout<<i<<endl;
    }
    cout<<dq.size();

}

//Sliding window maximum

#include "bits/stdc++.h"
using namespace std;

int main()
{
    int key,n;
    int arr;

    cout<<"Enter key : ";
    cin>>key;

    cout<<"enter limit : ";
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

}
