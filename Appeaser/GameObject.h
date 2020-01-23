#pragma once

#include <SFML/Graphics.hpp>
#include "iostream"
#include "Collision.h"

class GameObject {

	public:

		GameObject();
		GameObject(sf::Vector2f aPosition, sf::Sprite aSprite);
		virtual ~GameObject();

		sf::Vector2f GetPosition();
		sf::Sprite GetSprite();

		void Render(sf::RenderWindow* aWindow);
		
	protected:

		sf::Vector2f position;
		sf::Sprite sprite;
		sf::Texture texture;
};

