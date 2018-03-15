all: compile

compile: FigBase.o Retangulo.o Circulo.o Segmento.o TesteFiguras2.o
	g++ FigBase.o Retangulo.o Circulo.o Segmento.o TesteFiguras2.o -o Teste

FigBase.o: FigBase.h FigBase.cpp
	g++ -c Figbase.cpp

Retangulo.o: Retangulo.h Retangulo.cpp
	g++ -c Retangulo.cpp

Circulo.o: Circulo.h Circulo.cpp
	g++ -c Circulo.cpp

Segmento.o: Segmento.h Segmento.cpp
	g++ -c Segmento.cpp

TesteFiguras2.o: TesteFiguras2.cpp
	g++ -c TesteFiguras2.cpp