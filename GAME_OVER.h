#pragma once
#include "SFML/Graphics.hpp"
class GameOver {
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	GameOver() {
		texture.loadFromFile("game_over.jpg");
		sprite.setTexture(texture);
	}
	sf::Sprite getSprite() { return sprite; }
};