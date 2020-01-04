#pragma once

#include "GameObject.h"

class Moveable : public GameObject {

	private:

	public:

		Moveable();
		Moveable(sf::Vector2f aPosition, sf::RectangleShape aSprite);
		virtual ~Moveable();

		void ResetPos();

		void Update();
		void Render(sf::RenderWindow* aWindow);

	protected:
		
		sf::Vector2f prevPos;
		sf::Vector2f velocity;

		void Move();
};

