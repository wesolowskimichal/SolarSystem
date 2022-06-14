#include "Planet.h"

Planet::Planet(float x, float y, float M, float R, std::string textureFile) :M(M), R(R), textureFile(textureFile) {
	this->x = x;
	this->y = y;
	this->texture.loadFromFile(textureFile);
	this->texture.setSmooth(true);
	this->_planet.setTexture(&this->texture);
	this->_planet.setRadius(this->R);
	_planet.setPosition(x * SCALE + ((1920 - 2 * this->R) / 2), y * SCALE + ((1080 - 2 * this->R) / 2));
	_planet.setPointCount(1000);
	std::cout << this->R << ' ' << x << ' ' << y << ' ' << x * SCALE << std::endl;
}

float Planet::getX() {
	return x;
}
float Planet::getY() {
	return y;
}

float Planet::getM() {
	return M;
}

float Planet::getR() {
	return R;
}

sf::CircleShape Planet::getPlanet() {
	return _planet;
}

void Planet::setVY(float yVel) {
	this->yVel = yVel;
}

std::pair<float, float> Planet::a(Planet* p) {
	float x2 = p->getX();
	float y2 = p->getY();
	float dx = x2 - x;
	float dy = y2 - y;
	float d = sqrt((dx * dx) + (dy * dy));
	float f1 = p->getM() / (d * d);
	float f2 = G * M;
	float f = f1 * f2;

	float theta = atan2(dy, dx);
	float fx = cos(theta) * f;
	float fy = sin(theta) * f;
	return std::make_pair(fx, fy);
}

void Planet::updatePos(std::vector<Planet*>planets) {
	float tfx = 0;
	float tfy = 0;
	for (auto planet : planets) {
		if (this != planet) {
			std::pair<float, float> fT = this->a(planet);
			tfx += fT.first;
			tfy += fT.second;
		}

	}
	xVel += tfx / M * TS;
	yVel += tfy / M * TS;
	x += xVel * TS;
	y += yVel * TS;
}

void Planet::movePlanet() {
	_planet.setPosition(x * SCALE + ((1920 - 2 * this->R) / 2), y * SCALE + ((1080 - 2 * this->R) / 2));
}