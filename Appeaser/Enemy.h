#pragma once

#include "Moveable.h"

class Enemy : public Moveable {

	private:

		int stepCount = 0;
		int stepCountMax = 10;
		bool enabled = false;
		void UpdateVelocity();

	public:

		sf::Vector2f playerPosition = sf::Vector2f(0.f, 0.f);

		Enemy();
		Enemy(sf::Vector2f aPosition, sf::RectangleShape aSprite);
		virtual ~Enemy();

		void PassPlayerPosition(sf::Vector2f aPosition);
		void Respawn(sf::Vector2f aPosition);
		bool IsEnabled();
		void Enable();

		void Init();
		void Update();
		void Render(sf::RenderWindow* aWindow);
};

