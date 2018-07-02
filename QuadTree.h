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
  private:
	Nodo *root;

	PPMImage *img;

	int imgSize;

	void PreencheArvore(Nodo *&root, Nodo *parent, int y_min, int x_min, int size);
	void print(Nodo *root);

  public:
	QuadTree(const PPMImage &img);
	void print();
};

#endif