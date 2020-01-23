#include "GameObject.h"

//Construction
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
//~Construction

//Initialization
//~Initialization

//Functionality
sf::Vector2f GameObject::GetPosition() {
	return position;
}

sf::Sprite GameObject::GetSprite() {
	return sprite;
}
//~Functionality

//Update
void GameObject::Render(sf::RenderWindow* aWindow) {
	aWindow->draw(sprite);
}
//~Update