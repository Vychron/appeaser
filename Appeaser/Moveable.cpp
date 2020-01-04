#include "Moveable.h"

Moveable::Moveable() : Object() {

}

Moveable::Moveable(sf::Vector2f aPosition, sf::RectangleShape aSprite) : Object(aPosition, aSprite) {

}

Moveable::~Moveable() {

}

void Moveable::Move() {
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
	position += movement;
	sprite.setPosition(sf::Vector2f(position.x - (sprite.getSize().x / 2.f), position.y - (sprite.getSize().y / 2.f)));
}

void Moveable::Update() {
	Move();
}

void Moveable::Render(sf::RenderWindow* aWindow) {
	Object::Render(aWindow);
}