#pragma once

#include "GameObject.h"

class Gravestone : public GameObject {

	private:

		int chargeValue = 1;
		int chargeCap = 10;

	public:

		Gravestone();
		Gravestone(sf::Vector2f aPosition, sf::RectangleShape aSprite);
		Gravestone(sf::Vector2f aPosition, sf::RectangleShape aSprite, int aChargeValue);
		virtual ~Gravestone();
		
		void Charge();

		void Init();
		void Update();
		void Render(sf::RenderWindow* aWindow);

	protected:

};

