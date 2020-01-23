#pragma once

#include "Moveable.h"

class Wave : public Moveable {
	
	private:

		bool upDirection = false;
		bool downDirection = false;
		bool leftDirection = false;
		bool rightDirection = false;

	public:

		Wave();
		Wave(sf::Vector2f aPosition, sf::Sprite  aSprite);
		virtual ~Wave();

		void SetRandomDirecion();
		void SetSpriteAndPosition();
		void Flow();

		void Init();
		void Update();
		void Render(sf::RenderWindow* aWindow);

};

