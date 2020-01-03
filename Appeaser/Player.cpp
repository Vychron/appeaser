#include "Player.h"

#include "iostream"

Player::Player() {
	this->upDirection = false;
	this->downDirection = false;
	this->leftDirection = false;
	this->rightDirection = false;
	this->velocity = sf::Vector2f(0.f, 0.f);
}

Player::~Player() {

}

void Player::UpdateVelocity() {
	sf::Vector2f vel = this->velocity;

	//Horizontal velocity
	if (this->leftDirection && !this->rightDirection) {
		this->velocity.x = -.1f;
	}
	else if (!this->leftDirection && this->rightDirection) {
		this->velocity.x = .1f;
	}
	else {
		this->velocity.x = 0.f;
	}
	//Vertical velocity
	if (this->upDirection && !this->downDirection) {
		this->velocity.y = -.1f;
	}
	else if (!this->upDirection && this->downDirection) {
		this->velocity.y = .1f;
	}
	else {
		this->velocity.y = 0.f;
	}
	if (this->velocity != sf::Vector2f(0.f, 0.f) && this->velocity != vel) {
		std::cout << "Moving";
		if (this->velocity.y < 0.f) {
			std::cout << " Up";
		}
		else if (this->velocity.y > 0.f) {
			std::cout << " Down";
		}
		if (this->velocity.x != 0.f && this->velocity.y != 0.f) {
			std::cout << " and";
		}
		if (this->velocity.x < 0.f) {
			std::cout << " Left";
		}
		else if (this->velocity.x > 0.f) {
			std::cout << " Right";
		}
		std::cout << ".\n";
	}
}

void Player::Init() {
	
}

void Player::Update() {
	this->UpdateVelocity();
}

void Player::Render() {

}
