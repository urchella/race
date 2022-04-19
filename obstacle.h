#pragma once 
#include "SFML/Graphics.hpp" 
#include "const.h" 

class Obstacle {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f speed = sf::Vector2f(0.0f, 3.0f);
	int score = 0;
	int chance;
	int num = rand() % 4;
public:
	Obstacle() {
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
			setChance(rand() % 1000 * -1);
			sprite.setPosition(static_cast<float>(156 + 72 * num), getChance());
			score++;
		}
	}
	int getScore() { return score; }
	void setChance(int number) { chance = number; }
	int getChance() { return chance; }
};


