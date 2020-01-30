#include "NumberOperations.h"
#include <random>

#pragma region Functionality
int NumberOperations::GetRandomNumber(int aMin, int aMax) {
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(aMin, aMax);
	return distr(eng);
}

Vector2f NumberOperations::NormalizeVector2f(Vector2f aVector2) {
	float length = sqrt((aVector2.x * aVector2.x) + (aVector2.y * aVector2.y));
	if (length != 0) {
		return Vector2f(aVector2.x / length, aVector2.y / length);
	}
	else {
		return aVector2;
	}
}

float NumberOperations::GetDistanceBetween(Vector2f aVector2, Vector2f anotherVetor2) {
	Vector2f delta = Vector2f(std::abs(aVector2.x - anotherVetor2.x), std::abs(aVector2.y - anotherVetor2.y));
	return std::sqrtf(std::powf(delta.x, 2) + std::powf(delta.y, 2));
}
#pragma endregion