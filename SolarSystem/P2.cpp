#include "P2.h"

P2::P2(float x, float y, float M, float R, std::string textureFile):M(M),R(R),textureFile(textureFile) {
	this->x = x;
	this->y = y;
	this->textue.loadFromFile(textureFile);
	this->textue.setSmooth(true);
	this->_planet.setTexture(&this->textue);
	this->_planet.setRadius(this->R);
	_planet.setPosition(x * this->SCALE + ((1920 - 2 * this->R) / 2) , y * this->SCALE + ((1080 - 2 * this->R) / 2));
	_planet.setPointCount(1000);
	std::cout << this->R << ' ' << x << ' ' << y <<' '<< x * this->SCALE << std::endl;
}

float P2::getX() {
	return x;
}
float P2::getY() {
	return y;
}

float P2::getM() {
	return M;
}

sf::CircleShape P2::getPlanet() {
	return _planet;
}

void P2::setVY(float yVel) {
	this->yVel = yVel;
}

std::pair<float, float> P2::a(P2* p) {
	float x2 = p->getX();
	float y2 = p->getY();
	//std::cout << x << ' ' << y << ' ' << x2 << ' ' << y2 << '\t';
	float dx = x2 - x;
	float dy = y2 - y;
	float d = sqrt((dx * dx) + (dy * dy));
	//std::cout << dx<<' '<<dy<<' '<<dx * dx << ' ' << dy * dy << std::endl;
	float f1 = p->getM() / (d * d);
	float f2 = G * M;
	float f = f1 * f2;
	
	float theta = atan2(dy, dx);  
	float fx = cos(theta) * f;
	float fy = sin(theta) * f;
	//std::cout << "fx: " << fx << "\t\tfy: " << fy << std::endl;
	return std::make_pair(fx, fy);
}

void P2::updatePos(std::vector<P2*>planets) {
	float tfx = 0;
	float tfy = 0;
	for (auto planet : planets) {
		if (this != planet) {
			std::pair<float, float> fT = this->a(planet);
			tfx += fT.first;
			tfy += fT.second;
		}
		
	}
	std::cout << "\n\n";
	xVel += tfx / M * TS;
	yVel += tfy / M * TS;    
	x += xVel * TS;
	y += yVel * TS;
}

void P2::movePlanet() {
	//std::cout << x << "\t\t" << y << std::endl;
	_planet.setPosition(x * this->SCALE + ((1920 - 2 * this->R) / 2), y * this->SCALE + ((1080 - 2 * this->R) / 2));
}