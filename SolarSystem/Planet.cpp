#include "Planet.h"
#include <iostream>
Planet::Planet(float xPos, float yPos, float Mass, float Radius, bool isSun, int Red, int Green, int Blue, float sunR) : R(Radius), M(Mass), SCALE(250/AU), isSun(isSun), sunR(sunR), Color(Red, Green, Blue) {
	//this->x = new float((xPos - this->R) * this->SCALE + (1920 / 2));
	//this->y = new float((yPos - this->R) * this->SCALE + (1080 / 2));
	//this->x = new float(xPos * this->SCALE + ((1920 - 2*this->R) / 2));		GOOD
	//this->y = new float(yPos * this->SCALE + ((1080 - 2*this->R) / 2));		GOOD
	this->x = new float(xPos * this->SCALE + ((1920 - 2 * this->R) / 2) + sunR);
	this->y = new float(yPos * this->SCALE + ((1080 - 2 * this->R) / 2));
}

Planet::~Planet() {
	delete x;
	delete y;
}

sf::CircleShape Planet::create() {
	sf::CircleShape  _planet(this->R);
	_planet.setFillColor(sf::Color(Red, Green, Blue));
	_planet.setPosition(*x, *y);
	std::cout << this->R << ' ' << *x << ' ' << *y<<std::endl;
	return _planet;
}

float Planet::getR() {
	return R;
}