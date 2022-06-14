#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <vector>
class Legend
{
private:
	sf::Font font;
	std::string text;
	sf::Text displayText;
public:
	Legend() {
		this->font.loadFromFile("KdamThmorPro-Regular.ttf");
		text = "F1 - sub. vel.\nF2 - add vel.\nSPACE - stop/resume\nArrow Keys - move\nMouse- move\nENTER - center";
		displayText.setString(text);
		displayText.setFont(font);
		displayText.setFillColor(sf::Color::White);
	}
	void showLegend(sf::RenderWindow& window, float x1, float y1, float W) {
		displayText.setPosition(x1, y1);
		displayText.setCharacterSize(W/80);
		window.draw(displayText);
	}
};

