#include "Gravestone.h"

//Construction
Gravestone::Gravestone() : GameObject() {

}

Gravestone::Gravestone(sf::Vector2f aPosition, sf::RectangleShape aSprite) : GameObject(aPosition, aSprite) {

}

Gravestone::Gravestone(sf::Vector2f aPosition, sf::RectangleShape aSprite, int aChargeValue) : GameObject(aPosition, aSprite) {
	chargeValue = aChargeValue;
}

Gravestone::~Gravestone() {

}
//~Construction

//Initialization
void Gravestone::Init() {
	sprite.setFillColor(sf::Color((255 / chargeCap) * chargeValue, 0, 0, 255));
}
//~Initialization

//Functionality
void Gravestone::Charge() {
	chargeValue++;
	if (chargeValue > chargeCap) {
		chargeValue -= chargeCap;
	}
	sprite.setFillColor(sf::Color((255 / chargeCap) * chargeValue, 0, 0, 255));
}
//Functionality

//Update
void Gravestone::Update() {
	
}

void Gravestone::Render(sf::RenderWindow* aWindow) {
	GameObject::Render(aWindow);
}
//~Update