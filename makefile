all: Mediana.o driver.o
	g++ driver.o Mediana.o -o teste

Mediana.o: Mediana.cpp Mediana.h
	g++ -c Mediana.cpp

driver.o: driver.cpp
	g++ -c driver.cpp