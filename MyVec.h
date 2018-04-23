/*
TAD MyVec
- Representa uma lista implementada por contiguidade
- Interface similar a da classe Vector do STL
- Criado por Salles Magalhaes em 19/02/2018

*/

#ifndef MyVec_H__
#define MyVec_H__

#include <iostream>
#include <string>
#include <ostream>


//Excessao usada pela classe MyVec
class MyVecException {
private:
	std::string msg;
public:
	MyVecException (const std::string &msg0): msg(msg0) { }
	const std::string & what() const { return msg; }
};


template<class T>
class MyVec {
public:
	template<class T2>
	friend std::ostream& operator<<(std::ostream &, const MyVec<T2> &);

	//construtores/destrutures/etc
	MyVec();
	MyVec(int n, const T&init=T());

	//destrutor
	~MyVec() { destroy(); };

	//Construtor de copia
	MyVec(const MyVec &);
	MyVec & operator=(const MyVec &);

	//funcoes de acesso
	T &operator[](int pos) {return data[pos];}
	const T &operator[](int pos) const {return data[pos];}
	void push_back(const T&);
	void resize(int newSize);
	void insert(const T&,int pos);
	void clear();

	void empty() const {return size() == 0;};
	int size() const {return dataSize;};

	int eraseMatchingElements(const T&item);
	void sortedInsert(const T&item);


private:
	T* data; //declare o membro de dados data, que devera armazenar os elementos da lista
	int dataSize; //quantos elementos ha na lista?
	int dataCapacity; //quantos elementos atualmente cabem na lista? 

	void create();
	void destroy();
	void resizeCapacity(int newCapacity);
};

template<class T>
void MyVec<T>::push_back(const T&elem) {
	if(this->dataSize == this->dataCapacity)
	{
		if(this->dataSize == 0)
		{
			this->resizeCapacity(1);
		}
		else
		{
			this->resizeCapacity(2 * this->dataCapacity);
		}
	}

	this->data[dataSize] = elem;
	this->dataSize++;
}

template<class T>
void MyVec<T>::resize(int newSize) {
	if(newSize >= dataCapacity) { //primeiro temos que realocar o vector...
		resizeCapacity(newSize); //para o resize vamos usar o tamanho exato caso seja necessario realocar o vector..
	}
	for(int i=dataSize;i<newSize;i++) { //preencha a parte "extra" do vector com valores "em branco"
		data[i] = T();
	}
	dataSize = newSize;
}

//insere o elemento na posicao pos e move os elementos ja presentes no vetor
// pos pode ser:
//   uma posicao apos o final do vetor (para inserir na ultima posicao) 
//   ou uma posicao ja existente (nesse caso os elementos nessa posicao e apos ela serao movidos "para a frente")
template<class T>
void MyVec<T>::insert(const T&elem,int pos) {
	if(pos > dataSize || pos < 0) {
		throw MyVecException("Erro na funcao insert: posicao invalida");
	}

	if(dataSize == dataCapacity) { //preciso redimensionar?
		if(dataCapacity ==0) //Exercicio: Por que e' preciso testar isso?
			resizeCapacity(1);
		else
			resizeCapacity(dataCapacity*2);
	}	

	for(int i=dataSize;i>pos;i--)
		data[i] = data[i-1];
	data[pos] = elem;
	dataSize++;
}


template<class T>
void MyVec<T>::clear() {
	destroy();
	create();
}


template<class T>
void MyVec<T>::resizeCapacity(int newCapacity) {
	//implemente esta funcao
	//Ela deve redimensionar o vetor de modo que ele tenha capacidade newCapacity
	//Se newCapacity for menor do que a capacidade atual voce devera ignorar a chamada a esta funcao (i.e., nunca reduziremos a capacidade do vetor)
	//Nao se esqueca de liberar (deletar) a memoria que nao for mais necessaria (para evitar vazamentos de memoria)
	//Exemplo de execucao:
	//data=[1,2,3,,], dataSize=3, dataCapacity=5 (vetor de capacidade 5, com 3 elementos ocupados)
	//se chamarmos resizeCapacity(10), os membros de dados deverao ter os seguintes valores:
	//data=[1,2,3,,,,,,,], dataSize=3, dataCapacity=10.

	if(newCapacity <= this->dataCapacity) return;

	T* temp = this->data;
	this->data = new T[newCapacity];

	int i;
	for(i=0; i<this->dataCapacity; i++)
	{
		this->data[i] = temp[i];
	}
	for(; i<newCapacity; i++)
	{
		this->data[i]= T();
	}

	delete[] temp;
	this->dataCapacity = newCapacity;
}

template<class T>
void MyVec<T>::destroy() {
	delete []data;
	dataSize = dataCapacity = 0;
}

template<class T>
void MyVec<T>::create() {
	data = NULL;
	dataSize = dataCapacity = 0;
}

template<class T>
MyVec<T>::MyVec() {
	create();
}

template<class T>
MyVec<T>::MyVec(int n, const T&init) {
	//Implemente esta funcao:
	//Cria um vetor de tamanho e capacidade n, onde todos os n elementos valem "init"

	this->data = new T[n];
	this->dataCapacity = this->dataSize = n;
	for(int i=0; i<n; i++)
	{
		this->data[i] = init;
	}

}


//Construtor de copia
template<class T>
MyVec<T>::MyVec(const MyVec &other) {
	//Implemente esta funcao
	//Dica: nao duplique codigo! (esta funcao deve ser escrita utilizando apenas 2 linhas de codigo!)
	this->create();
	(*this) = other;

}

template<class T>
MyVec<T> & MyVec<T>::operator=(const MyVec &other) {
	if(this==&other) return *this; 
	destroy(); //Exercicio: por que precisamos disso?
	dataCapacity = other.dataCapacity;
	dataSize = other.dataSize;
	//data = other.data; //por que nao podemos fazer isso?
	data = new T[dataCapacity];
	for(int i=0;i<dataSize;i++) data[i] = other.data[i];
	return *this;
}

template<class T2>
std::ostream& operator<<(std::ostream &out, const MyVec<T2> &v) {
	out << "Size: " << v.size() << "\n";
	out << "Capacity: " << v.dataCapacity << "\n";
	for(int i=0;i<v.size();i++) out << v.data[i] << " ";
	out << "\n";
	return out;
}

/*
	Alocando mais memória seria assim:

	MyVec temp();
	temp.resize(this->dataCapacity);

	int removidos = 0;
	
	for(int i=0; i<this->capacidade; i++)
	{
		if(this->data[i] == item)
		{
			removidos++
			continue;
		}
		temp.push_back(item);
	}

	this->dataSize -= removidos;
	(*this) = temp;

	return removidos;	
*/
template<class T>
int MyVec<T>::eraseMatchingElements(const T&item)
{
	int removidos = 0;
	int removidosLocal;

	for(int i = 0; i < this->dataSize; i++)
	{
		if(this->data[i] == item)
		{
			removidosLocal = 0;
			int j; for(j=0; this->data[i+j] == item && (i+j) < this->dataSize; j++) { removidosLocal++; }
			
			this->dataSize -= removidosLocal;
			for(int k = i; k < this->dataSize; k++)
			{
				this->data[k] = this->data[k+j];
			}
			removidos += removidosLocal;
		}
	}

	return removidos;
}

template<class T>
void MyVec<T>::sortedInsert(const T&item)
{
	for(int i = 0; i < this->dataCapacity; i++)
	{
		if(item <= this->data[i])
		{
			this->insert(item, i);
			return;
		}
	}
	
	this->insert(item, this->dataSize);
}

#endif