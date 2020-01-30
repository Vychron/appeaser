#include "Game.h"

int main() {

	Game game;

	// game update loop, keeping the main file clean
	while (game.running()) {

		game.Update();
		game.Render();
	}

	return 0;
}
