#pragma once

#include "GameObject.h"

class Gravestone : public GameObject {

	private:

	public:

		Gravestone();
		Gravestone(sf::Vector2f aPosition, sf::RectangleShape aSprite);
		virtual ~Gravestone();

		void Render(sf::RenderWindow* aWindow);

	protected:

};

