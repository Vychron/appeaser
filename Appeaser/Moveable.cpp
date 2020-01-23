#include "Moveable.h"
#include "NumberOperations.h"

//Construction
Moveable::Moveable() : GameObject() {

}

Moveable::Moveable(sf::Vector2f aPosition, sf::Sprite aSprite) : GameObject(aPosition, aSprite) {

}

Moveable::~Moveable() {

}
//~Construction

//Initialization
//~Initialization

//Functionality
void Moveable::Move() {
	prevPos = position;
	sf::Vector2f movement = velocity;
	//Checking boundaries
	if (position.x < 0 || position.x > 800) {
		movement.x = 0;
		if (position.x < 0) {
			position.x = 0;
		}
		else {
			position.x = 800;
		}
	}
	if (position.y < 0 || position.y > 600) {
		movement.y = 0;
		if (position.y < 0) {
			position.y = 0;
		}
		else {
			position.y = 600;
		}
	}
	//Updating position
	position += (NumberOperations::NormalizeVector2f(movement) * moveSpeed);
	sprite.setPosition(sf::Vector2f(position.x - (16.f), position.y - (16.f)));
}

void Moveable::ResetPos() {
	position = prevPos;
	sprite.setPosition(sf::Vector2f(position.x - (16.f), position.y - (16.f)));
}
//~Functionality

//Update
void Moveable::Update() {
	Move();
}

void Moveable::Render(sf::RenderWindow* aWindow) {
	GameObject::Render(aWindow);
}
//~Update