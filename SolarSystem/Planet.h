#pragma once
#include <SFML/Graphics.hpp>
#include "Color.h"
#include <math.h>
class Planet:
	protected Color
{
private:
	const float M;
	const float R;
	float* x;
	float* y;
	const bool isSun = false;
public:
	const float AU = 149.6e6 * 1000;
	const float G = 6.67428e-11;
	//const float SCALE = 250 / AU;
	const float SCALE;

	Planet(float xPos, float yPos, float Mass, float Radius, bool isSun, int Red, int Green, int Blue);
	~Planet();
	sf::CircleShape create();
};
