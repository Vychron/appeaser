#include "Garlic.h"

#pragma region Construction
Garlic::Garlic() : GameObject() {

}

Garlic::Garlic(Vector2f aPosition, Sprite aSprite) : GameObject(aPosition, aSprite) {

}

Garlic::~Garlic() {

}
#pragma endregion

#pragma region Initialization
void Garlic::Init() {
	enabled = true;
	texture.loadFromFile("Images/Garlic.png");
	sprite.setTexture(texture);
	sprite.setScale(Vector2f(1.f, 1.f));
}
#pragma endregion

#pragma region Functionality
void Garlic::Place(Vector2f aPosition) {
	Init();
	position = aPosition;
}

bool Garlic::IsEnabled() {
	return enabled;
}

bool Garlic::IsDetonating() {
	return isDetonating;
}

void Garlic::Detonate() {
	texture.loadFromFile("Images/Shockwave.png");
	sprite.setTexture(texture);
	sprite.setScale(Vector2f(0.f, 0.f));
	isDetonating = true;
}
#pragma endregion

#pragma region Update
void Garlic::Update() {
	if (enabled) {
		if (isDetonating) {
			if (sprite.getScale().x < 3) {
				sprite.setScale(sprite.getScale() + Vector2f(0.5f, 0.5f));
			}
			else {
				isDetonating = false;
				enabled = false;
				sprite.setScale(Vector2f(0.f, 0.f));
				position = Vector2f(-32.f, -32.f);
			}
		}
		sprite.setPosition(Vector2f(position.x - ((sprite.getTexture()->getSize().x / 2) * sprite.getScale().x), position.y - ((sprite.getTexture()->getSize().y / 2) * sprite.getScale().y)));
	}
}

void Garlic::Render(RenderWindow* aWindow) {
	if (enabled) {
		GameObject::Render(aWindow);
	}
}
#pragma endregion
