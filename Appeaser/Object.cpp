#include "Object.h"

Object::Object() {
	sprite = sf::RectangleShape(sf::Vector2f(32.f, 32.f));
}

Object::Object(sf::Vector2f aPosition, sf::RectangleShape aSprite) {
	position = aPosition;
	sprite = aSprite;
}

Object::~Object() {

}

sf::Vector2f Object::GetPosition() {
	return position;
}

void Object::Render(sf::RenderWindow* aWindow) {
	aWindow->draw(sprite);
}