#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Gravestone.h"
#include "Enemy.h"
#include "Wave.h"
#include "Flower.h"
#include "Garlic.h"

using namespace sf;

class Game {

	private:

		int frameRate = 12;
		float waveTimer = 0;
		float currentWaveTime = 0;
		float garlicTimer = 3;
		float currentGarlicTime = 0;

		RenderWindow* window;
		VideoMode videoMode;
		Event evt;
		int graveCount = 10;

		Player player;
		Gravestone gravestones[10];
		Enemy enemies[10];
		Wave* wave;
		Flower flowers[10];
		Garlic garlic;

		void GenerateGraves();
		void CheckCollisions();
		void UpdateTimers();

		void InitVars();
		void InitWindow();
		void InitObjects();

	public:

		Game();
		virtual ~Game();

		const bool running() const;

		void Poll();
		void Update();
		void Render();

};

