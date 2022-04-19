#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "car.h"
#include "road.h"
#include "splash.h"
#include "obstacle.h"
#include "Score.h"
#include "new_rg.h"
#include "Bonus.h"
#include "GAME_OVER.h"
#include "mahina.h"
class Game {
public:
	enum GameState { SPLASH,NEW_REGION, PLAY, GAME_OVER };
	Game();
	void play();
	int  getSumScore();
private:
	sf::RenderWindow window;
	GameState game_state = SPLASH;
	Splash splash;
	GameOver game_over;
	//Score score;
	Bonus bonus;
	Mashina mashina;
	Car car;
	TextObj text;
	Region region;
	Road road1, road2;
	Obstacle obs[OBS_QTY];
	void check_events();
	void update();
	void draw();
	void check_collisions();
	bool new_region = false;
	int sum_score = 0;
};