#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Gravestone.h"
#include "Enemy.h"
#include "Wave.h";

class Game {

	private:

		sf::RenderWindow* window;
		sf::VideoMode videoMode;
		sf::Event evt;
		int count = 10;

		Player player;
		Gravestone gravestones[10];
		Enemy enemies[10];

		void GenerateGravestones();
		void CheckCollisions();

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

	protected:

		Wave wave;
};

