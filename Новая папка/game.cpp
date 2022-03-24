#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.h"
#include "road.h"
#include "const.h"
#include "Score.h"
#include"obstacle.h"
#include "GAME_OVER.h"

Game::Game():text(500.f, 50.f, 50, sf::Color::Yellow) {
	window.create(
		sf::VideoMode(
			static_cast<size_t>(WINDOW_WIDTH),
			static_cast<size_t>(WINDOW_HEIGHT)
		), "SUPER RACE",
		sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(FPS);
	road1.init(0.f, 0.f);
	road2.init(0.f, -WINDOW_HEIGHT);
	for (int i = 0; i < OBS_QTY; i++) {
		obs[i].init(i * 150.f, -i * WINDOW_HEIGHT / 2.f);
	}
};
void Game::check_events() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) window.close();
		if (event.type == sf::Event::KeyPressed)
			if (event.key.code == sf::Keyboard::Space)
				if (game_state == SPLASH) game_state = PLAY;
		if (event.type == sf::Event::KeyPressed)
			if (event.key.code == sf::Keyboard::Space)
				if (game_state == NEW_REGION) game_state = PLAY;
	}
	
	
	
};
void Game::update() { 
	
	switch (game_state) {
	case SPLASH:
		break;
	case PLAY:
		car.update();
		road1.update();
		road2.update();
		sum_score = 0;
		for (int i = 0; i < OBS_QTY; i++) {
			obs[i].update();
			sum_score += obs[i].getScore();
		}
		text.update(std::to_string(sum_score));
		if (sum_score == 10) {
			game_state = NEW_REGION;
			sum_score++;
		}
		break;
	case NEW_REGION:
		break;
	case GAME_OVER:
		break;
	default:
		break;
	}
};
void Game::draw() {
	switch (game_state) {
	case SPLASH:
		window.clear(sf::Color::Black);
		window.draw(splash.getSprite());
		window.display();
		break;
	case PLAY:
		window.clear(sf::Color::Black);
		text.draw(window);
		window.draw(road1.getSprite());
		window.draw(road2.getSprite());
		window.draw(car.getSprite());
		text.draw(window);
		for (int i = 0; i < OBS_QTY; i++) {
			window.draw(obs[i].getSprite());
		}

		window.display();

		break;
	case NEW_REGION:
		window.clear(sf::Color::Black);
		window.draw(region.getSprite());
		window.display();
		break;
	case GAME_OVER:
		window.clear(sf::Color::Black);
		window.draw(game_over.getSprite());
		window.display();
	default:
		break;
	}
};
void Game::check_collisions() {
	for (int i = 0; i < OBS_QTY; i++) {
		if (obs[i].getHitBox().intersects(car.getHitBox())) {
			game_state = GAME_OVER;
		}
	}
};
void Game::play() {
	while (window.isOpen()) {
		check_events();
		update();
		check_collisions();
		draw();
	}
}