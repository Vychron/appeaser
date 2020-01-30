#pragma once

#include "Moveable.h"

using namespace sf;

class Player : public Moveable {
		
	private:

		void UpdateVelocity();
	
		bool upDirection = false;
		bool downDirection = false;
		bool leftDirection = false;
		bool rightDirection = false;

	public:
	
		Player();
		Player(Vector2f aPosition, Sprite aSprite);
		virtual ~Player();
	
		void SetUpDirection(bool active);
		void SetDownDirection(bool active);
		void SetLeftDirection(bool active);
		void SetRightDirection(bool active);

		void Init();
		void Update();
		void Render(RenderWindow* aWindow);

};

