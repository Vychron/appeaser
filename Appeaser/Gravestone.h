#pragma once

#include "GameObject.h"

class Gravestone : public GameObject {

	private:

		int chargeValue = 1;
		int chargeCap = 10;
		bool isCharged = false;

	public:

		Gravestone();
		Gravestone(sf::Vector2f aPosition, sf::Sprite aSprite);
		Gravestone(sf::Vector2f aPosition, sf::Sprite aSprite, int aChargeValue);
		virtual ~Gravestone();
		
		bool IsCharged();
		void Charge();
		void ResetCharge();

		void Init();
		void Update();
		void Render(sf::RenderWindow* aWindow);
};

