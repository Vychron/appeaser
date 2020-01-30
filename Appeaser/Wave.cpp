#include "Wave.h"

#pragma region Construction
Wave::Wave() : Moveable() {

}

Wave::Wave(Vector2f aPosition, Sprite aSprite) : Moveable(aPosition, aSprite) {
	position = aPosition;
	sprite = aSprite;
}

Wave::~Wave() {

}
#pragma endregion

#pragma region Initialization
void Wave::Init() {
	moveSpeed = 12.f;
	SetRandomDirecion();
}
#pragma endregion

#pragma region Functionality
void Wave::SetRandomDirecion() {
	velocity = Vector2f(0.f, 0.f);
	while (velocity == Vector2f(0.f, 0.f)) {
		velocity = Vector2f(NumberOperations::GetRandomNumber(-2.f, 2.f), NumberOperations::GetRandomNumber(-2.f, 2.f));
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
			velocity = Vector2f(-8, -6);
			texture.loadFromFile("Images/Wave-UpLeft.png");
			position = Vector2f(1000.f, 750.f);
		}
		else if (rightDirection) {
			velocity = Vector2f(8, -6);
			texture.loadFromFile("Images/Wave-UpRight.png");
			position = Vector2f(-200.f, 750.f);
		}
		else {
			velocity = Vector2f(0, -6);
			texture.loadFromFile("Images/Wave-Up.png");
			position = Vector2f(400.f, 632.f);
		}
	}
	else if (downDirection) {
		if (leftDirection) {
			velocity = Vector2f(-8, 6);
			texture.loadFromFile("Images/Wave-DownLeft.png");
			position = Vector2f(1000.f, -150.f);
		}
		else if (rightDirection) {
			velocity = Vector2f(8, 6);
			texture.loadFromFile("Images/Wave-DownRight.png");
			position = Vector2f(-200.f, -150.f);
		}
		else {
			velocity = Vector2f(0, 6);
			texture.loadFromFile("Images/Wave-Down.png");
			position = Vector2f(400.f, -32.f);
		}
	}
	else if (leftDirection) {
		velocity = Vector2f(-8, 0);
		texture.loadFromFile("Images/Wave-Left.png");
		position = Vector2f(832.f, 300.f);
	}
	else {
		velocity = Vector2f(8, 0);
		texture.loadFromFile("Images/Wave-Right.png");
		position = Vector2f(-32.f, 300.f);
	}
	sprite.setTexture(texture);
}

void Wave::Flow() {
	position += (NumberOperations::NormalizeVector2f(velocity) * moveSpeed);
	sprite.setPosition(Vector2f(position.x - (texture.getSize().x / 2.f), position.y - (texture.getSize().y / 2.f)));
}
#pragma endregion

#pragma region Update
void Wave::Update() {
	Flow();
}

void Wave::Render(RenderWindow* aWindow) {
	Moveable::Render(aWindow);
}
#pragma endregion