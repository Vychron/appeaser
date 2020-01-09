#pragma once

#include <SFML/Graphics.hpp>

class NumberOperations
{
	public:

		static int GetRandomNumber(int aMin, int aMax);

		static sf::Vector2f NormalizeVector2f(sf::Vector2f aVector2);
};