#include "GameObject.h"

#pragma region Construction
GameObject::GameObject() {
	sprite = sf::Sprite();
	position = sf::Vector2f(0.f, 0.f);
}

GameObject::GameObject(sf::Vector2f aPosition, sf::Sprite aSprite) {
	position = aPosition;
	sprite = aSprite;
	sprite.setPosition(sf::Vector2f(position.x - (texture.getSize().x /2.f), position.y - (texture.getSize().y / 2.f)));
}

GameObject::~GameObject() {

}
#pragma endregion

#pragma region Initialization
#pragma endregion

#pragma region Functionality
sf::Vector2f GameObject::GetPosition() {
	return position;
}

sf::Sprite GameObject::GetSprite() {
	return sprite;
}
#pragma endregion

#pragma region Update
void GameObject::Render(sf::RenderWindow* aWindow) {
	aWindow->draw(sprite);
}
#pragma endregion