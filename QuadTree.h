#ifndef QUADTREE_H
#define QUADTREE_H

#include <bits/stdc++.h>
#include "PPMImage.h"
using namespace std;

class Nodo
{
  public:
	Nodo *parent;
	Nodo *quads[4];

	Color predominantColor;
	bool isUniform;

	int x_min;
	int y_min;
	int size;

	Nodo();
	Nodo(Nodo *parent, int y_min, int x_min, int size);
};

class QuadTree
{
private: //atributos
	Nodo *root;
	PPMImage *img;
	string *str;
	int imgSize;

private: //metodos
	void PPMToTree(Nodo *&root, Nodo *parent, int y_min, int x_min, int size, int typeCompress);
	int  stringToTree(Nodo *root, int indice);

	void treeToPPMImage(Nodo *root);
	void treeToString(Nodo * root);

	void copiaNodos(Nodo *parent, Nodo *root, Nodo *other);
	void destroy(Nodo *root);

	bool extraUniform(int y_min, int x_min, int size, Color &predominantColor);

public: //metodos
	QuadTree(const QuadTree &other);
	QuadTree(const PPMImage &img, int typeCompress);
	QuadTree(int tam, int maxIntensity, const string &str);
	~QuadTree();

	string toString();
	PPMImage toPPMImage();
	
	void printCompress();
	void printUncompress();
};

#endif