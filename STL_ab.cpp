#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector <int> v = {2,4,6,8,10};
    v.push_back(20);    //add new entry at-last
    v.push_back(30);    //add new entry at-last
    v.pop_back();       //deletes last entry

    for(int x:v)
    {
        cout<<x<<endl;
    }
}