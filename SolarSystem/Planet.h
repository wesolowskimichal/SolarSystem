#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
class Planet
{
private:
	const float M;
	const float R;
	float* x;
	float* y;
public:
	bool isSun = false;
	Planet(float xPos, float yPos, float Mass, float Radius, bool isSun);
	~Planet();
};
