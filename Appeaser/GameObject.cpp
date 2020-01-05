#include "GameObject.h"

//Construction
GameObject::GameObject() {
	sprite = sf::RectangleShape(sf::Vector2f(32.f, 32.f));
}

GameObject::GameObject(sf::Vector2f aPosition, sf::RectangleShape aSprite) {
	position = aPosition;
	sprite = aSprite;
	sprite.setPosition(sf::Vector2f(position.x - (sprite.getSize().x / 2.f), position.y - (sprite.getSize().y / 2.f)));
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

sf::RectangleShape GameObject::GetSprite() {
	return sprite;
}
//~Functionality

//Update
void GameObject::Render(sf::RenderWindow* aWindow) {
	aWindow->draw(sprite);
}
//~Update