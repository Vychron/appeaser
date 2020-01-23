#include "Wave.h"

//Construction
Wave::Wave() {

}

Wave::Wave(sf::Vector2f aPosition, sf::Sprite aSprite) {
	sprite = aSprite;
}

Wave::~Wave() {

}
//~Construction

//Initialization
void Wave::Init() {
	texture.loadFromFile("#");
	sprite.setTexture(texture);
}
//~Initialization

//Functionality
//~Functionality

//Update
void Wave::Update() {

}

void Wave::Render(sf::RenderWindow* aWindow) {
	//Moveable::Render(aWindow);
	aWindow->draw(sprite);
}
//~Update