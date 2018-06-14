#include <bits/stdc++.h>
#include "MySet.h"
using namespace std;

template <class T>
int inserctionSort(vector<T> &v)
{
    int count = 0;
    for (int i = 1; i < v.size(); i++)
    {
        int x = v[i];
        int j = i - 1;

        while ((j >= 0) && (v[j] > x))
        {
            v[j + 1] = v[j];
            j--;
            count++;
        }

        v[j + 1] = x;
    }
    return count;
}

template <class T>
int tree(vector<T> &v)
{
    int count = 0;
    MySet<int> tree;
    for (auto &x : v)
    {
        pair<MySetIterator<T>, bool> p = tree.insert(x);
    }
    return tree.getMov();
}

int main()
{
    string metodo;
    int n;

    cin >> metodo;
    cin >> n;
    vector<int> v(n);

    for (auto &x : v)
    {
        cin >> x;
    }

    if (metodo == "ORDENAR")
    {
        cout << inserctionSort(v) << endl;
    }
    else
    {
        cout << tree(v) << endl;
    }
}