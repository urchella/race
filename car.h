#pragma once
#include "SFML/Graphics.hpp"
#include "game.h"
#include "const.h"
class Car {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f speed = sf::Vector2f(5.0f, 0.0f);
	int sum_score;
	bool kater = false;
public:
	Car() {
		texture.loadFromFile("car.png");
		sprite.setTexture(texture);
		sf::FloatRect local_bounds = sprite.getLocalBounds();
		sprite.setOrigin(local_bounds.width / 2.f, local_bounds.height / 2.f);
		sprite.setScale(0.08f, 0.08f);
		sprite.setRotation(90.f);
		sf::FloatRect global_bounds = sprite.getGlobalBounds();
		sprite.setPosition(WINDOW_WIDTH / 2.f, WINDOW_HEIGHT - global_bounds.height / 2 - 20);

	}
	sf::Sprite getSprite() { return sprite; }
	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
	void update() {
		speed = sf::Vector2f(0.f, 0.f);
		if (sum_score >= 1 && kater == false) {
			texture.loadFromFile("kater.jpeg");
			sprite.setTexture(texture);
			kater = true;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			speed = sf::Vector2f(-5.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			speed = sf::Vector2f(5.0f, 0.0f);
		}
		sprite.move(speed);
		sf::Vector2f curr_position = sprite.getPosition();
		if (curr_position.x <= 156.f) {
			sprite.setPosition(156.f, curr_position.y);
		}
		else if (curr_position.x >= WINDOW_WIDTH - 156.f) {
			sprite.setPosition(WINDOW_WIDTH - 156.f, curr_position.y);
		}
	}
	bool getNewKaterVisible() { return kater; }
	void setNewKaterVisible(bool x) { kater = x; }
	void setNewTexture() {
		texture.loadFromFile("kater.png");
		sprite.setTexture(texture);
		sprite.setRotation(-90.f);
		kater = true;

	}

};