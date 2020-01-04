#include "Gravestone.h"

//Construction
Gravestone::Gravestone() : GameObject() {

}

Gravestone::Gravestone(sf::Vector2f aPosition, sf::RectangleShape aSprite) : GameObject(aPosition, aSprite) {

}

Gravestone::~Gravestone() {

}
//~Construction

//Initialization
//~Initialization

//Functionality
//Functionality

//Update
void Gravestone::Render(sf::RenderWindow* aWindow) {
	GameObject::Render(aWindow);
}
//~Update