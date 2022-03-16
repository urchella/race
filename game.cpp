#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.h"
#include "const.h"
Game::Game() {
	window.create(
		sf::VideoMode(
			static_cast<size_t>(WINDOW_HEIGHT),
			static_cast<size_t>(WINDOW_WIDTH)
		), "SUPER RACE",
		sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(FPS);
}
void Game::check_events() { 
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) window.close();
		/*if (event.type == sf::Event::KeyPressed)
			if (event.key.code == sf::Keyboard::Space);
				if (game_state == SPLASH) game_state = PLAY;*/
	}
};
void Game::update() { car.update(); };
void Game::draw() {
	window.clear(sf::Color::Black);
	//window.draw(splash.getSprite());
	window.draw(car.getSprite());
	window.display();

};
void Game::check_collisions() {};
void Game::play(){
	while (window.isOpen()) {
		check_events();
		update();
		check_collisions();
		draw();
	}
}
