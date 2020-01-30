#pragma once

#include "GameObject.h"

using namespace sf;
// a rather troublesome, stationary object. it serves as a spawn point for enemies
class Gravestone : public GameObject {

	private:

		int chargeValue = 1;
		int chargeCap = 10;
		bool isCharged = false;
		bool alreadyCharging;

	public:

		Gravestone();
		Gravestone(Vector2f, Sprite);
		Gravestone(Vector2f, Sprite, int);
		virtual ~Gravestone();
		
		bool IsCharged();
		void Charge();
		void ResetCharge();
		bool AlreadyCharging();
		void EnableCharge();

		void Init();
		void Render(RenderWindow*);

};

