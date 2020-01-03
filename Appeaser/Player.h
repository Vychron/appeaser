#pragma once

#include <SFML/Graphics.hpp>

class Player {

	private:
		void UpdateVelocity();

	public:

		bool upDirection;
		bool downDirection;
		bool leftDirection;
		bool rightDirection;
		sf::Vector2f velocity;

		Player();
		virtual ~Player();

		void Init();
		void Update();
		void Render();

};

