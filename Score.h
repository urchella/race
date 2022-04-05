#pragma once
#include "SFML/Graphics.hpp" 
class TextObj {
private:
	sf::Text text;
	sf::Font font;
public:
	TextObj(float x, float y, int size, sf::Color color) {
		font.loadFromFile("DS-DIGI.TTF");
		text.setFont(font);
		text.setFillColor(color);
		text.setCharacterSize(size);
		text.setPosition(x, y);
	}
	int score = 0;
	void update(std::string str) { text.setString(str); }
	int getScore(){ return score; }
	void draw(sf::RenderWindow& window) { window.draw(text); }
};