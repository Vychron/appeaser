#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Gravestone.h"
#include "Enemy.h"
#include "Wave.h"
#include "Flower.h"
#include "Garlic.h"
#include "NumberOperations.h"

using namespace sf;

class Game {

	private:

		int frameRate = 12;
		float waveTimer = 0;
		float currentWaveTime = 0;
		float garlicTimer = 3;
		float currentGarlicTime = 0;
		bool started = false;
		bool completed = false;
		bool completeCheck = false;

		RenderWindow* window;
		VideoMode videoMode;
		Event evt;
		int graveCount = 24;

		Font font;
		Text text;

		Player player;
		Gravestone gravestones[28] = {
			Gravestone(Vector2f(100.f, 100.f), Sprite()),
			Gravestone(Vector2f(150.f, 100.f), Sprite()),
			Gravestone(Vector2f(200.f, 100.f), Sprite()),
			Gravestone(Vector2f(600.f, 100.f), Sprite()),
			Gravestone(Vector2f(650.f, 100.f), Sprite()),
			Gravestone(Vector2f(700.f, 100.f), Sprite()),
			Gravestone(Vector2f(100.f, 200.f), Sprite()),
			Gravestone(Vector2f(150.f, 200.f), Sprite()),
			Gravestone(Vector2f(200.f, 200.f), Sprite()),
			Gravestone(Vector2f(600.f, 200.f), Sprite()),
			Gravestone(Vector2f(650.f, 200.f), Sprite()),
			Gravestone(Vector2f(700.f, 200.f), Sprite()),
			Gravestone(Vector2f(100.f, 400.f), Sprite()),
			Gravestone(Vector2f(150.f, 400.f), Sprite()),
			Gravestone(Vector2f(200.f, 400.f), Sprite()),
			Gravestone(Vector2f(600.f, 400.f), Sprite()),
			Gravestone(Vector2f(650.f, 400.f), Sprite()),
			Gravestone(Vector2f(700.f, 400.f), Sprite()),
			Gravestone(Vector2f(100.f, 500.f), Sprite()),
			Gravestone(Vector2f(150.f, 500.f), Sprite()),
			Gravestone(Vector2f(200.f, 500.f), Sprite()),
			Gravestone(Vector2f(600.f, 500.f), Sprite()),
			Gravestone(Vector2f(650.f, 500.f), Sprite()),
			Gravestone(Vector2f(700.f, 500.f), Sprite())
		};
		Enemy enemies[28];
		Wave* wave;
		Flower flowers[28];
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

