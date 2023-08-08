#pragma once
#include "SDL.h"
#include <iostream>
#include "SDL_image.h"
#include <vector>
#include "Classes/Player.h"

class AssetManager;

class ColliderComponent;

class Game
{

public:
	Game(const char* p_title, int p_width, int p_height, bool fsc);
	~Game();

	void init();
	void handleEvents();

	void update();
	void render();
	void clean();
	bool running();
	bool menuRunning();
	void menu(const char* title, int width, int height, bool fullscreen);
	static void stopMenu() { m_menu = false; }
	float posX(float coefficient);
	float posY(float coefficient);

	

	static SDL_Renderer *renderer;
	static SDL_Event event;
	static bool isRunning;
	static bool m_menu;
	static SDL_Rect camera;
	static AssetManager* assets;
	static SDL_Rect startMenu;


	enum groupLabels : std::size_t {
		groupMap,
		groupPlayers,
		groupEnemies,
		groupColliders,
		groupProjectiles
	};
private:
	
	SDL_Window* window;
	//SDL_Renderer* renderer;
	int cnt = 0;
	const char* title; 
	int width;
	int height;
	bool fullscreen;
	Player m_player;
	//Manager* manager;
	/*Button* bouton;*/

};


