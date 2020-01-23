#include "Wave.h"

//Construction
Wave::Wave() : Moveable() {

}

Wave::Wave(sf::Vector2f aPosition, sf::Sprite aSprite) : Moveable(aPosition, aSprite) {
	position = aPosition;
	sprite = aSprite;
}

Wave::~Wave() {

}
//~Construction

//Initialization
void Wave::Init() {
	moveSpeed = 20.f;
	SetRandomDirecion();
}
//~Initialization

//Functionality
void Wave::SetRandomDirecion() {
	while (velocity == sf::Vector2f(0.f, 0.f)) {
		velocity = sf::Vector2f(NumberOperations::GetRandomNumber(-2.f, 2.f), NumberOperations::GetRandomNumber(-2.f, 2.f));
		std::cout << velocity.x << ", " << velocity.y << "\n";
	}
	upDirection = downDirection = leftDirection = rightDirection = false;
	if (velocity.x > 0) {
		leftDirection = false;
		rightDirection = true;
	}
	else if (velocity.x < 0) {
		leftDirection = true;
		rightDirection = false;
	}
	if (velocity.y > 0) {
		upDirection = false;
		downDirection = true;
	}
	else if (velocity.y < 0) {
		upDirection = true;
		downDirection = false;
	}
	SetSpriteAndPosition();
}

void Wave::SetSpriteAndPosition() {
	if (upDirection) {
		if (leftDirection) {
			velocity = sf::Vector2f(-8, -6);
			texture.loadFromFile("Images/Wave-UpLeft.png");
			position = sf::Vector2f(1000.f, 750.f);
		}
		else if (rightDirection) {
			velocity = sf::Vector2f(8, -6);
			texture.loadFromFile("Images/Wave-UpRight.png");
			position = sf::Vector2f(-200.f, 750.f);
		}
		else {
			velocity = sf::Vector2f(0, -6);
			texture.loadFromFile("Images/Wave-Up.png");
			position = sf::Vector2f(400.f, 632.f);
		}
	}
	else if (downDirection) {
		if (leftDirection) {
			velocity = sf::Vector2f(-8, 6);
			texture.loadFromFile("Images/Wave-DownLeft.png");
			position = sf::Vector2f(1000.f, -150.f);
		}
		else if (rightDirection) {
			velocity = sf::Vector2f(8, 6);
			texture.loadFromFile("Images/Wave-DownRight.png");
			position = sf::Vector2f(-200.f, -150.f);
		}
		else {
			velocity = sf::Vector2f(0, 6);
			texture.loadFromFile("Images/Wave-Down.png");
			position = sf::Vector2f(400.f, -32.f);
		}
	}
	else if (leftDirection) {
		velocity = sf::Vector2f(-8, 0);
		texture.loadFromFile("Images/Wave-Left.png");
		position = sf::Vector2f(832.f, 300.f);
	}
	else {
		velocity = sf::Vector2f(8, 0);
		texture.loadFromFile("Images/Wave-Right.png");
		position = sf::Vector2f(-32.f, 300.f);
	}
	sprite.setTexture(texture);
}

void Wave::Flow() {
	position += (NumberOperations::NormalizeVector2f(velocity) * moveSpeed);
	sprite.setPosition(sf::Vector2f(position.x - (texture.getSize().x / 2.f), position.y - (texture.getSize().y / 2.f)));
}
//~Functionality

//Update
void Wave::Update() {
	Flow();
}

void Wave::Render(sf::RenderWindow* aWindow) {
	Moveable::Render(aWindow);
}
//~Update