#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"

class Game {

	private:
		sf::RenderWindow* window;
		sf::VideoMode videoMode;
		sf::Event evt;

		Player player;

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

