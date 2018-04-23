all:
	echo "Funcoes ou MyVec"
	
Funcoes: MyVec.h testaFuncoes.cpp
	g++ testaFuncoes.cpp -g -o Teste.out

MyVec: MyVec.h TestaMyVec.cpp
	g++ TestaMyVec.cpp -g -o Teste.out
