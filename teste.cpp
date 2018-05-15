#include <iostream>
#include "MyList2.h"
using namespace std;


int main()
{
	MyList2<char> v;

    for(int i=0; i<5;i++)
    {
        v.push_back('a' + i);
    }

    cout<< v << endl;

    int posInsert = 0;
    char st = '0';
    Node<char> *it	 = v.begin();
    for (int i = 0; i < posInsert; i++, it = v.next(it)); //faca it apontar para a posicao "posInsert"
	
    v.insert(st, it);

    cout<< v << endl;

    posInsert = 1;
    st = '1';
    it = v.begin();
    for (int i = 0; i < posInsert; i++, it = v.next(it)); //faca it apontar para a posicao "posInsert"
	
    v.insert(st, it);

    cout<< v << endl;

}
