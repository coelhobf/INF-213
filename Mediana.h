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

    friend ostream &operator<<(ostream &, const Mediana &);
    int size();

  private:
    MyPriorityQueue<int> data;
    int left;
    int hasLeft;
};

#endif