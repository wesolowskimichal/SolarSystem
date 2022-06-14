#pragma once
#include "Planet.h"
#include "constants.h"
class Moon{
private:
	Planet* planet;
	float x;
	float y;
	float xVel = 0;
	float yVel = 1000.f;
	const std::string textureFile;
	sf::Texture texture;
	const float M;
	const float R;
public:
	sf::CircleShape _moon;
	Moon(float x, float y, float M, float R, std::string texture, Planet* planet);
	std::pair<float, float> a();
	void updatePos();
	void movePlanet();
	void moveMoon();
};

