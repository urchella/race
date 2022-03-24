#pragma once
#include "const.h"
#include "SFML/Graphics.hpp"
#include <iostream>
class Game_over {
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Game_over() {
		texture.loadFromFile("game_over.jpg");
		sprite.setTexture(texture);
	}
	sf::Sprite getSprite() { return sprite; }
};