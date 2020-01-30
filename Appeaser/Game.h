#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Gravestone.h"
#include "Enemy.h"
#include "Wave.h"
#include "Flower.h"

using namespace sf;

class Game {

	private:

		int frameRate = 12;
		float timer = 0;
		float currentTime = 0;

		RenderWindow* window;
		VideoMode videoMode;
		Event evt;
		int graveCount = 10;

		Player player;
		Gravestone gravestones[10];
		Enemy enemies[10];
		Wave* wave;
		Flower flowers[10];

		void GenerateGraves();
		void CheckCollisions();
		void UpdateTimer();

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

