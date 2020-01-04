#include "Game.h"

Game::Game() {
	player = Player(sf::Vector2f(100.f, 100.f), sf::RectangleShape(sf::Vector2f(32.f, 32.f)));
	InitVars();
	InitWindow();
}

Game::~Game() {
	delete window;
}

void Game::InitVars() {
	window = nullptr;
}

void Game::InitWindow() {
	videoMode.width = 800;
	videoMode.height = 600;
	window = new sf::RenderWindow(videoMode, "Appeaser", sf::Style::Titlebar | sf::Style::Close);
	window->setFramerateLimit(60);
}

void Game::InitObjects() {

	player.Init();
}

const bool Game::running() const {
	return window->isOpen();
}

//Functions

//Input
void Game::Poll() {
	while (window->pollEvent(evt)) {
		//Player movement
		switch (evt.type) {
			//Closing the game
			case (sf::Event::Closed):
				std::cout << "closing the game";
				window->close();
				break;

			//Player movement
			case (sf::Event::KeyPressed):
				if (evt.key.code == sf::Keyboard::W) {
					player.SetUpDirection(true);
				}
				if (evt.key.code == sf::Keyboard::S) {
					player.SetDownDirection(true);
				}
				if (evt.key.code == sf::Keyboard::A) {
					player.SetLeftDirection(true);
				}
				if (evt.key.code == sf::Keyboard::D) {
					player.SetRightDirection(true);
				}
				break;
			case (sf::Event::KeyReleased):
				if (evt.key.code == sf::Keyboard::W) {
					player.SetUpDirection(false);
				}
				if (evt.key.code == sf::Keyboard::S) {
					player.SetDownDirection(false);
				}
				if (evt.key.code == sf::Keyboard::A) {
					player.SetLeftDirection(false);
				}
				if (evt.key.code == sf::Keyboard::D) {
					player.SetRightDirection(false);
				}
				break;
		}		
	}
}


void Game::Update() {
	Poll();

	player.Update();
}

void Game::Render() {
	window->clear(sf::Color(50, 200, 100));

	player.Render(window);

	window->display();
}
