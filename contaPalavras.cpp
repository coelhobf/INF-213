#include <bits/stdc++.h>
using namespace std;

int main(int a, char *b[])
{
    string modo = b[1];

    if (modo == "myvec")
    {
        int quant = 0;
        string str;
        vector<string> v;

        while (cin >> str)
        {
            bool insere = true;
            quant++;
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i] == str)
                {
                    insere = false;
                    break;
                }
            }

            if (insere)
            {
                v.push_back(str);
            }
        }

        cout << quant << " " << v.size() << endl;
    }
    else
    {
        int quant = 0;
        string str;
        set<string> v;

        while (cin >> str)
        {
            bool insere = true;
            quant++;

            v.insert(str);
        }

        cout << quant << " " << v.size() << endl;
    }
}