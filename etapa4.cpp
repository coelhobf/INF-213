#include <bits/stdc++.h>
using namespace std;

int custo(const vector<vector<int> > &mapa, const vector<int> &seq)
{
    int custo = 0;

    int i = 0;
    for(; i<seq.size()-1; i++)
    {
        custo+= mapa[seq[i]][seq[i+1]];
    }
    custo+= mapa[seq[i]][seq[0]];

    return custo;
}

int main()
{
    int n;
    cin>>n;

    vector<vector<int> > mapa(n, vector<int>(n));
    vector<int> seq(n);

    for(auto &x: mapa)
    {
        for(auto &z: x)
        {
            cin>> z;
        }
    }

    int i =0;
    for(auto &x: seq)
    {
        x = i;
        i++;
    }

//
    /*for(auto &x: mapa)
    {
        for(auto &z: x)
        {
            cout<< z << " ";
        }
        cout<< "\n";
    }

    for(auto &x: seq)
    {
        cout<< x << " ";
    }
    cout<< "\n";*/
//

    sort(seq.begin(), seq.end());

    int menor = INT_MAX;
    do
    {
        int c = custo(mapa, seq);
        if(c < menor)
        {
            menor = c;
        }
    }
    while(next_permutation(seq.begin(), seq.end()));

    cout << menor << "\n";
}

/* 
        SO      CO
    7   0.006   0.004
    8   0.033   0.005
    9   0.080   0.009
    10  0.741   0.036
    11  8.690   0.337
*/
