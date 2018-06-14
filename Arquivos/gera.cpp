#include <bits/stdc++.h>
using namespace std;

int main(int a, char **b)
{
    int n;
    n = atoi(b[1]);

    srand(time(0));

    cout << "ORDENAR" << endl;
    cout << n << endl;
    cerr << "ARVORE" << endl;
    cerr << n << endl;

    for (int i = 0; i < n; i++)
    {
        int a = rand() % n;
        cout << a << " ";
        cerr << a << " ";
    }
    cout << endl;
    cerr << endl;
}