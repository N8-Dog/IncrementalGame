#pragma once
#include "SDL.h"
#include <iostream>
#include "SDL_image.h"
#include <vector>
#include "Classes/Player.h"

class AssetManager;
class TransformComponent;

class ListEntry;

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
	void manageInput();
	bool gameClick(const TransformComponent* recA, const SDL_Event& recB);
	void gameBuyDog(int index);
	void makePannels();
	enum actionType{
		quit,
		buy
	};
	struct eventSlot {
		ListEntry* source;
		int index;
		std::string action;
	};

	
	void addEventSlot(ListEntry* source, int index, actionType action);
	

	static SDL_Renderer *renderer;
	static SDL_Event event;
	static bool isRunning;
	static bool m_menu;
	static SDL_Rect camera;
	static AssetManager* assets;



	enum groupLabels : std::size_t {
		groupMap,
		groupPlayers,
		groupEnemies,
		groupColliders,
		groupProjectiles
	};





	std::vector<eventSlot> slotList;
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


