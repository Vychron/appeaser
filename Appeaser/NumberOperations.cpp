#include "NumberOperations.h"
#include <random>

int NumberOperations::GetRandomNumber(int aMin, int aMax) {
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(aMin, aMax);
	return distr(eng);
}

sf::Vector2f NumberOperations::NormalizeVector2f(sf::Vector2f aVector2) {
	float length = sqrt((aVector2.x * aVector2.x) + (aVector2.y * aVector2.y));
	if (length != 0) {
		return sf::Vector2f(aVector2.x / length, aVector2.y / length);
	}
	else {
		return aVector2;
	}
}