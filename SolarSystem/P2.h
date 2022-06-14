#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
class P2{
private:
	float x;
	float y;
	float xVel = 0.f;
	float yVel = 0.f;
	const std::string textureFile;
	sf::Texture textue;
	const float M;
	const float R;
	const float G = 6.67428e-11;
	const float TS = 3600 * 24;
public:
	const float AU = 149.6e6 * 1000;
	const float SCALE = 250 / AU;
	sf::CircleShape _planet;
	P2(float x, float y, float M, float R, std::string texture);
	float getX();
	float getY();
	float getM();
	sf::CircleShape getPlanet();
	std::pair<float, float>a(P2* p);
	void updatePos(std::vector<P2*>planets);
	void movePlanet();
	void setVY(float yVel);
};

