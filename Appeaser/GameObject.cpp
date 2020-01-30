#include "GameObject.h"

#pragma region Construction
GameObject::GameObject() {
	sprite = Sprite();
	position = Vector2f(0.f, 0.f);
}

GameObject::GameObject(Vector2f aPosition, Sprite aSprite) {
	position = aPosition;
	sprite = aSprite;
	sprite.setPosition(Vector2f(position.x - (texture.getSize().x / 2.f), position.y - (texture.getSize().y / 2.f)));
}

GameObject::~GameObject() {

}
#pragma endregion

#pragma region Initialization
#pragma endregion

#pragma region Functionality
Vector2f GameObject::GetPosition() {
	return position;
}

Sprite GameObject::GetSprite() {
	return sprite;
}
#pragma endregion

#pragma region Update
void GameObject::Render(RenderWindow* aWindow) {
	aWindow->draw(sprite);
}
#pragma endregion