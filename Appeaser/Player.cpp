#include "Player.h"

//Construction
Player::Player() : Moveable() {

}

Player::Player(sf::Vector2f aPosition, sf::Sprite aSprite) : Moveable (aPosition, aSprite) {

}

Player::~Player() {

}
//~Construction

//Initialization
void Player::Init() {
	moveSpeed = 4.f;
	texture.loadFromFile("Images/Player-Front.png");
	sprite.setTexture(texture);
}
//~Initialization

//Functionality
void Player::UpdateVelocity() {
	sf::Vector2f vel = velocity;

	//Horizontal velocity
	if (leftDirection && !rightDirection) {
		velocity.x = -1.f;
	}
	else if (!leftDirection && rightDirection) {
		velocity.x = 1.f;
	}
	else {
		velocity.x = 0.f;
	}
	//Vertical velocity
	if (upDirection && !downDirection) {
		this->velocity.y = -1.f;
	}
	else if (!upDirection && downDirection) {
		velocity.y = 1.f;
	}
	else {
		velocity.y = 0.f;
	}

	//Printing the output to the console
	if (velocity != sf::Vector2f(0.f, 0.f) && velocity != vel) {
		std::cout << "Player is moving";
		if (velocity.y < 0.f) {
			std::cout << " Up";
		}
		else if (velocity.y > 0.f) {
			std::cout << " Down";
		}
		if (velocity.x != 0.f && velocity.y != 0.f) {
			std::cout << " and";
		}
		if (velocity.x < 0.f) {
			std::cout << " Left";
		}
		else if (velocity.x > 0.f) {
			std::cout << " Right";
		}
		std::cout << ".\n";
	}
}

void Player::SetUpDirection(bool active) {
	upDirection = active;
}
void Player::SetDownDirection(bool active) {
	downDirection = active;
}
void Player::SetLeftDirection(bool active) {
	leftDirection = active;
}
void Player::SetRightDirection(bool active) {
	rightDirection = active;
}
//~Functionality

//Update
void Player::Update() {
	UpdateVelocity();
	Moveable::Update();
}

void Player::Render(sf::RenderWindow* aWindow) {
	Moveable::Render(aWindow);
}
//~Update
