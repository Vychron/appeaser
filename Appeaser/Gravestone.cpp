#include "Gravestone.h"

#pragma region Construction
Gravestone::Gravestone() : GameObject() {

}

Gravestone::Gravestone(sf::Vector2f aPosition, sf::Sprite aSprite) : GameObject(aPosition, aSprite) {

}

Gravestone::Gravestone(sf::Vector2f aPosition, sf::Sprite aSprite, int aChargeValue) : GameObject(aPosition, aSprite) {
	chargeValue = aChargeValue;
}

Gravestone::~Gravestone() {

}
#pragma endregion

#pragma region Initialization
void Gravestone::Init() {
	texture.loadFromFile("Images/Gravestone.png");
	sprite.setTexture(texture);
	sprite.setColor(sf::Color((255 / chargeCap) * chargeValue, (255 / chargeCap) * chargeValue, 0, 255));
}
#pragma endregion

#pragma region Functionality
void Gravestone::Charge() {
	alreadyCharging = true;
	if (isCharged) {
		return;
	}
	chargeValue++;
	if (chargeValue > chargeCap) {
		isCharged = true;
		std::cout << "A gravestone has fully charged, a restless spirit emerges... \n";
		return;
	}
	isCharged = false;
	std::cout << "The wave of energy flows through a gravestone... \n";
	sprite.setColor(sf::Color((255 / chargeCap) * chargeValue, (255 / chargeCap) * chargeValue, 0, 255));
}

bool Gravestone::IsCharged() {
	return isCharged;
}

void Gravestone::ResetCharge() {
	chargeValue = 1;
}

bool Gravestone::AlreadyCharging() {
	return alreadyCharging;
}

void Gravestone::EnableCharge() {
	alreadyCharging = false;
}
#pragma endregion

#pragma region Update
void Gravestone::Update() {
	
}

void Gravestone::Render(sf::RenderWindow* aWindow) {
	GameObject::Render(aWindow);
}
#pragma endregion