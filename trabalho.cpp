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
    if (string(argv[1]) == "comprimir")
    {
        PPMImage img;
        cin >> img;
        QuadTree tree(img, 1);
        tree.printCompress();
    }
    else if (string(argv[1]) == "descomprimir")
    {
        int tam, maxIntensity;
        cin>> tam >> maxIntensity;
        string img;
        cin>> img;

        QuadTree tree(tam, maxIntensity, img);
        tree.printUncompress();
    }
    else if (string(argv[1]) == "extra")
    {
        PPMImage img;
        cin >> img;
        QuadTree tree(img, 2);
        tree.printCompress();
    }
}
