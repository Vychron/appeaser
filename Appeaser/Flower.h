#pragma once

#include "GameObject.h"

using namespace sf;
// the most important item the player can use, it's the only thing that can make the player progress
class Flower : public GameObject {

	private:

		bool enabled = false;
		bool alreadyReduced = false;
		int durability = 0;

	public:

		Flower();
		Flower(Vector2f aPosition, Sprite aSprite);
		virtual ~Flower();

		void Respawn(Vector2f aPosition);
		void ReduceDurability();
		int GetDurability();
		bool IsEnabled();
		void Enable();
		void Disable();
		bool AlreadyReduced();
		void EnableDurability();

		void Init();
		void Render(RenderWindow* aWindow);

};

