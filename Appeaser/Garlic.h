#pragma once

#include "GameObject.h"

using namespace sf;
// the player's "weapon" to get rid of enemies
class Garlic : public GameObject {

	private:

		bool enabled = false;
		bool isDetonating = false;


	public:

		Garlic();
		Garlic(Vector2f aPosition, Sprite aSprite);
		virtual ~Garlic();

		void Place(Vector2f aPosition);
		bool IsEnabled();
		bool IsDetonating();
		void Detonate();

		void Init();
		void Update();
		void Render(RenderWindow* aWindow);

};

