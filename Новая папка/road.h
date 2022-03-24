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
		texture.loadFromFile("dorozhka mefa.jpg");
		sprite.setTexture(texture);
		sprite.setScale(0.5f, 1.9f);
	}
	sf::Sprite getSprite() { return sprite; }
	void init(float startx, float starty) { sprite.setPosition(startx, starty); }
	void update() {
		sprite.move(speed);
		if (sprite.getPosition().y >= WINDOW_HEIGHT) {
			sprite.setPosition(0.f, -WINDOW_HEIGHT);
		}
	}
};