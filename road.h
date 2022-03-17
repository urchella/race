#pragma once
#include "const.h"
#include <SFML/Graphics.hpp>
class Road {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f speed = sf::Vector2f(0.0f, 3.0f);
public:
	Road() {
		texture.loadFromFile("дорожка мефа.png");
		sprite.setTexture(texture);
		sprite.setScale(0.5f, 1.9f);
	}
	sf::Sprite getSprite() { return sprite; }
	void init(float startx, float starty) { sprite.setPosition(startx, starty); }
};