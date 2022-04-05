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
		texture.loadFromFile("region2.jpeg");
		sprite.setTexture(texture);
		sprite.setScale(1.6f, 2.f);
	}
	sf::Sprite getSprite() { return sprite; }
};