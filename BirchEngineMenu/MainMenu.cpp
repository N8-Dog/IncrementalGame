//#include "MainMenu.h"
//
//MainMenu::MainMenu(const Game* game) {
//
//}
//MainMenu::~MainMenu() {
//
//}
//
//MainMenu::init() {
//	int flags = 0;
//	if (fullscreen == true) {
//		flags = SDL_WINDOW_FULLSCREEN;
//	}
//
//
//	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
//		std::cout << "Subsystems initialized..." << std::endl;
//
//		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
//
//		if (window) {
//			std::cout << "Window Created !" << std::endl;
//		}
//
//		renderer = SDL_CreateRenderer(window, -1, 0);
//		if (renderer) {
//			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//			std::cout << "Renderer created!" << std::endl;
//		}
//
//		isRunning = true;
//	}
//	else {
//		isRunning = false;
//	}
//	if (TTF_Init() == -1) {
//		std::cout << "Error : SDL_TTF" << std::endl;
//	}
//}
//
//void MainMenu::gameStart() {
//	const int FPS = 60;
//	const int frameDelay = 1000 / FPS;
//
//	Uint32 frameStart;
//	int frameTime;
//
//	game->init("BarchEngine", 800, 640, false);
//	while (game->running()) {
//
//		frameStart = SDL_GetTicks();
//
//		game->handleEvents();
//		game->update();
//		game->render();
//
//		frameTime = SDL_GetTicks() - frameStart;
//
//		if (frameDelay > frameTime) SDL_Delay(frameDelay - frameTime);
//	}
//	game->clean();
//}