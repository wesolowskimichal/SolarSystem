#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
class Legend
{
private:
	sf::Font font;
	std::string text;
	sf::Text displayText;
public:
	Legend();
	void showLegend(sf::RenderWindow& window, float x1, float y1, float W);
};

