#pragma once
class Planet
{
private:
	const float M;
	const float R;
	float* x;
	float* y;
public:
	Planet(float x, float y, float M, float R);
	~Planet();
};

