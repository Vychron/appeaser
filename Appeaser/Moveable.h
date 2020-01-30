#pragma once

#include "GameObject.h"
#include "NumberOperations.h"

using namespace sf;

class Moveable : public GameObject {

	public:

		Moveable();
		Moveable(Vector2f aPosition, Sprite aSprite);
		virtual ~Moveable();

		void ResetPos();

		void Update();
		void Render(RenderWindow* aWindow);

	protected:
		
		float moveSpeed = 0;
		Vector2f velocity;
		Vector2f prevPos;
		virtual void Move();

};

