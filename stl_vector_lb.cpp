#include"bits/stdc++.h"
using namespace std;

int main()
{
    vector<int> v;
    //size will be zero here

    cout<<"Size : "<<v.size()<<endl;
    cout<<"Capacity : "<<v.capacity()<<endl;

    v.push_back(1);
    cout<<"Pushed element 1..."<<endl;
    cout<<"Size : "<<v.size()<<endl;
    cout<<"Capacity : "<<v.capacity()<<endl;

    v.push_back(2);
    cout<<"Pushed element 2..."<<endl;
    cout<<"Size : "<<v.size()<<endl;
    cout<<"Capacity : "<<v.capacity()<<endl;

    v.push_back(3);
    cout<<"Pushed element 3..."<<endl;
    cout<<"Size : "<<v.size()<<endl;
    cout<<"Capacity : "<<v.capacity()<<endl;

    cout<<"Element at 2 index : "<<v.at(2)<<endl;

    cout<<"First element : "<<v.front()<<endl;
    cout<<"Last element : "<<v.back()<<endl;

    cout<<"Before pop : ";
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i];
    }cout<<endl;


    v.pop_back();


    cout<<"After pop : ";
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i];
    }cout<<endl;



}