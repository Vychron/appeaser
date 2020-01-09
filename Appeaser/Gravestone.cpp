#include "Gravestone.h"

//Construction
Gravestone::Gravestone() : GameObject() {

}

Gravestone::Gravestone(sf::Vector2f aPosition, sf::RectangleShape aSprite) : GameObject(aPosition, aSprite) {

}

Gravestone::Gravestone(sf::Vector2f aPosition, sf::RectangleShape aSprite, int aChargeValue) : GameObject(aPosition, aSprite) {
	chargeValue = aChargeValue;
	sprite.setFillColor(sf::Color((255 / chargeCap) * chargeValue, (255 / chargeCap) * chargeValue, 0, 255));
}

Gravestone::~Gravestone() {

}
//~Construction

//Initialization
void Gravestone::Init() {

}
//~Initialization

//Functionality
void Gravestone::Charge() {
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
	sprite.setFillColor(sf::Color((255 / chargeCap) * chargeValue, (255 / chargeCap) * chargeValue, 0, 255));
}

bool Gravestone::IsCharged() {
	return isCharged;
}

void Gravestone::ResetCharge() {
	chargeValue = 1;
}
//Functionality

//Update
void Gravestone::Update() {
	
}

void Gravestone::Render(sf::RenderWindow* aWindow) {
	GameObject::Render(aWindow);
}
//~Update