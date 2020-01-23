#include "Enemy.h"
#include "NumberOperations.h"

//Construction
Enemy::Enemy() : Moveable() {

}

Enemy::Enemy(sf::Vector2f aPosition, sf::Sprite aSprite) : Moveable(aPosition, aSprite) {

}

Enemy::~Enemy() {

}
//~Construction

//Initialization
void Enemy::Init() {
	moveSpeed = 5.f;
	texture.loadFromFile("Images/Player-Front.png");
	sprite.setTexture(texture);
	sprite.setColor(sf::Color::Red);
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

void Enemy::RecalculateVelocity() {
	velocity = sf::Vector2f(0.f, 0.f);
	stepCount = stepCountMax;
}

void Enemy::PassPlayerPosition(sf::Vector2f aPosition) {
	playerPosition = aPosition;
}

void Enemy::Respawn(sf::Vector2f aPosition) {
	enabled = true;
	position = aPosition + sf::Vector2f(0.f, 32.f);
	sprite.setScale(sf::Vector2f(1.f, 1.f));
	sprite.setPosition(sf::Vector2f(position.x - (16.f), position.y - (16.f)));
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