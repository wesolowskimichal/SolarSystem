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
public:
	
	sf::CircleShape _planet;
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
	void setTrail() {
		std::pair<float, float>temp = { this->x,this->y };
		orbitTrail.push_back(temp);
	}
	void drawTrail(sf::RenderWindow& window) {
		sf::Vertex line[2];
		for (int i = orbitTrail.size()-1; i > 0; i--) {
			line[0] = sf::Vertex(sf::Vector2f((orbitTrail[i].first * SCALE + ((1920 - 2 * this->R) / 2))+this->R, (orbitTrail[i].second * SCALE + ((1080 - 2 * this->R) / 2))+this->R));
			line[1] = sf::Vertex(sf::Vector2f((orbitTrail[i-1].first * SCALE + ((1920 - 2 * this->R) / 2))+this->R, (orbitTrail[i-1].second * SCALE + ((1080 - 2 * this->R) / 2))+this->R));
			//line[1] = sf::Vertex(sf::Vector2f(orbitTrail[i - 1].first, orbitTrail[i].second));
			window.draw(line, 2, sf::Lines);
		}

	}
};

