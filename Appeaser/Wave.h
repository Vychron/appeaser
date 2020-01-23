#pragma once

#include "Moveable.h"

class Wave : public Moveable {

	private:

	public:

		Wave();
		Wave(sf::Vector2f aPosition, sf::Sprite  aSprite);
		virtual ~Wave();

		void Init();
		void Update();
		void Render(sf::RenderWindow* aWindow);

	protected:
		
};

