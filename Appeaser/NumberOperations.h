#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class NumberOperations {

	public:

		static int GetRandomNumber(int aMin, int aMax);

		static Vector2f NormalizeVector2f(Vector2f aVector2);

		static float GetDistanceBetween(Vector2f aVector2, Vector2f anotherVector2);

};