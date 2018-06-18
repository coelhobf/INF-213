#include <bits/stdc++.h>
#include "MyMap.h"

using namespace std;

int main()
{
    MyMap<string, int> m;
    string s;
    vector<string> v;
    int i=0;
    while(cin>> s)
    {
        v.push_back(s);
        if(m.find(s) == m.end())
        {
            m[s] = i;
            i++;
        }
    }

    for(int i=0; i<v.size(); i++)
    {
        cout<< v[i] << " " << m[v[i]] << "\n";
    }
}