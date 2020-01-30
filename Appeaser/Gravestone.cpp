#include "Gravestone.h"

#pragma region Construction
Gravestone::Gravestone() : GameObject() {

}

Gravestone::Gravestone(Vector2f aPosition, Sprite aSprite) : GameObject(aPosition, aSprite) {

}

Gravestone::Gravestone(Vector2f aPosition, Sprite aSprite, int aChargeValue) : GameObject(aPosition, aSprite) {
	chargeValue = aChargeValue;
}

Gravestone::~Gravestone() {

}
#pragma endregion

#pragma region Initialization
void Gravestone::Init() {
	texture.loadFromFile("Images/Gravestone.png");
	sprite.setTexture(texture);
	sprite.setColor(Color((255 / chargeCap) * chargeValue, (255 / chargeCap) * chargeValue, 0, 255));
	sprite.setPosition(Vector2f(position.x - (texture.getSize().x / 2.f), position.y - (texture.getSize().y / 2.f)));
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
	sprite.setColor(Color((255 / chargeCap) * chargeValue, (255 / chargeCap) * chargeValue, 0, 255));
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
void Gravestone::Render(RenderWindow* aWindow) {
	GameObject::Render(aWindow);
}
#pragma endregion