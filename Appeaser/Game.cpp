#include "Game.h"

#include "Player.h"

#include "iostream"

Game::Game() {
	this->InitVars();
	this->InitWindow();
}

Game::~Game() {
	delete this->window;
	//delete this->player;
}

void Game::InitVars() {
	this->window = nullptr;
}

void Game::InitWindow() {
	this->videoMode.width = 800;
	this->videoMode.height = 600;
	this->window = new sf::RenderWindow(this->videoMode, "Appeaser", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

void Game::InitObjects() {

	this->player.Init();
}

const bool Game::running() const {
	return this->window->isOpen();
}

//Functions

//Input
void Game::Poll() {
	while (this->window->pollEvent(this->evt)) {
		//Player movement
		switch (this->evt.type) {
			//Closing the game
			case (sf::Event::Closed):
				std::cout << "closing the game";
				this->window->close();
				break;

			//Player movement
			case (sf::Event::KeyPressed):
				if (this->evt.key.code == sf::Keyboard::W) {
					this->player.upDirection = true;
				}
				if (this->evt.key.code == sf::Keyboard::S) {
					this->player.downDirection = true;
				}
				if (this->evt.key.code == sf::Keyboard::A) {
					this->player.leftDirection = true;
				}
				if (this->evt.key.code == sf::Keyboard::D) {
					this->player.rightDirection = true;
				}
				break;
			case (sf::Event::KeyReleased):
				if (this->evt.key.code == sf::Keyboard::W) {
					this->player.upDirection = false;
				}
				if (this->evt.key.code == sf::Keyboard::S) {
					this->player.downDirection = false;
				}
				if (this->evt.key.code == sf::Keyboard::A) {
					this->player.leftDirection = false;
				}
				if (this->evt.key.code == sf::Keyboard::D) {
					this->player.rightDirection = false;
				}
				break;
		}		
	}
}


void Game::Update() {
	this->Poll();

	this->player.Update();
}

void Game::Render() {
	this->window->clear(sf::Color(50, 200, 100));

	//this->player->Render();


	this->window->display();
}
