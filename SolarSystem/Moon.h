#pragma once
#include "Planet.h"
class Moon{
private:
	Planet* planet;
	float x;
	float y;
	float xVel = 0.f;
	float yVel = 1000.f  ;
	const std::string textureFile;
	sf::Texture texture;
	const float M;
	const float R;
	const float G = 6.67428e-11;
	const float TS = 3600 * 24;
public:
	sf::CircleShape _moon;
	const float AU = 149.6e6 * 1000;
	const float SCALE = 250 / AU;
	Moon(float x, float y, float M, float R, std::string texture, Planet* planet);
	void acc();
	void moveMoon();
};

