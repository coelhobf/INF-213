
#include "Circulo.h"
#include <cmath>

using namespace std;


Circulo::Circulo(const Ponto &p, float raio_) : FigBase(p) {
	raio = raio_;
}

void Circulo::setRaio(float r) {
	raio = r;
}
    
float Circulo::getRaio() const {
	return raio;
}
    
//O ponto p esta dentro do circulo <-> a distancia entre o p e o interior do circulo for menor do que o raio
bool Circulo::contem(const Ponto &p) const {
	float dx = p.getX() - this->getP0().getX();
	float dy = p.getY() - this->getP0().getY();
	float dist = sqrt(dx*dx + dy*dy); //distancia entre p e o interior do circulo
	return  dist < raio;
}