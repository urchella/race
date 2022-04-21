#include <SFML/Graphics.hpp>
#include "game.h"

Game::Game() :text(500.f, 50.f, 50, sf::Color::Yellow) {
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
		obs[OBS_QTY].setChance(rand() % 1000 * -1);
		obs[i].init(i * 150.f, obs[OBS_QTY].getChance());
	}
}
void Game::check_events() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) window.close();
		if (event.type == sf::Event::KeyPressed)
			if (event.key.code == sf::Keyboard::Space)
				if (game_state == SPLASH) game_state = PLAY;
		if (event.type == sf::Event::KeyPressed)
			if (event.key.code == sf::Keyboard::Q)
				if (game_state == NEW_REGION && new_region) game_state = PLAY;
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
		int number;
		int num;
		for (int i = 0; i < OBS_QTY; i++) {
			obs[i].update();
			sum_score += obs[i].getScore();
			if (obs[i].getPosition().y >= WINDOW_HEIGHT) {
				//забрали из update() obstacle и вставили сюда
				obs[i].setChance(rand() % 1000);
				num = rand() % 4;
				obs[i].setPosition(static_cast<float>(156 + 72 * num), -1*obs[i].getChance());
				obs[i].setScore(obs[i].getScore() + 1);

				bonus.setChance(rand() % 10000);
				if (bonus.getChance() < 5000) {
					bonus.setNum(rand() % 4);
					bonus.setPosition(static_cast<float>(156 + 72 * bonus.getNum()), 0.f);
				}
			}
		}
		
		bonus.update();
		text.update(std::to_string(sum_score));
		if (sum_score == 1 && !new_region) {
			game_state = NEW_REGION;
			new_region = true;
			if (!road1.getNewRoadVisible() && !road2.getNewRoadVisible()) {
				road1.setNewTexture();
				road2.setNewTexture();
				road1.setNewRoadVisible(true);
				road2.setNewRoadVisible(true);
			};
			if (!car.getNewKaterVisible()) {
				car.setNewTexture();
				car.setNewKaterVisible(true);

			};
		}
			break;
	case NEW_REGION:

		break;
	case GAME_OVER:
		break;
	default:
		break;
		}
	}
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
		window.draw(bonus.getSprite());
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
	if (bonus.getHitBox().intersects(car.getHitBox())) {
		sum_score++;
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
int Game::getSumScore() { return sum_score; }