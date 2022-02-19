#include"bits/stdc++.h"
using namespace std;

int main()
{
    array <int,5> a = {1,2,3,4,5};

    int size = a.size();

    for(int i=0; i< a.size(); i++)
    {
        cout<<"Element at index " << i <<" is "<< a[i]<<endl;
    }

    cout<<"Element at 2nd index : "<<a.at(2)<<endl;
    cout<<"Empty or not : "<<a.empty()<<endl;

    cout<<"First element : "<<a.front()<<endl;
    cout<<"Last element : "<<a.back()<<endl;

    cout<<"Size of array is : " <<a.size()<<endl;
}