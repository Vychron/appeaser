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
	started = false;
	completed = false;
}

void Game::InitWindow() {
	// setting up the window
	videoMode.width = 800;
	videoMode.height = 600;
	window = new RenderWindow(videoMode, "Appeaser", Style::Titlebar | Style::Close);
	window->setFramerateLimit(frameRate);
	// Startup message to give a brief explanation
	window->clear(sf::Color(50, 200, 100));
	font.loadFromFile("Fonts/sansation.ttf");
	text.setFont(font);
	text.setOutlineColor(Color::Black);
	text.setOutlineThickness(2.f);
	text.setString(
		"A strange energy flows around the graveyard\n"
		"Waves of this energy can flow over\nthe graveyard and reanimate the restless spirits\n"
		"Bring peace to the spirits by making them feel remembered\n\n"
		"Use WASD to move\n"
		"Use E to place garlic\n"
		"Use Spacebar to place flowers on graves\n\n"
		"Press any key to start");
	window->draw(text);
	window->display();
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
			// closing the game
			case (Event::Closed):
				std::cout << "closing the game";
				window->close();
				break;
			// player Actions
			case (Event::KeyPressed):
				// check to start the update and render loops only after pressing any key
				if (!started) {
					started = true;
					break;
				}
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
					// checking if the player can place flowers from it's current position
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
					// checking if the player can place garlic
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
	// checking the collisions of everything
	Sprite playerSprite = player.GetSprite();
	for (int i = 0; i < graveCount; i++) {
		Sprite rect = gravestones[i].GetSprite();
		// player and gravestones
		if (playerSprite.getGlobalBounds().intersects(rect.getGlobalBounds())) {
			if (Collision::PixelPerfectTest(rect, playerSprite)) {
				player.ResetPos();
			}
		}
		Sprite waveSprite = wave->GetSprite();
		// wave and gravestones
		if (waveSprite.getGlobalBounds().intersects(rect.getGlobalBounds())) {
			if (Collision::PixelPerfectTest(rect, waveSprite)) {
				// taking flowers into account
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
		// player and enemies
		if (playerSprite.getGlobalBounds().intersects(rect.getGlobalBounds())) {
			if (Collision::PixelPerfectTest(enemies[i].GetSprite(), player.GetSprite())) {
				std::cout << "You died...\n";
				text.setString("A restless spirit has mistaken you\nfor a relative that forgot him,\nand took your life as an act of revenge.");
				window->draw(text);
				window->display();
				completed = true;
			}
		}
		for (int j = 0; j < graveCount; j++) {
			// graves and enemies
			if (gravestones[j].GetSprite().getGlobalBounds().intersects(rect.getGlobalBounds())) {
				if (Collision::PixelPerfectTest(gravestones[j].GetSprite(), rect)) {
					enemies[i].ResetPos();
					enemies[i].RecalculateVelocity();
				}
			}
		}
		if (garlic.IsDetonating()) {
			// garlic and enemies
			if (NumberOperations::GetDistanceBetween(enemies[i].GetPosition(), garlic.GetPosition()) < (garlic.GetSprite().getScale().x * garlic.GetSprite().getTexture()->getSize().x) / 2.f) {
				enemies[i].Kill();
				gravestones[i].ResetCharge();
				std::cout << "An spirit has been chased away by the garlic and is now retreating.\n";
			}
		}
	}
}

void Game::UpdateTimers() {
	// update clock for waves
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
	// update clock for garlic
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
		
		// check if game should update
		if (!started || completed) {
			return;
		}
		UpdateTimers();
		wave->Update();
		garlic.Update();
		player.Update();
		completeCheck = true;
		// check for enemies to be updated
		for (int i = 0; i < graveCount; i++) {
			if (!enemies[i].IsEnabled() && gravestones[i].IsCharged()) {
				enemies[i].Respawn(gravestones[i].GetPosition());
			}
			if (enemies[i].IsEnabled()) {
				enemies[i].PassPlayerPosition(player.GetPosition());
			}
			// checking 
			if (!flowers[i].IsEnabled()) {
				completeCheck = false;
			}
			enemies[i].Update();
		}
		CheckCollisions();
		// on completion rendering one more frame before freezing on the end message
		if (completeCheck) {
			Render();
			completed = true;
			text.setString("You have calmed the souls, may they rest in peace now.");
			window->draw(text);
			window->display();
		}
	}

	void Game::Render() {
		// check if game should be rendered
		if (!started || completed) {
			return;
		}
		window->clear(sf::Color(50, 200, 100));
		wave->Render(window);
		for (int i = 0; i < graveCount; i++) { // separate loop to make sure all other sprites are drawn on top
			flowers[i].Render(window);
		}
		garlic.Render(window);
		player.Render(window);
		// rendering gravestones and enemies
		for (int i = 0; i < graveCount; i++) {
			gravestones[i].Render(window);
			enemies[i].Render(window);
		}
		window->display();
	}
#pragma endregion