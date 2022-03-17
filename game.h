#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "car.h"
#include "splash.h"
class Game {
public:
	enum GameState { SPLASH, PLAY, GAME_OVER };
	Game();
	void play();
private:
	sf::RenderWindow window;
	GameState game_state = SPLASH;
	Splash splash;
	Car car;
	void check_events();
	void update();
	void draw();
	void check_collisions();
};