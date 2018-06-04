#include <bits/stdc++.h>
#include "Mediana.h"

using namespace std;

void Mediana::heap(int pos)
{
    if (pos == 0)
    {
        return;
    }

    int i;

    if (pos % 2 == 0) //filho 2
    {
        i = (pos - 2) / 2;
    }
    else //filho 1
    {
        i = (pos - 1) / 2;
    }

    if (data[pos] > data[i])
    {
        swap(data[pos], data[i]);
        heap(i);
    }
}

void Mediana::insere(int x)
{
    data.push_back(x);
    heap(data.size() - 1);
}

int Mediana::getMediana()
{
    int i = data.size();

    if (i % 2 == 0) //par
    {
        return (data[i / 2 - 1] + data[i / 2]) / 2;
    }
    else
    {
        return data[i / 2];
    }
}

ostream &operator<<(ostream &os, const Mediana &med)
{
    for (int i = 0; i < med.data.size(); i++)
    {
        cout<< med.data[i] << " ";
    }
    cout<< endl;

    return os;
}
