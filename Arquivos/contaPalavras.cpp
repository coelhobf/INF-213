#include <bits/stdc++.h>
using namespace std;

int main(int a, char* b[])
{
    string modo = b[1];

    if(modo == "myvec")
    {
        int quant = 0;
        string str;
        vector<string> v;

        while(cin>> str)
        {
            bool insere = true;
            quant++;
            for(auto &x: v)
            {
                if(x == str)
                {
                    insere = false;
                    break;
                }
            }

            if(insere)
            {
                v.push_back(str);
            }
        }

        cout<< quant << " " << v.size() << endl;
    }
    else
    {
        int quant = 0;
        string str;
        set<string> v;

        while(cin>> str)
        {
            bool insere = true;
            quant++;

            v.insert(str);
        }

        cout<< quant << " " << v.size() << endl;
    }
}