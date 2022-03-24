#pragma once
#include "const.h"
#include "SFML/Graphics.hpp"
#include <iostream>
class Region {
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Region() {
		texture.loadFromFile("splash.png");
		sprite.setTexture(texture);
	}
	sf::Sprite getSprite() { return sprite; }
};