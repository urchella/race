#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "car.h"
class Game {
public:
	enum game_state { SPLASH, PLAY, GAME_OVER };
	Game();
	void play();
private:
	sf::RenderWindow window;
	Car car;
	void check_events();
	void update();
	void draw();
	void check_collisions();
};
