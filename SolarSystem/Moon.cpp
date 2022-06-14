#include "Moon.h"

Moon::Moon(float x, float y, float M, float R, std::string textureFile, Planet* planet) :M(M), R(R), textureFile(textureFile) {
	this->x = x * AU + planet->getX();
	this->y = y + planet->getY();
	this->planet = planet;
	this->texture.loadFromFile(textureFile);
	this->texture.setSmooth(true);
	this->_moon.setTexture(&this->texture);
	this->_moon.setRadius(this->R);
	float planetX = planet->getX() * SCALE + ((1920 - 2 * this->R) / 2);
	float planetY = planet->getY() * SCALE + ((1080 - 2 * this->R) / 2);
		//x * this->SCALE + ((1920 - 2 * this->R) / 2), y * this->SCALE + ((1080 - 2 * this->R) / 2)
	//_moon.setPosition((this->x + planet->getX()) * this->SCALE + ((1920 - 2 * this->R) / 2), (this->y + planet->getY()) * this->SCALE + ((1080 - 2 * this->R) / 2));
		_moon.setPosition(this->x * SCALE , this->y * SCALE );
	_moon.setPointCount(1000);
	//std::cout << this->R << ' ' << x << ' ' << y << ' ' << x * this->SCALE << std::endl;
}

void Moon::moveMoon() {
	float planetX = planet->getX() * SCALE + ((1920 - 2 * this->R) / 2);
	float planetY = planet->getY() * SCALE + ((1080 - 2 * this->R) / 2);
	//std::cout << this->x * this->SCALE + planetX << "\t\t" << this->y * this->SCALE + planetY << "\n\n";
	_moon.setPosition(this->x * SCALE , this->y * SCALE);

	//_moon.setPosition((this->x + planet->getX()) * this->SCALE + ((1920 - 2 * this->R) / 2), (this->y + planet->getY()) * this->SCALE + ((1080 - 2 * this->R) / 2));

}

std::pair<float, float> Moon::a() {
	float x2 = planet->getX();
	float y2 = planet->getY();
	float dx = x2 - x;
	float dy = y2 - y;
	float d = sqrt((dx * dx) + (dy * dy));
	float f1 = planet->getM() / (d * d);
	float f2 = G * M;
	float f = f1 * f2;

	float theta = atan2(dy, dx);
	float fx = cos(theta) * f;
	float fy = sin(theta) * f;
	return std::make_pair(fx, fy);
}

void Moon::updatePos() {
	float tfx = 0;
	float tfy = 0;
	std::pair<float, float> fT = this->a();
	tfx += fT.first;
	tfy += fT.second;
	xVel += tfx / M * TS;
	yVel += tfy / M * TS;
	x += xVel * TS;
	y += yVel * TS;
}

void Moon::movePlanet() {
	_moon.setPosition(x * SCALE + ((1920 - 2 * this->R) / 2), y * SCALE + ((1080 - 2 * this->R) / 2));
}