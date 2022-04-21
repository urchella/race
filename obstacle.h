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
	int getScore() { return score; }
	void setScore(int sc) { score = sc; }
	void setChance(int number) { chance = number; }
	int getChance() { return chance; }
	void setPosition(float x, float y) { sprite.setPosition(x, y); }
	void update() {
		sprite.move(speed);
		if (sprite.getPosition().y >= WINDOW_HEIGHT) {
			
		}
	}
	
};


