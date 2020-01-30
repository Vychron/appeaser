#include "Enemy.h"
#include "NumberOperations.h"

#pragma region Construction
Enemy::Enemy() : Moveable() {

}

Enemy::Enemy(Vector2f aPosition, Sprite aSprite) : Moveable(aPosition, aSprite) {

}

Enemy::~Enemy() {

}
#pragma endregion

#pragma region Initialization
void Enemy::Init() {
	moveSpeed = 5.f;
	texture.loadFromFile("Images/Player-Front.png");
	sprite.setTexture(texture);
	sprite.setColor(Color::Red);
}
#pragma endregion

#pragma region Functionality
void Enemy::UpdateVelocity() {
	stepCount++;
	if (stepCount >= stepCountMax) {
		stepCount -= stepCountMax;
		if (NumberOperations::GetRandomNumber(0, 10) > 3) {
			velocity = playerPosition - position;
		}
		else {
			velocity = Vector2f(NumberOperations::GetRandomNumber(-1, 1), NumberOperations::GetRandomNumber(-1, 1));
		}
	}
}

void Enemy::RecalculateVelocity() {
	velocity = Vector2f(0.f, 0.f);
	stepCount = stepCountMax;
}

void Enemy::PassPlayerPosition(Vector2f aPosition) {
	playerPosition = aPosition;
}

void Enemy::Respawn(Vector2f aPosition) {
	enabled = true;
	position = aPosition + Vector2f(0.f, 32.f);
	sprite.setScale(Vector2f(1.f, 1.f));
	sprite.setPosition(Vector2f(position.x - (16.f), position.y - (16.f)));
	Init();
}

bool Enemy::IsEnabled() {
	return enabled;
}

void Enemy::Enable() {
	enabled = true;
}

void Enemy::Kill() {
	enabled = false;
	sprite.setScale(Vector2f(0.f, 0.f));
	position = Vector2f(-32.f, -32.f);
	sprite.setPosition(Vector2f(position.x - (16.f), position.y - (16.f)));
}
#pragma endregion

#pragma region Update
void Enemy::Update() {
	if (enabled) {
		UpdateVelocity();
		Moveable::Update();
	}
}

void Enemy::Render(RenderWindow* aWindow) {
	if (enabled) {
		Moveable::Render(aWindow);
	}
}
#pragma endregion