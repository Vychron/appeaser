#pragma once

#include <SFML/Graphics.hpp>

class Game {

	private:
		sf::RenderWindow* window;
		sf::VideoMode videoMode;
		sf::Event evt;


		void InitVars();
		void InitWindow();

	public:

		Game();
		virtual ~Game();

		const bool running() const;

		void PollEvents();
		void Update();
		void Render();
};

