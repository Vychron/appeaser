#include "Enemy.h"
#include "NumberOperations.h"

//Construction
Enemy::Enemy() : Moveable() {

}

Enemy::Enemy(sf::Vector2f aPosition, sf::RectangleShape aSprite) : Moveable(aPosition, aSprite) {

}

Enemy::~Enemy() {

}
//~Construction

//Initialization
void Enemy::Init() {
	moveSpeed = 2.5f;
	sprite.setFillColor(sf::Color::Red);
}
//~Initialization

//Functionality
void Enemy::UpdateVelocity() {
	stepCount++;
	if (stepCount >= stepCountMax) {
		stepCount -= stepCountMax;
		if (NumberOperations::GetRandomNumber(0, 10) > 3) {
			velocity = playerPosition - position;
		}
		else {
			velocity = sf::Vector2f(NumberOperations::GetRandomNumber(-1, 1), NumberOperations::GetRandomNumber(-1, 1));
		}
	}
}

void Enemy::PassPlayerPosition(sf::Vector2f aPosition) {
	playerPosition = aPosition;
}

void Enemy::Respawn(sf::Vector2f aPosition) {
	enabled = true;
	position = aPosition + sf::Vector2f(0.f, 32.f);
	sprite.setScale(sf::Vector2f(1.f, 1.f));
	sprite.setPosition(sf::Vector2f(position.x - (sprite.getSize().x / 2), position.y - (sprite.getSize().y / 2)));
	Init();
}

bool Enemy::IsEnabled() {
	return enabled;
}

void Enemy::Enable() {
	enabled = true;
}
//~Functionality

//Update
void Enemy::Update() {
	UpdateVelocity();
	Moveable::Update();
}

void Enemy::Render(sf::RenderWindow* aWindow) {
	Moveable::Render(aWindow);
}
//~Update