#pragma once

#include "GameObject.h"

class Gravestone : public GameObject {

	private:

		int chargeValue = 1;
		int chargeCap = 10;
		bool isCharged = false;
		bool alreadyCharging;

	public:

		Gravestone();
		Gravestone(sf::Vector2f, sf::Sprite);
		Gravestone(sf::Vector2f, sf::Sprite, int);
		virtual ~Gravestone();
		
		bool IsCharged();
		void Charge();
		void ResetCharge();
		bool AlreadyCharging();
		void EnableCharge();

		void Init();
		void Update();
		void Render(sf::RenderWindow*);
};

