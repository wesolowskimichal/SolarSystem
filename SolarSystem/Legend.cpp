#include "Legend.h"
Legend::Legend(){
	this->font.loadFromFile("Fonts/KdamThmorPro-Regular.ttf");
	text = "F1 - sub. vel.\nF2 - add vel.\nSPACE - stop/resume\nArrow Keys - move\nMouse- move\nENTER - center";
	displayText.setString(text);
	displayText.setFont(font);
	displayText.setFillColor(sf::Color::White);
}

void Legend::showLegend(sf::RenderWindow& window, float x1, float y1, float W) {
	displayText.setPosition(x1, y1);
	displayText.setCharacterSize(W / 80);
	window.draw(displayText);
}