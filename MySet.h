#ifndef MY_SET_LIST_H
#define MY_SET_LIST_H

#include <bits/stdc++.h> //classe pair esta aqui...
using namespace std;

template <class T>
class MySetIterator;

template <class T>
class Node
{
  public: //classe auxiliar.. vamos utiliza-la apenas neste arquivo (nao e' muito necessario ter encapsulamento)
	Node(const T &elem_) : elem(elem_), left(NULL), right(NULL), count(1), subSz(0) {}
	Node<T> *left, *right;
	T elem;
	int count;
	int subSz;

	void print()
	{
		cout << "{ " << elem << " c: " << count << " sS: " << subSz << " }";
	}
};

template <class T>
class MySet
{
	typedef MySetIterator<T> iterator;

  public:
	int size() const;
	MySet() : size_(0), root(NULL), movimentos(0) {}

	pair<iterator, bool> insert(const T &elem); //retorna um iterador para o elemento inserido (o valor booleano sera' true se o elemento nao existia no conjunto e falso caso ele ja exista (ou seja, o novo elemento nao foi inserido) ).
	iterator find(const T &elem);				//por simplicidade, nao vamos deixar implementar um find constante...

	iterator end() { return iterator(NULL); }; //por enquanto nao vamos ter um metodo "begin()"

	MySet(const MySet &other);
	MySet &operator=(const MySet &other);
	~MySet();

	void print();
	long long int getMov(){return movimentos;}

  private:
	Node<T> *root;
	int size_;

	//funcoes auxiliares...
	pair<iterator, bool> insert(const T &elem, Node<T> *&root);
	iterator find(const T &elem, Node<T> *root);

	void deleteNodes(Node<T> *root);
	Node<T> *copyNodes(const Node<T> *root) const;

	void print(Node<T> *root);
	long long int sum(Node<T> *root, const T &elem);
	int count(Node<T> *root);

	long long int movimentos;
};

//por enquanto vamos desconsiderar os operadores ++ e -- em conjuntos...
//tais operadores serao "escondidos"
template <class T>
class MySetIterator
{
	friend class MySet<T>;

  public:
	MySetIterator(Node<T> *ptr_) : ptr(ptr_) {}
	T &operator*() { return ptr->elem; }

	bool operator==(const MySetIterator &other) const { return ptr == other.ptr; }
	bool operator!=(const MySetIterator &other) const { return ptr != other.ptr; }

  private:
	Node<T> *ptr;
};

template <class T>
MySet<T>::MySet(const MySet &other)
{
	size_ = 0;
	root = NULL;
	*this = other; //vamos usar o operador de atribuicao..
}

template <class T>
void MySet<T>::deleteNodes(Node<T> *root)
{
	if (!root)
		return;
	deleteNodes(root->left);
	deleteNodes(root->right);
	delete root;
}

template <class T>
MySet<T>::~MySet()
{
	deleteNodes(root);
}

template <class T>
Node<T> *MySet<T>::copyNodes(const Node<T> *root) const
{
	if (root == NULL)
	{ //caso base
		return NULL;
	}
	Node<T> *ans = new Node<T>(root->elem);
	ans->left = copyNodes(root->left);
	ans->right = copyNodes(root->right);

	return ans;
}

template <class T>
MySet<T> &MySet<T>::operator=(const MySet &other)
{
	if (this == &other)
		return *this; //testa auto-atribuicao...
	root = copyNodes(other.root);
	size_ = other.size_;
}

template <class T>
int MySet<T>::size() const
{
	return size_; //exercicio: como calcular o tamanho de forma dinamica? (i.e., sem armazenar o inteiro "size" na classe)
}

//funcao auxiliar...
//exercicio: por que a raiz precisa ser passada por referencia?
template <class T>
pair<typename MySet<T>::iterator, bool> MySet<T>::insert(const T &elem, Node<T> *&root)
{ //retorna um iterador para o elemento inserido (o valor booleano sera' true se o elemento nao existia no conjunto e falso caso ele ja exista (ou seja, o novo elemento nao foi inserido) ).
	if (!root)
	{
		root = new Node<T>(elem);
		size_++;
		root->subSz++;
		return make_pair(iterator(root), true);
	}
	else
	{
		root->subSz++;
		if (root->elem > elem)
		{
			return insert(elem, root->left);
		}
		else if (root->elem < elem)
		{
			return insert(elem, root->right);
		}
		else
		{
			root->count++;
			return make_pair(iterator(root), false); //igual..
		}
	}
}

template <class T>
pair<typename MySet<T>::iterator, bool> MySet<T>::insert(const T &elem)
{ //retorna um iterador para o elemento inserido (o valor booleano sera' true se o elemento nao existia no conjunto e falso caso ele ja exista (ou seja, o novo elemento nao foi inserido) ).
	pair<typename MySet<T>::iterator, bool> p = insert(elem, root);
	movimentos += sum(root, elem);
	return p;
}

//funcao auxiliar...
template <class T>
typename MySet<T>::iterator MySet<T>::find(const T &elem, Node<T> *root)
{ //retorna um iterador para o elemento inserido (o valor booleano sera' true se o elemento nao existia no conjunto e falso caso ele ja exista (ou seja, o novo elemento nao foi inserido) ).
	if (!root)
	{
		return iterator(NULL);
	}
	else
	{
		if (root->elem > elem)
			return find(elem, root->left);
		else if (root->elem < elem)
			return find(elem, root->right);
		else
			return iterator(root); //igual..
	}
}

template <class T>
typename MySet<T>::iterator MySet<T>::find(const T &elem)
{
	find(elem, root);
}

template <class T>
void MySet<T>::print(Node<T> *root)
{
	if(root)
	{
		root->print();
		print(root->left);
		print(root->right);
	}
	else
	{
		return;
	}
}

template <class T>
void MySet<T>::print()
{
	print(root);
	cout<< endl;
}

template <class T>
int MySet<T>::count(Node<T> *root)
{
	if(!root)
	{
		return 0;
	}
	else
	{
		return root->subSz;
	}
}

template <class T>
long long int MySet<T>::sum(Node<T> *root,const T &elem)
{
	if(!root)
	{
		return 0;
	}

	long long int soma = 0;

	if(root->elem > elem)
	{
		soma += count(root->right);
		soma += root->count;
		soma += sum(root->left, elem);
	}

	if(root->elem < elem)
	{
		soma += sum(root->right, elem);
	}

	if(root->elem == elem)
	{
		soma += count(root->right);
	}

	return soma;

}

#endif