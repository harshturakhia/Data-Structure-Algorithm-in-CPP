#include"bits/stdc++.h"
using namespace std;

int main()
{
    stack<string> s;

    s.push("Harsh");
    s.push("Vipesh");
    s.push("Turakhia");

    cout<<"Top element : "<<s.top()<<endl;
    cout<<"Size is : "<<s.size()<<endl;
    cout<<"Empty or not : "<<s.empty()<<endl;
   
    int size = s.size();

    // cout<<"Before pop : ";
    // for(int i=0; i<size; i++)
    // {
    //     cout<<s[i];
    // }
    // cout<<endl;

    s.pop();
    cout<<"Top element : "<<s.top()<<endl;


    // cout<<"After pop : ";
    // for(int i=0; i<size; i++)
    // {
    //     cout<<s[i]<<"   ";
    // }
    // cout<<endl;

}