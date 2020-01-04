#pragma once
#include <SFML/Graphics.hpp>
#include "iostream"

class Object {

	private:

	public:

		Object();
		Object(sf::Vector2f aPosition, sf::RectangleShape aSprite);
		virtual ~Object();

		sf::Vector2f GetPosition();
		void Render(sf::RenderWindow* aWindow);
		
	protected:

		sf::Vector2f position;
		sf::RectangleShape sprite;
		
};

