#include "Game.h"
#include "NumberOperations.h"

#pragma region Construction
Game::Game() {
	wave = new Wave();
	player = Player(sf::Vector2f(100.f, 100.f), sf::Sprite());
	InitVars();
	InitWindow();
	GenerateGravestones();
	InitObjects();
}

Game::~Game() {
	delete window;
	delete wave;
}
#pragma endregion

#pragma region Initialization
void Game::InitVars() {
	window = nullptr;
}

void Game::InitWindow() {
	videoMode.width = 800;
	videoMode.height = 600;
	window = new sf::RenderWindow(videoMode, "Appeaser", sf::Style::Titlebar | sf::Style::Close);
	window->setFramerateLimit(frameRate);
}

void Game::InitObjects() {
	wave->Init();
	player.Init();
	for (int i = 0; i < graveCount; i++) {
		gravestones[i].Init();
	}
}
#pragma endregion

#pragma region Functionality
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
	for (int i = 0; i < graveCount; i++) {
		gravestones[i] = Gravestone(sf::Vector2f(NumberOperations::GetRandomNumber(0, videoMode.width), NumberOperations::GetRandomNumber(0, videoMode.height)), sf::Sprite(), NumberOperations::GetRandomNumber(0, 8));
		enemies[i] = Enemy(sf::Vector2f(-32.f, -32.f), sf::Sprite());
		enemies[i].GetSprite().setScale(sf::Vector2f(0.f, 0.f));
	}
}

void Game::CheckCollisions() {
	sf::Sprite playerSprite = player.GetSprite();
	for (int i = 0; i < graveCount; i++) {
		sf::Sprite rect = gravestones[i].GetSprite();
		if (playerSprite.getGlobalBounds().intersects(rect.getGlobalBounds())) {
			if (Collision::PixelPerfectTest(rect, playerSprite, 255.f)) {
				player.ResetPos();
			}
		}
		sf::Sprite waveSprite = wave->GetSprite();
		if (waveSprite.getGlobalBounds().intersects(rect.getGlobalBounds())) {
			if (Collision::PixelPerfectTest(rect, waveSprite)) {
				if (!gravestones[i].AlreadyCharging()) {
					gravestones[i].Charge();
				}
			}
		}
	}
	for (int i = 0; i < graveCount; i++) {
		sf::Sprite rect = enemies[i].GetSprite();
		if (playerSprite.getGlobalBounds().intersects(rect.getGlobalBounds())) {
			if (Collision::PixelPerfectTest(enemies[i].GetSprite(), player.GetSprite())) {
				std::cout << "you died...\n";
			}
		}
	}
	for (int i = 0; i < graveCount; i++) {
		sf::Sprite rect = enemies[i].GetSprite();
		for (Gravestone g : gravestones) {
			if (g.GetSprite().getGlobalBounds().intersects(rect.getGlobalBounds())) {
				if (Collision::PixelPerfectTest(g.GetSprite(), rect)) {
					enemies[i].ResetPos();
					enemies[i].RecalculateVelocity();
				}
			}
		}
	}
}

void Game::UpdateTimer() {
	currentTime++;
	if (currentTime >= timer) {
		currentTime = 0;
		delete wave;
		wave = new Wave();
		wave->Init();
		timer = NumberOperations::GetRandomNumber(10.f, 20.f) * frameRate;
		std::cout << "A wave of energy has appeared...\n";
		for (int i = 0; i < graveCount; i++) {
			gravestones[i].EnableCharge();
		}
	}
}
#pragma endregion

#pragma region Update
	void Game::Update() {
		Poll();
		UpdateTimer();
		wave->Update();
		player.Update();
		for (int i = 0; i < graveCount; i++) {
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

		wave->Render(window);
		player.Render(window);
		for (int i = 0; i < graveCount; i++) {
			gravestones[i].Render(window);
			if (enemies[i].IsEnabled()) {
				enemies[i].Render(window);
			}
		}

		window->display();
	}
#pragma endregion