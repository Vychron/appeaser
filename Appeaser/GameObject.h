#pragma once

#include <SFML/Graphics.hpp>
#include "iostream"
#include "Collision.h"

using namespace sf;
// the base game object every instance in the game derives from
class GameObject {

	public:

		GameObject();
		GameObject(Vector2f aPosition, Sprite aSprite);
		virtual ~GameObject();

		Vector2f GetPosition();
		Sprite GetSprite();

		void Render(RenderWindow* aWindow);
		
	protected:

		Vector2f position;
		Sprite sprite;
		Texture texture;

};

