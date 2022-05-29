#include "Planet.h"

Planet::Planet(float xPos, float yPos, float Mass, float Radius, bool isSun) : R(Radius), M(Mass){
	this->x = new float(xPos);
	this->y = new float(yPos);
}

Planet::~Planet() {
	delete[] x;
	delete[] y;
}
