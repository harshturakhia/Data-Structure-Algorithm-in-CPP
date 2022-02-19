#include"bits/stdc++.h"
using namespace std;

int main()
{
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout<<"Size : "<<q.size()<<endl;
    cout<<"Front element is : "<<q.front()<<endl;
    cout<<"Last element is : "<<q.back()<<endl;

    q.pop();
    cout<<"Size : "<<q.size()<<endl;
    cout<<"Front element is : "<<q.front()<<endl;
    cout<<"Last element is : "<<q.back()<<endl;

    q.pop();
    cout<<"Size : "<<q.size()<<endl;
    cout<<"Front element is : "<<q.front()<<endl;
    cout<<"Last element is : "<<q.back()<<endl;

    q.pop();
    cout<<"Size : "<<q.size()<<endl;
    cout<<"Front element is : "<<q.front()<<endl;
    cout<<"Last element is : "<<q.back()<<endl;

    q.pop();
    cout<<"Size : "<<q.size()<<endl;
    cout<<"Front element is : "<<q.front()<<endl;
    cout<<"Last element is : "<<q.back()<<endl;

}