#include "bits/stdc++.h"
using namespace std;

/*
    1) Map = it will print inorder which we have inserted
    2) Unordered Map = it will print in any order (No sequence)

*/

int main()
{
    // Creation
    map<string, int> m;

    // Insertion

    // 1 :
    pair<string, int> pair1 = make_pair("Harsh", 1);
    m.insert(pair1);

    // 2 :
    pair<string, int> pair2("Turakhia", 2);
    m.insert(pair2);

    // 3 :
    m["Khushi"] = 3;

    // Updated value of Khushi key
    m["Khushi"] = 4;

    // Searching
    cout << m["Harsh"] << endl;
    cout << m.at("Turakhia") << endl;

    // cout << m.at("Wrong");      // unaccepted valuee - cancelled
    cout << m["Wrong"] << endl; // will make an key value pair with value = 0

    // Size
    cout << m.size() << endl;

    // Checking
    cout << m.count("Bro") << endl;
    cout << m.count("Khushi") << endl;

    // Erase
    m.erase("Turakhia");
    cout << m.size() << endl;

    // Traverse

    // 1 :
    // for (auto i : m)
    //     cout << i->first << " " << i->second << endl;

    // 2 :
    map<string, int>::iterator it = m.begin();

    while (it != m.end())
    {
        cout << it->first << " " << it->second << endl;
        it++;
    }
}