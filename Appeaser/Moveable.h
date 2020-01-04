#pragma once

#include "Object.h"

class Moveable : public Object {

	private:

	public:

		Moveable();
		Moveable(sf::Vector2f aPosition, sf::RectangleShape aSprite);
		virtual ~Moveable();
	
		void Update();
		void Render(sf::RenderWindow* aWindow);

	protected:
		
		sf::Vector2f velocity;

		void Move();
};

