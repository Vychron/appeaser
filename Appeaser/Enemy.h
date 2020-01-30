#pragma once

#include "Moveable.h"

using namespace sf;

class Enemy : public Moveable {

	private:

		int stepCount = 0;
		int stepCountMax = 10;
		bool enabled = false;
		void UpdateVelocity();

	public:

		Vector2f playerPosition = Vector2f(0.f, 0.f);

		Enemy();
		Enemy(Vector2f aPosition, Sprite aSprite);
		virtual ~Enemy();

		void RecalculateVelocity();
		void PassPlayerPosition(Vector2f aPosition);
		void Respawn(sf::Vector2f aPosition);
		bool IsEnabled();
		void Enable();
		void Kill();

		void Init();
		void Update();
		void Render(RenderWindow* aWindow);

};

