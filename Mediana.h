#ifndef MEDIANA_H
#define MEDIANA_H

#include <bits/stdc++.h>
#include "MyPriorityQueue.h"

using namespace std;

class Mediana
{
  public:
    Mediana();

    void insere(int);
    int getMediana();
    int size();

    friend ostream &operator<<(ostream &, const Mediana &);

  private:
    MyPriorityQueue<int> d1, d2;
};

#endif
