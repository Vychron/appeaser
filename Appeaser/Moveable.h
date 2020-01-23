#pragma once

#include "GameObject.h"

class Moveable : public GameObject {

	public:

		Moveable();
		Moveable(sf::Vector2f aPosition, sf::Sprite aSprite);
		virtual ~Moveable();

		void ResetPos();

		void Update();
		void Render(sf::RenderWindow* aWindow);

	protected:
		
		float moveSpeed = 0;
		sf::Vector2f velocity;
		sf::Vector2f prevPos;
		void Move();
};

