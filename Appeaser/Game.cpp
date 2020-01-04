#include "Game.h"

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
	for (int i = 0; i < count; i++) {
		gravestones[i].Init();
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
	//count = sizeof(gravestones);
	for (int i = 0; i < count; i++) {
		gravestones[i] = Gravestone(sf::Vector2f(RandomNumber(0, videoMode.width), RandomNumber(0, videoMode.height)), sf::RectangleShape(sf::Vector2f(32.f, 32.f)), RandomNumber(0, 8));
	}
	std::cout << count;
}

int Game::RandomNumber(int aMin, int aMax) {
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(aMin, aMax);
	return distr(eng);
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
}
//~Functionality

//Update
void Game::Update() {
	Poll();
	player.Update();
	for (int i = 0; i < count; i++) {
		gravestones[i].Update();
	}

	CheckCollisions();
}

void Game::Render() {
	window->clear(sf::Color(50, 200, 100));

	player.Render(window);
	for (int i = 0; i < count; i++) {
		gravestones[i].Render(window);
	}

	window->display();
}
//~Update
