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

    x_min = 0;
    y_min = 0;
    size = 0;

    isUniform = false;
}

Nodo::Nodo(Nodo *parent, int y_min, int x_min, int size)
{
    for (int i = 0; i < 4; i++)
    {
        quads[i] = 0;
    }
    isUniform = false;

    this->parent = parent;
    this->x_min = x_min;
    this->y_min = y_min;
    this->size = size;
}

void QuadTree::PreencheArvore(Nodo *&root, Nodo *parent, int y_min, int x_min, int size)
{
    assert(y_min >= 0 && x_min >= 0);
    root = new Nodo(parent, y_min, x_min, size);

    root->isUniform = img->isUniform(y_min, x_min, size, root->predominantColor);

    if (!(root->isUniform))
    {
        int newY = y_min + (size / 2);
        int newX = x_min + (size / 2);

        PreencheArvore(root->quads[3], root, y_min, newX, size / 2);
        PreencheArvore(root->quads[2], root, y_min, x_min, size / 2);
        PreencheArvore(root->quads[1], root, newY, x_min, size / 2);
        PreencheArvore(root->quads[0], root, newY, newX, size / 2);
    }
}

int QuadTree::stringToTree(Nodo *root, const string &str, int indice)
{
    if (str[indice + 1] == '(')
    {
        //atribuir ao nodo seu tamanho
        int newY = root->y_min + (root->size / 2);
        int newX = root->x_min + (root->size / 2);

        int newIndice;

        root->quads[0] = new Nodo(root, root->y_min, newX, (root->size / 2));
        root->quads[1] = new Nodo(root, root->y_min, root->x_min, (root->size / 2));
        root->quads[2] = new Nodo(root, newY, root->x_min, (root->size / 2));
        root->quads[3] = new Nodo(root, newY, newX, (root->size / 2));

        newIndice = stringToTree(root->quads[3], str, indice + 1);
        newIndice = stringToTree(root->quads[2], str, newIndice + 1);
        newIndice = stringToTree(root->quads[1], str, newIndice + 1);
        newIndice = stringToTree(root->quads[0], str, newIndice + 1);

        return newIndice + 1;
    }
    else
    {
        Color cor;
        string color;
        vector<string> st;

        int i;
        for (i = indice + 1; true; i++)
        {
            if (str[i] != ',' && str[i] != ')')
            {
                color += str[i];
            }
            else
            {
                st.push_back(color);
                color = "";
            }
            if (str[i] == ')')
            {
                break;
            }
        }

        cor.r = stoi(st[0]);
        cor.g = stoi(st[1]);
        cor.b = stoi(st[2]);

        root->predominantColor = cor;
        root->isUniform = true;

        return i;
    }
}

void QuadTree::treeToPPMImage(Nodo *root)
{
    if (root->isUniform)
    {
        for(int i = root->y_min; i < (root->y_min + root->size); i++)
        {
            for (int j = root->x_min; j < (root->x_min + root->size); j++)
            {
                img->set(i, j, root->predominantColor);
            }
        }
    }
    else
    {
        treeToPPMImage(root->quads[0]);
        treeToPPMImage(root->quads[1]);
        treeToPPMImage(root->quads[2]);
        treeToPPMImage(root->quads[3]);
    }
}

void QuadTree::preenchePPMImage(const string &str, int imgSize)
{
    this->imgSize = imgSize;
    root->size = imgSize;
    root->y_min = 0;
    root->x_min = 0;

    stringToTree(root, str, 0);
    treeToPPMImage(root);
}

QuadTree::QuadTree(const PPMImage &img, bool descomprimir)
{
    this->img = (PPMImage *)&img;
    imgSize = this->img->getRows();
    root = new Nodo();
    if (!descomprimir)
    {
        PreencheArvore(root, 0, 0, 0, imgSize);
    }
}

QuadTree::~QuadTree()
{
    destroy(root);
}

void QuadTree::print(Nodo *root)
{
    if (root->isUniform)
    {
        cout << root->predominantColor.toStr();
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            cout << "(";
            print(root->quads[i]);
            cout << ")";
        }
    }
}

void QuadTree::print()
{
    cout << imgSize << " "
         << img->getMaxCol() << endl;
    cout << "(";
    print(root);
    cout << ")";
}

void QuadTree::destroy(Nodo *root)
{
    if(root->isUniform)
    {
        delete root;
    }
    else
    {
        destroy(root->quads[0]);
        destroy(root->quads[1]);
        destroy(root->quads[2]);
        destroy(root->quads[3]);
    }
}