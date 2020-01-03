#include "Game.h"

void Game::InitVars() {
	this->window = nullptr;
}

void Game::InitWindow() {
	this->videoMode.width = 800;
	this->videoMode.height = 600;
	this->window = new sf::RenderWindow(this->videoMode, "Appeaser", sf::Style::Titlebar | sf::Style::Close);
}

//Constructor
Game::Game() {
	this->InitVars();
	this->InitWindow();
}

//Deconstructor
Game::~Game() {
	delete this->window;
}

const bool Game::running() const {
	return this->window->isOpen();
}

//Functions

void Game::PollEvents() {
	while (this->window->pollEvent(this->evt)) {
		switch (this->evt.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		}
	}
}


void Game::Update() {
	this->PollEvents();
}

void Game::Render() {
	this->window->clear(sf::Color(50, 200, 100));




	this->window->display();
}
