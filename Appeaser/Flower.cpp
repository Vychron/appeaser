#include "Flower.h"

#pragma region Construction
Flower::Flower() : GameObject() {

}

Flower::Flower(Vector2f aPosition, Sprite aSprite) : GameObject(aPosition, aSprite) {

}

Flower::~Flower() {

}
#pragma endregion

#pragma region Initialization
void Flower::Init() {
	texture.loadFromFile("Images/Flower.png");
	sprite.setTexture(texture);
	durability = 5;
}
#pragma endregion

#pragma region Functionality
void Flower::Respawn(Vector2f aPosition) {
	std::cout << "A bouquet of flowers has been placed on a grave.\n";
	position = aPosition + Vector2f(0.f, 32.f);
	sprite.setScale(Vector2f(1.f, 1.f));
	sprite.setPosition(Vector2f(position.x - (16.f), position.y - (16.f)));
	Init();
}

void Flower::ReduceDurability() {
	durability--;
	alreadyReduced = true;
}

int Flower::GetDurability() {
	return durability;
}

bool Flower::IsEnabled() {
	return enabled;
}

void Flower::Enable() {
	enabled = true;
}

void Flower::Disable() {
	enabled = false;
	position = Vector2f(-32.f, -32.f);
	sprite.setScale(Vector2f(0.f, 0.f));
	sprite.setPosition(Vector2f(position.x - (16.f), position.y - (16.f)));
}

bool Flower::AlreadyReduced() {
	return alreadyReduced;
}

void Flower::EnableDurability() {
	alreadyReduced = false;
}
#pragma endregion

#pragma region Update
void Flower::Render(RenderWindow* aWindow) {
	// only render "existing" flowers
	if (enabled) {
		GameObject::Render(aWindow);
	}
}
#pragma endregion
