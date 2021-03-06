#pragma once
#include "SFML/Graphics.hpp"
#include "game.h"
class Bonus {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f speed = sf::Vector2f(0.0f, 3.0f);
	int chance;
	int num;
public:
	Bonus(){
		texture.loadFromFile("benz.png");
		sprite.setTexture(texture);
		sprite.setScale(0.2f, 0.2f);
	}
	sf::Sprite getSprite() { return sprite; }
	void setPosition(float startx, float starty) {sprite.setPosition(startx, starty); }
	//void init(float startx, float starty) { sprite.setPosition(startx, starty); }
	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
	void update() {
		sprite.move(speed);
	}
	void setChance(int number) { chance = number; }
	int getChance() { return chance; }
	int getNum() { return num; }
	void setNum(int number) { num = number; }

};