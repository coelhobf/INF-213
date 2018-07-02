#include <bits/stdc++.h>
using namespace std;

//Observacoes:
//-- Atencao: C++11 e' necessario para compilar este codigo

#include "PPMImage.h" //nao modifique a classe PPMImage!!!
#include "QuadTree.h"

//--------------------------------
//Implemente seu trabalho a partir daqui... (crie outros arquivos .h/.cpp se necessario)

int main(int argc, char **argv)
{
    PPMImage img;
    cin >> img;

    QuadTree tree(img);
    tree.print();
}
