#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Gravestone.h"
#include <vector>
#include <random>

class Game {

	private:
		sf::RenderWindow* window;
		sf::VideoMode videoMode;
		sf::Event evt;
		int count = 10;

		Player player;
		Gravestone gravestones[10];

		void GenerateGravestones();
		int RandomNumber(int aMin, int aMax);

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

