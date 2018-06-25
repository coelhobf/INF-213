#include <bits/stdc++.h>
#include "MySet.h"

using namespace std;

int main()
{
    char c;
    int n;
    MySet<int> bd;

    while(cin>> c)
    {
        cin>> n;

        if(c == 'C')
        {
            bd.insert(n);
        }
        else
        {
            MySetIterator<int> it = bd.find(n);
            if(it == bd.end())
            {
                cout<< "FALHA" << endl;
                continue;
            }

            it++;
            if(it == bd.end())
            {
                cout<< "FALHA" << endl;
                continue;
            }
            else
            {
                cout<< *it << endl;
            }
        }
    }
}