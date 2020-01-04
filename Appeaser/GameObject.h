#pragma once

#include <SFML/Graphics.hpp>
#include "iostream"

class GameObject {

	private:

	public:

		GameObject();
		GameObject(sf::Vector2f aPosition, sf::RectangleShape aSprite);
		virtual ~GameObject();

		sf::Vector2f GetPosition();
		sf::RectangleShape GetSprite();

		void Render(sf::RenderWindow* aWindow);
		
	protected:

		sf::Vector2f position;
		sf::RectangleShape sprite;
		
};

