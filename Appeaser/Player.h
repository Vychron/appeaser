#pragma once

#include "Moveable.h"

class Player : public Moveable {

		
	private:

		void UpdateVelocity();
	
		bool upDirection = false;
		bool downDirection = false;
		bool leftDirection = false;
		bool rightDirection = false;

	public:
	
		Player();
		Player(sf::Vector2f aPosition, sf::RectangleShape aSprite);
		virtual ~Player();
	
		void SetUpDirection(bool active);
		void SetDownDirection(bool active);
		void SetLeftDirection(bool active);
		void SetRightDirection(bool active);

		void Init();
		void Update();
		void Render(sf::RenderWindow* aWindow);
};

