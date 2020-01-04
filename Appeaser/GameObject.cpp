#include "GameObject.h"

//Construction
GameObject::GameObject() {
	sprite = sf::RectangleShape(sf::Vector2f(32.f, 32.f));
}

GameObject::GameObject(sf::Vector2f aPosition, sf::RectangleShape aSprite) {
	position = aPosition;
	sprite = aSprite;
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
//~Functionality

//Update
void GameObject::Render(sf::RenderWindow* aWindow) {
	aWindow->draw(sprite);
}
//~Update