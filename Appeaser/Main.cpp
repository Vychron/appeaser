#include "Main.h"
#include "iostream"

#include "Game.h"

int main() {

	Game game;

	//Game update loop
	while (game.running()) {

		//Update
		game.Update();

		//Render
		game.Render();
	}

	return 0;
}
