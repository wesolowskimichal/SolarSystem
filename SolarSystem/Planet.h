#pragma once
#include <SFML/Graphics.hpp>
#include "Color.h"
#include <math.h>
#include <vector>
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
	const float G = 6.67428e-11;
	const float TS = 3600 * 24;
	const int trailPoints = 120;
	std::vector < std::pair<float, float>>orbitTrail;
public:
	const float AU = 149.6e6 * 1000;
	const float SCALE = 250 / AU;
	sf::CircleShape _planet;
	Planet(float x, float y, float M, float R, std::string texture);
	float getX();
	float getY();
	float getM();
	sf::CircleShape getPlanet();
	std::pair<float, float>a(Planet* p);
	void updatePos(std::vector<Planet*>planets);
	void movePlanet();
	void setVY(float yVel);
	void setTrail() {
		std::pair<float, float>temp = { this->x,this->y };
		orbitTrail.push_back(temp);
		if (orbitTrail.size() == trailPoints) 
			orbitTrail.erase(orbitTrail.begin());
	}
	void drawTrail(sf::RenderWindow& window) {
		sf::Vertex line[2];
		for (int i = orbitTrail.size()-1; i > 0; i--) {
			line[0] = sf::Vertex(sf::Vector2f(orbitTrail[i].first * this->SCALE + ((1920 - 2 * this->R) / 2), orbitTrail[i].second * this->SCALE + ((1080 - 2 * this->R) / 2)));
			line[1] = sf::Vertex(sf::Vector2f(orbitTrail[i-1].first * this->SCALE + ((1920 - 2 * this->R) / 2), orbitTrail[i-1].second * this->SCALE + ((1080 - 2 * this->R) / 2)));
			//line[1] = sf::Vertex(sf::Vector2f(orbitTrail[i - 1].first, orbitTrail[i].second));
			window.draw(line, 2, sf::Lines);
		}

	}
};

