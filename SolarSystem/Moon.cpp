#include "Moon.h"

Moon::Moon(float x, float y, float M, float R, std::string textureFile, Planet* planet) :M(M), R(R), textureFile(textureFile) {
	this->x = (x + planet->getX())*this->AU;
	this->y = y;
	this->planet = planet;
	this->texture.loadFromFile(textureFile);
	this->texture.setSmooth(true);
	this->_moon.setTexture(&this->texture);
	this->_moon.setRadius(this->R);
	_moon.setPosition(x * this->SCALE + ((1920 - 2 * this->R) / 2), y * this->SCALE + ((1080 - 2 * this->R) / 2));
	_moon.setPointCount(1000);
	//std::cout << this->R << ' ' << x << ' ' << y << ' ' << x * this->SCALE << std::endl;
}

void Moon::acc() {
	float x2 = this->planet->getX();
	float y2 = this->planet->getY();
	float dx = x2 - x;
	float dy = y2 - y;
	float d = sqrt((dx * dx) + (dy * dy));
	float f1 = this->planet->getM() / (d * d);
	float f2 = G * M;
	float f = f1 * f2;

	float theta = atan2(dy, dx);
	float fx = cos(theta) * f;
	float fy = sin(theta) * f;
	xVel += fx / M * TS;
	yVel += fy / M * TS;
	x += xVel * TS;
	y += yVel * TS;
}

void Moon::moveMoon() {
	_moon.setPosition(x * this->SCALE + ((1920 - 2 * this->R) / 2), y * this->SCALE + ((1080 - 2 * this->R) / 2));
}