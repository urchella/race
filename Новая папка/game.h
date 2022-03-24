#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "car.h"
#include "road.h"
#include "splash.h"
#include"obstacle.h"
#include "Score.h"
#include "new rg.h"
#include "GAME_OVER.h"
class Game {
public:
	enum GameState { SPLASH,NEW_REGION, PLAY, GAME_OVER };
	Game();
	void play();
private:
	sf::RenderWindow window;
	GameState game_state = SPLASH;
	Splash splash;
	Game_over game_over;
	//Score score;
	Car car;
	TextObj text;
	Region region;
	Road road1, road2;
	Obstacle obs[OBS_QTY];
	void check_events();
	void update();
	void draw();
	void check_collisions();
	int sum_score = 0;
};