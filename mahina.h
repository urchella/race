#pragma once 
#include "SFML/Graphics.hpp" 
#include "const.h" 

class Mashina {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f speed = sf::Vector2f(0.0f, -3.0f);
	int score = 0;
	int num = rand() % 4;
public:
	Mashina() {
		texture.loadFromFile("obs.png");
		sprite.setTexture(texture);
		sprite.setScale(0.2f, 0.2f);
	}
	sf::Sprite getSprite() { return sprite; }
	sf::Vector2f getPosition() { return sprite.getPosition(); }
	void init(float startx, float starty) { sprite.setPosition(startx, starty); }
	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
	void update() {
		sprite.move(speed);
		if (sprite.getPosition().y >= WINDOW_HEIGHT) {
			sprite.setPosition(static_cast<float>(156 + 72 * num), 0.f);
			score++;
		}
	}
	int getScore() { return score; }
};
