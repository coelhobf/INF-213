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

QuadTree::QuadTree(const QuadTree &other)
{
	img = new PPMImage(*(other.img));
	str = new string(*(other.str));
	imgSize = other.imgSize;

    copiaNodos(0, root, other.root);
}

QuadTree::QuadTree(const PPMImage &img, int typeCompress)
{
    this->img = new PPMImage(img);
    this->str = new string();

    imgSize = this->img->getRows();
    root = new Nodo();

    PPMToTree(root, 0, 0, 0, imgSize, typeCompress);
    *str += "(";
    treeToString(root);
    *str += ")";
}

QuadTree::QuadTree(int tam, int maxIntensity, const string &str)
{
    this->str = new string(str);
    this->img = new PPMImage(tam, tam, maxIntensity);

    imgSize = this->img->getRows();
    root = new Nodo();

    root->size = imgSize;
    stringToTree(root, 0);
    treeToPPMImage(root);
}

QuadTree::~QuadTree()
{
    destroy(root);
}

void QuadTree::PPMToTree(Nodo *&root, Nodo *parent, int y_min, int x_min, int size, int typeCompress)
{
    assert(y_min >= 0 && x_min >= 0);
    root = new Nodo(parent, y_min, x_min, size);

    if (typeCompress == 1)
    {
        root->isUniform = img->isUniform(y_min, x_min, size, root->predominantColor);
    }
    else
    {
        root->isUniform = extraUniform(y_min, x_min, size, root->predominantColor);
    }

    if (!(root->isUniform))
    {
        int newY = y_min + (size / 2);
        int newX = x_min + (size / 2);

        PPMToTree(root->quads[3], root, y_min, newX, size / 2, typeCompress);
        PPMToTree(root->quads[2], root, y_min, x_min, size / 2, typeCompress);
        PPMToTree(root->quads[1], root, newY, x_min, size / 2, typeCompress);
        PPMToTree(root->quads[0], root, newY, newX, size / 2, typeCompress);
    }
}

int QuadTree::stringToTree(Nodo *root, int indice)
{
    if ((*str)[indice + 1] == '(')
    {
        //atribuir ao nodo seu tamanho
        int newY = root->y_min + (root->size / 2);
        int newX = root->x_min + (root->size / 2);

        int newIndice;

        root->quads[0] = new Nodo(root, root->y_min, newX, (root->size / 2));
        root->quads[1] = new Nodo(root, root->y_min, root->x_min, (root->size / 2));
        root->quads[2] = new Nodo(root, newY, root->x_min, (root->size / 2));
        root->quads[3] = new Nodo(root, newY, newX, (root->size / 2));

        newIndice = stringToTree(root->quads[3], indice + 1);
        newIndice = stringToTree(root->quads[2], newIndice + 1);
        newIndice = stringToTree(root->quads[1], newIndice + 1);
        newIndice = stringToTree(root->quads[0], newIndice + 1);

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
            if ((*str)[i] != ',' && (*str)[i] != ')')
            {
                color += (*str)[i];
            }
            else
            {
                st.push_back(color);
                color = "";
            }
            if ((*str)[i] == ')')
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

void QuadTree::treeToString(Nodo *root)
{
    if (root->isUniform)
    {
        (*str) += root->predominantColor.toStr();
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            (*str) += "(";
            treeToString(root->quads[i]);
            (*str) += ")";
        }
    }
}

string QuadTree::toString()
{
    return *str;
}

PPMImage QuadTree::toPPMImage()
{
    return *img;
}

void QuadTree::printCompress()
{
    cout << imgSize << " "
         << img->getMaxCol() << endl;
    cout << *str << endl;
}

void QuadTree::printUncompress()
{
    cout<< *img << endl;
}

void QuadTree::copiaNodos(Nodo *parent, Nodo *root, Nodo *other)
{
    if(other->isUniform)
    {
        root = new Nodo(parent, other->y_min, other->x_min, other->size);
    }
    else
    {
        copiaNodos(root, root->quads[0], other->quads[0]);
        copiaNodos(root, root->quads[1], other->quads[1]);
        copiaNodos(root, root->quads[2], other->quads[2]);
        copiaNodos(root, root->quads[3], other->quads[3]);
    }
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

bool QuadTree::extraUniform(int y_min, int x_min, int size, Color &predominantColor)
{
    predominantColor = img->get(y_min, x_min);
	if (size == 1)
	{
        return true;
    }

    vector<int> med[3];
    med[0].reserve(size * size);
    med[1].reserve(size * size);
    med[2].reserve(size * size);

    int mi[3] = {255};
	int ma[3] = {0};

	map<array<int, 3>, int> s;
    for (int i = y_min; i < y_min + size; i++)
	{
        for (int j = x_min; j < x_min + size; j++)
		{
			med[0].push_back(img->get(i, j).r);
            med[1].push_back(img->get(i, j).g);
            med[2].push_back(img->get(i, j).b);

			s[{img->get(i, j).r / 10, img->get(i, j).g / 10, img->get(i, j).b / 10}]++;

			mi[0] = min(mi[0], img->get(i, j).r);
			mi[1] = min(mi[1], img->get(i, j).g);
			mi[2] = min(mi[2], img->get(i, j).b);
			ma[0] = max(ma[0], img->get(i, j).r);
			ma[1] = max(ma[1], img->get(i, j).g);
			ma[2] = max(ma[2], img->get(i, j).b);
		}
    }

    int avg[3] = {0};

    sort(med[0].begin(), med[0].end());
    sort(med[1].begin(), med[1].end());
    sort(med[2].begin(), med[2].end());

    avg[0] = (med[0][med[0].size()/2 -1] + med[0][med[0].size()/2])/2;
    avg[1] = (med[1][med[1].size()/2 -1] + med[1][med[1].size()/2])/2;
    avg[2] = (med[2][med[2].size()/2 -1] + med[2][med[2].size()/2])/2;
    
	predominantColor.r = avg[0];
	predominantColor.g = avg[1];
	predominantColor.b = avg[2];

	int countCloseToAvg = 0;
	for (int i = y_min; i < y_min + size; i++)
		for (int j = x_min; j < x_min + size; j++)
		{
			const Color &pixel = img->get(i, j);
			int mxDist = max(max(pixel.r - predominantColor.r, pixel.g - predominantColor.g), pixel.b - predominantColor.b);
			if (mxDist < 255 * 0.04)
				countCloseToAvg++;
		}
	return (countCloseToAvg >= size * size * 0.97);
}