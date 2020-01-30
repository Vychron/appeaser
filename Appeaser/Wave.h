#pragma once

#include "Moveable.h"

using namespace sf;
// The main obstacle in this game, causes enemies to spawn and interrupts progression
class Wave : public Moveable {
	
	private:

		bool upDirection = false;
		bool downDirection = false;
		bool leftDirection = false;
		bool rightDirection = false;

	public:

		Wave();
		Wave(Vector2f aPosition, Sprite  aSprite);
		virtual ~Wave();

		void SetRandomDirecion();
		void SetSpriteAndPosition();
		void Flow();

		void Init();
		void Update();
		void Render(RenderWindow* aWindow);

};

