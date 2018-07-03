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
        QuadTree tree(img);
        tree.print();
    }
    else if (string(argv[1]) == "descomprimir")
    {
        int tam, maxIntensity;
        cin>> tam >> maxIntensity;
        string img;
        cin>> img;

        PPMImage img2(tam, tam, maxIntensity);

        QuadTree tree(img2, true);
        tree.preenchePPMImage(img, tam);
        
        cout<< img2;
    }
}
