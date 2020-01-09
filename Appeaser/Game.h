#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Gravestone.h"
#include "Enemy.h"

class Game {

	private:

		sf::RenderWindow* window;
		sf::VideoMode videoMode;
		sf::Event evt;
		int count = 1;

		Gravestone gravestones[1];
		Enemy enemies[1];

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

		Player player;
};

