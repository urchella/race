#pragma once 
#include "SFML/Graphics.hpp" 
#include "const.h" 

class Obstacle {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f speed = sf::Vector2f(0.0f, 3.0f);
	int score = 0;
public:
	Obstacle() {
		texture.loadFromFile("obs.png");
		sprite.setTexture(texture);
		sprite.setScale(0.2f, 0.2f);
	}
	sf::Sprite getSprite() { return sprite; }
	void init(float startx, float starty) { sprite.setPosition(startx, starty); }
	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
	void update() {
		sprite.move(speed);
		if (sprite.getPosition().y >= WINDOW_HEIGHT) {
			sprite.setPosition(static_cast<float>(rand() % (350 - 200 + 1) + 200), 0.f);
			score++;
		}
	}
	int getScore() { return score; }
};


