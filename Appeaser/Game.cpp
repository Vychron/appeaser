#include "Game.h"
#include "NumberOperations.h"

#pragma region Construction
Game::Game() {
	wave = new Wave();
	player = Player(Vector2f(100.f, 100.f), Sprite());
	InitVars();
	InitWindow();
	GenerateGraves();
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
	garlicTimer *= frameRate;
}

void Game::InitWindow() {
	videoMode.width = 800;
	videoMode.height = 600;
	window = new RenderWindow(videoMode, "Appeaser", Style::Titlebar | Style::Close);
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
		switch (evt.type) {
			//Closing the game
			case (Event::Closed):
				std::cout << "closing the game";
				window->close();
				break;
			//Player Actions
			case (Event::KeyPressed):
				if (evt.key.code == Keyboard::W) {
					player.SetUpDirection(true);
				}
				if (evt.key.code == Keyboard::S) {
					player.SetDownDirection(true);
				}
				if (evt.key.code == Keyboard::A) {
					player.SetLeftDirection(true);
				}
				if (evt.key.code == Keyboard::D) {
					player.SetRightDirection(true);
				}
				if (evt.key.code == Keyboard::Space) {
					float shortest = 1000.f;
					int currentI = 0;
					for (int i = 0; i < graveCount; i++) {
						float current = NumberOperations::GetDistanceBetween(player.GetPosition(), gravestones[i].GetPosition() + Vector2f(0.f, 32.f));
						if (current < shortest) {
							shortest = current;
							currentI = i;
						}
					}
					if (shortest < 48.f && !flowers[currentI].IsEnabled()) {
						flowers[currentI].Respawn(gravestones[currentI].GetPosition());
						flowers[currentI].Enable();
					}
				}
				if (evt.key.code == Keyboard::E) {
					if (!garlic.IsEnabled()) {
						garlic.Place(player.GetPosition());
						std::cout << "A Garlic has been placed.\n";
					}
				}
				break;
			case (Event::KeyReleased):
				if (evt.key.code == Keyboard::W) {
					player.SetUpDirection(false);
				}
				if (evt.key.code == Keyboard::S) {
					player.SetDownDirection(false);
				}
				if (evt.key.code == Keyboard::A) {
					player.SetLeftDirection(false);
				}
				if (evt.key.code == Keyboard::D) {
					player.SetRightDirection(false);
				}
				break;
		}
	}
}

void Game::GenerateGraves() {
	for (int i = 0; i < graveCount; i++) {
		gravestones[i] = Gravestone(Vector2f(NumberOperations::GetRandomNumber(0, videoMode.width), NumberOperations::GetRandomNumber(0, videoMode.height)), Sprite(), NumberOperations::GetRandomNumber(0, 8));
		enemies[i] = Enemy(Vector2f(-32.f, -32.f), Sprite());
		enemies[i].GetSprite().setScale(Vector2f(0.f, 0.f));
		flowers[i] = Flower(Vector2f(-32.f, -32.f), Sprite());
		flowers[i].GetSprite().setScale(Vector2f(0.f, 0.f));
	}
}

void Game::CheckCollisions() {
	Sprite playerSprite = player.GetSprite();
	for (int i = 0; i < graveCount; i++) {
		Sprite rect = gravestones[i].GetSprite();
		if (playerSprite.getGlobalBounds().intersects(rect.getGlobalBounds())) {
			if (Collision::PixelPerfectTest(rect, playerSprite)) {
				player.ResetPos();
			}
		}
		Sprite waveSprite = wave->GetSprite();
		if (waveSprite.getGlobalBounds().intersects(rect.getGlobalBounds())) {
			if (Collision::PixelPerfectTest(rect, waveSprite)) {
				if (flowers[i].IsEnabled()) {
					if (!flowers[i].AlreadyReduced()) {
						flowers[i].ReduceDurability();
						std::cout << "A flower has been touched by the energy wave and has been damaged.\n";
						if (flowers[i].GetDurability() < 1.f) {
							flowers[i].Disable();
							std::cout << "A flower has been destroyed by the energy wave.\n";
						}
					}
				}
				else if (!gravestones[i].AlreadyCharging()) {
					gravestones[i].Charge();
				}
			}
		}
	}
	for (int i = 0; i < graveCount; i++) {
		Sprite rect = enemies[i].GetSprite();
		if (playerSprite.getGlobalBounds().intersects(rect.getGlobalBounds())) {
			if (Collision::PixelPerfectTest(enemies[i].GetSprite(), player.GetSprite())) {
				std::cout << "you died...\n";
			}
		}
		for (int j = 0; j < graveCount; j++) {
			if (gravestones[j].GetSprite().getGlobalBounds().intersects(rect.getGlobalBounds())) {
				if (Collision::PixelPerfectTest(gravestones[j].GetSprite(), rect)) {
					enemies[i].ResetPos();
					enemies[i].RecalculateVelocity();
				}
			}
		}
		if (garlic.IsDetonating()) {
			if (NumberOperations::GetDistanceBetween(enemies[i].GetPosition(), garlic.GetPosition()) < (garlic.GetSprite().getScale().x * garlic.GetSprite().getTexture()->getSize().x) / 2.f) {
				enemies[i].Kill();
				gravestones[i].ResetCharge();
				std::cout << "An spirit has been chased away by the garlic and is now retreating.\n";
			}
		}
	}
}

void Game::UpdateTimers() {
	currentWaveTime++;
	if (currentWaveTime >= waveTimer) {
		currentWaveTime = 0;
		delete wave;
		wave = new Wave();
		wave->Init();
		waveTimer = NumberOperations::GetRandomNumber(10.f, 20.f) * frameRate;
		std::cout << "A wave of energy has appeared...\n";
		for (int i = 0; i < graveCount; i++) {
			gravestones[i].EnableCharge();
			flowers[i].EnableDurability();
		}
	}
	if (garlic.IsEnabled()) {
		currentGarlicTime++;
		if (currentGarlicTime >= garlicTimer) {
			currentGarlicTime = 0;
			garlic.Detonate();
		}
	}
}
#pragma endregion

#pragma region Update
	void Game::Update() {
		Poll();
		UpdateTimers();
		wave->Update();
		garlic.Update();
		player.Update();
		for (int i = 0; i < graveCount; i++) {
			if (!enemies[i].IsEnabled() && gravestones[i].IsCharged()) {
				enemies[i].Respawn(gravestones[i].GetPosition());
			}
			if (enemies[i].IsEnabled()) {
				enemies[i].PassPlayerPosition(player.GetPosition());
			}
			enemies[i].Update();
		}
		CheckCollisions();
	}

	void Game::Render() {
		window->clear(sf::Color(50, 200, 100));
		wave->Render(window);
		for (int i = 0; i < graveCount; i++) { // separate loop to make sure all other sprites are drawn on top
			flowers[i].Render(window);
		}
		garlic.Render(window);
		player.Render(window);
		for (int i = 0; i < graveCount; i++) {
			gravestones[i].Render(window);
			enemies[i].Render(window);
		}
		window->display();
	}
#pragma endregion