make: testaInclusao.o
	g++ testaInclusao.o Circulo.o Retangulo.o Ponto.o FigBase.o -o testaInclusao.out

testaInclusao.o: Ponto.o Circulo.o Retangulo.o
	g++ -c testaInclusao.cpp

FigBase.o: FigBase.h FigBase.cpp
	g++ -c FigBase.cpp

Ponto.o: FigBase.o Ponto.h Ponto.cpp
	g++ -c Ponto.cpp

Circulo.o: Ponto.o Circulo.h Circulo.cpp
	g++ -c Circulo.cpp

Retangulo.o: Ponto.o Retangulo.h Retangulo.cpp
	g++ -c Retangulo.cpp

clean:
	rm -v FigBase.o Ponto.o Circulo.o Retangulo.o testaInclusao.o testaInclusao.out