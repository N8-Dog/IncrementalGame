#include "SDL.h"
#include "Game.h"


Game* game = nullptr;
int main(int argc, char* argv[]) {

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;


	game = new Game("DogMill", 1600, 1000, false);
	//game->menu("BarchEngine", 800, 640, false);
	//while (game->menuRunning()) {

	//	frameStart = SDL_GetTicks();

	//	game->handleEvents();
	//	game->update();
	//	game->render();

	//	frameTime = SDL_GetTicks() - frameStart;

	//	if (frameDelay > frameTime) SDL_Delay(frameDelay - frameTime);
	//}

	game->init();
	while (game->running()) {

		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) SDL_Delay(frameDelay - frameTime);
	}
	game->clean();
	/*while (game is running) {

		handle any user input
			update all objects changes eg. positions, etc.
			render changes
	}*/


	return 0;
}