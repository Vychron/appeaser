#include "Game.h"
#include "NumberOperations.h"

//Construction
Game::Game() {
	player = Player(sf::Vector2f(100.f, 100.f), sf::RectangleShape(sf::Vector2f(32.f, 32.f)));
	InitVars();
	InitWindow();
	GenerateGravestones();
	InitObjects();
}

Game::~Game() {
	delete window;
}
//~Construction

//Initialization
void Game::InitVars() {
	window = nullptr;
}

void Game::InitWindow() {
	videoMode.width = 800;
	videoMode.height = 600;
	window = new sf::RenderWindow(videoMode, "Appeaser", sf::Style::Titlebar | sf::Style::Close);
	window->setFramerateLimit(30);
}

void Game::InitObjects() {
	player.Init();
	for (Gravestone g : gravestones) {
		g.Init();
	}
}
//~Initialization

//Functionality
const bool Game::running() const {
	return window->isOpen();
}

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
				
				if (evt.key.code == sf::Keyboard::Space) {
					for (int i = 0; i < count; i++) {
						gravestones[i].Charge();
					}
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

void Game::GenerateGravestones() {
	for (int i = 0; i < count; i++) {
		gravestones[i] = Gravestone(sf::Vector2f(NumberOperations::GetRandomNumber(0, videoMode.width), NumberOperations::GetRandomNumber(0, videoMode.height)), sf::RectangleShape(sf::Vector2f(32.f, 32.f)), NumberOperations::GetRandomNumber(0, 8));
		enemies[i] = Enemy(sf::Vector2f(-32.f, -32.f), sf::RectangleShape(sf::Vector2f(32.f, 32.f)));
		enemies[i].GetSprite().setScale(sf::Vector2f(0.f, 0.f));
	}
}

void Game::CheckCollisions() {
	sf::FloatRect sprite = player.GetSprite().getGlobalBounds();
	//checking graveStones
	for (Gravestone g : gravestones) {
		sf::FloatRect rect = g.GetSprite().getGlobalBounds();
		if (sprite.intersects(rect)) {
			player.ResetPos();
		}
	}
	for (Enemy e : enemies) {
		sf::FloatRect rect = e.GetSprite().getGlobalBounds();
		if (sprite.intersects(rect)) {
			std::cout << "you died";
		}
	}

	for (int i = 0; i < count; i++) {
		sf::FloatRect rect = enemies[i].GetSprite().getGlobalBounds();
		for (Gravestone g : gravestones) {
			if (g.GetSprite().getGlobalBounds().intersects(rect)) {
				enemies[i].ResetPos();
				enemies[i].RecalculateVelocity();
			}
		}
	}
}
//~Functionality

//Update
void Game::Update() {
	Poll();
	player.Update();
	for (int i = 0; i < count; i++) {
		if (!enemies[i].IsEnabled() && gravestones[i].IsCharged()) {
			enemies[i].Respawn(gravestones[i].GetPosition());
		}
		if (enemies[i].IsEnabled()) {
			enemies[i].PassPlayerPosition(player.GetPosition());
			enemies[i].Update();
		}
	}
	CheckCollisions();
}

void Game::Render() {
	window->clear(sf::Color(50, 200, 100));

	player.Render(window);
	for (int i = 0; i < count; i++) {
		gravestones[i].Render(window);
		if (enemies[i].IsEnabled()) {
			enemies[i].Render(window);
		}
	}
	window->display();
}
//~Update
