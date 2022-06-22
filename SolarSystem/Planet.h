#pragma once
#include <SFML/Graphics.hpp>
#include "constants.h"
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>

class Planet {
private:
	float x;
	float y;
	float xVel = 0.f;
	float yVel = 0.f;
	const std::string textureFile;
	sf::Texture texture;
	const float M;
	const float R;
	std::vector < std::pair<float, float>>orbitTrail;
	std::vector < std::pair<float, float>>orbit;
	bool completeOrbit = false;
	sf::CircleShape _planet;

public:
	Planet(float x, float y, float M, float R, std::string texture);
	float getX();
	float getY();
	float getM();
	float getR();
	sf::CircleShape getPlanet();
	std::pair<float, float>a(Planet* p);
	void updatePos(std::vector<Planet*>planets);
	void movePlanet();
	void setVY(float yVel);
};

