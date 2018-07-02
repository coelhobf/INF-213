#include <bits/stdc++.h>
#include "QuadTree.h"
#include "PPMImage.h"
using namespace std;

Nodo::Nodo()
{
    parent = 0;
    for (int i = 0; i < 4; i++)
    {
        quads[i] = 0;
    }

    x_min = y_min = size = 0;
}

Nodo::Nodo(Nodo *parent, int y_min, int x_min, int size)
{
    for (int i = 0; i < 4; i++)
    {
        quads[i] = 0;
    }

    this->parent = parent;
    this->x_min = x_min;
    this->y_min = y_min;
    this->size = size;
}

void QuadTree::PreencheArvore(Nodo *&root, Nodo *parent, int y_min, int x_min, int size)
{
    assert(y_min >= 0 && x_min >=0);
    root = new Nodo(parent, y_min, x_min, size);

    root->isUniform = img->isUniform(y_min, x_min, size - 1, root->predominantColor);

    if (!(root->isUniform))
    {
        int newDivisionY = y_min + (size / 2);
        int newDivisionX = x_min + (size / 2);

        PreencheArvore(root->quads[0], root, x_min, newDivisionY, size / 2);
        PreencheArvore(root->quads[1], root, x_min, y_min, size / 2);
        PreencheArvore(root->quads[2], root, newDivisionX, y_min, size / 2);
        PreencheArvore(root->quads[3], root, newDivisionX, newDivisionY, size / 2);
    }
}

QuadTree::QuadTree(const PPMImage &img)
{
    this->img = (PPMImage *)&img;
    imgSize = this->img->getRows();

    PreencheArvore(root, 0, 0, 0, imgSize);
}

void QuadTree::print(Nodo *root)
{
    if (root->isUniform)
    {
        cout << root->predominantColor.r << "," << root->predominantColor.g << "," << root->predominantColor.b;
    }
    else
    {
        cout << "(";
        for (int i = 0; i < 4; i++)
        {
            cout << "(";
            print(root->quads[i]);
            cout << ")";
        }
        cout << ")";
    }
}

void QuadTree::print()
{
    cout<< this->imgSize << " " << "255" << endl;
    print(root);
}