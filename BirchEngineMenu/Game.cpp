#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "ECS/Components.h"
#include "Vector2D.h"
#include "Collision.h"
#include "AssetManager.h"
#include <sstream>

Map* map;
Manager manager;


SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
SDL_Rect Game::startMenu;

SDL_Rect Game::camera = { 0,0,800,640 };

AssetManager* Game::assets = new AssetManager(&manager);

auto& player(manager.addEntity());
auto& boutonStart(manager.addEntity());

bool Game::isRunning = false;
bool Game::m_menu = true;

auto& label(manager.addEntity());
auto& label2(manager.addEntity());
auto& label3(manager.addEntity());
auto& mainTitle(manager.addEntity());
auto& mainTitlebg(manager.addEntity());


Button boutonMarde(manager, 10, 30, "1$ /sec.");


GroupBox liste(manager, 10, 400 );

GroupBox listeOwned(manager, 10, 700);



Game::Game(const char* p_title, int p_width, int p_height, bool fsc) : title(p_title), width(p_width), height(p_height), fullscreen(fsc){
	Player Elmer;
	m_player = Elmer;
	

		
		
	
	
}
Game::~Game() {

}

void Game::init() {
	int flags = 0;
	if (fullscreen == true) {
		flags = SDL_WINDOW_FULLSCREEN;
	}


	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems initialized..." << std::endl;

		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);

		if (window) {
			std::cout << "Window Created !" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 0,0,0,0);
			std::cout << "Renderer created!" << std::endl;
		}

		isRunning = true;
	}
	else {
		isRunning = false;
	}
	if (TTF_Init() == -1) {
		std::cout << "Error : SDL_TTF" << std::endl;
	}
	assets->AddFont("vgafix", "assets/vgafix.fon", 16);

	
	assets->AddTexture("terrain", "assets/terrain_ss.png");
	assets->AddTexture("Carl", "assets/Carl.png");
	assets->AddTexture("player", "assets/player_anims.png");
	assets->AddTexture("Noir", "assets/MAUVE.png");
	assets->AddTexture("PurpleKush", "assets/MAUVE.png");
	//assets->AddTexture("projectile", "assets/proj.png");
	assets->AddTexture("King Dude", "assets/King Dude.png");
	assets->AddTexture("Jaune", "assets/JAUNE.png");
	map = new Map("terrain", 3, 32);

	map->LoadMap("assets/map.map", 25, 20);

	/*bouton1 = new Button(posX(0.5), posY(0.75), "assets/MAUVE.png", "Je m'en vais chier par la fenetre");
	*/
	player.addComponent<TransformComponent>(800.0f, 750.0f, 32, 32, 4);
	player.addComponent<SpriteComponent>("player", true);
	player.addComponent<KeyboardController>();
	player.addComponent<ColliderComponent>("player");
	player.addGroup(groupPlayers);
	SDL_Color white = { 255, 255, 255, 255 };
	SDL_Color black = { 0,0,0,0 };
	label.addComponent<UILabel>(10, 10, "Test string", "vgafix", white);
	label2.addComponent<UILabel>(550, 10, "Quit", "vgafix", white);
	startMenu = label2.getComponent<UILabel>().getPosition();
	label3.addComponent<TransformComponent>(startMenu);

	mainTitle.addComponent<UILabel>(posX(50), posY(0.2), "THE EXTRAORDINARY DOG FACTORY", "vgafix", white);
	
	mainTitle.getComponent<UILabel>().move((posX(0.5) - (mainTitle.getComponent<UILabel>().getPosition().w / 2)), posY(0.2));

	
	SDL_Rect pt = mainTitle.getComponent<UILabel>().getPosition();

	mainTitlebg.addComponent<TransformComponent>(pt);
	mainTitlebg.addComponent<SpriteComponent>("Noir");

	label3.addComponent<SpriteComponent>("Noir");

	
	//bgamarde.addComponent<TransformComponent>(10,30,50,50,1);
	//bgamarde.addComponent<SpriteComponent>("Noir");

	//bouton1.init(white, 10, 30, "La vie c'est comme une beurrée de marde", "vgafix");
	//bouton11.init();
	makePannels();

	
	boutonMarde.init();
}

auto& tiles(manager.getGroup(Game::groupMap));
auto& players(manager.getGroup(Game::groupPlayers));
//auto& enemies(manager.getGroup(Game::groupEnemies));
auto& colliders(manager.getGroup(Game::groupColliders));
auto& projectiles(manager.getGroup(Game::groupProjectiles));


void Game::handleEvents() {
	

	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;

		default:
			break;
		}
	
}

void Game::update() {

	
		SDL_Rect playerCol = player.getComponent<ColliderComponent>().collider;
		Vector2D playerPos = player.getComponent<TransformComponent>().position;

		if(cnt++ == 20 )
		{
			int playerMoney = m_player.time();

			std::stringstream ss;

			ss << "Money: " << playerMoney << " $";

			label.getComponent<UILabel>().SetLabelText(ss.str(), "vgafix");
			cnt = 0;
		}

		manageInput();

		manager.refresh();
		manager.update();
		boutonMarde.update();

		liste.update();
		listeOwned.update();
}



void Game::render() {
	
	SDL_RenderClear(renderer);
	////this is where we would add stuff to render  
	////map->DrawMap();
	//for (auto& t : tiles) {
	//	t->draw();
	//}
	//for (auto& p : players) {
	//	p->draw();
	//}
	////for (auto& c : colliders) {
	////	c->draw();
	////}
	////for (auto& e : enemies) {
	////	e->draw();
	////}
	//for (auto& p : projectiles) {
	//	p->draw();
	//}

	label.draw();
	label3.draw();
	label2.draw();
	mainTitlebg.draw();
	mainTitle.draw();

	//bouton11.draw();
	//bouton1.draw();
	boutonMarde.draw();

	liste.draw();
	listeOwned.draw();
	SDL_RenderPresent(renderer);
}
void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}
bool Game::running() {
	return isRunning;
}

bool Game::menuRunning()
{
	return m_menu;
}

void Game::menu(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen == true) {
		flags = SDL_WINDOW_FULLSCREEN;
	}


	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems initialized..." << std::endl;

		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);

		if (window) {
			std::cout << "Window Created !" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}

		isRunning = true;
	}
	else {
		isRunning = false;
	}
	if (TTF_Init() == -1) {
		std::cout << "Error : SDL_TTF" << std::endl;
	}

	assets->AddFont("vgafix", "assets/vgafix.fon", 16);
	SDL_Color white = { 255, 255, 255, 255 };
	boutonStart.addComponent<UILabel>(400, 320, "Start", "vgafix", white);
	boutonStart.getComponent<UILabel>().SetLabelText("Start", "vgafix");
	startMenu = boutonStart.getComponent<UILabel>().getPosition();
}

float Game::posX(float coefficient)
{
	if (coefficient < 1) return width * coefficient;
	else return width * (coefficient / 100);
	
}

float Game::posY(float coefficient)
{
	if (coefficient < 1) return height * coefficient;
	else return height * (coefficient / 100);
}

bool Game::gameClick(const ListEntry* recA, const SDL_Event& recB) {
	if (
		recA->getComponent<TransformComponent>().position.x + recA->getComponent<TransformComponent>().width >= recB.button.x &&
		recB.button.x >= recA->getComponent<TransformComponent>().position.x &&
		recA->getComponent<TransformComponent>().position.y + recA->getComponent<TransformComponent>().height >= recB.button.y &&
		recB.button.y >= recA->getComponent<TransformComponent>().position.y) {
		return true;
	}
	return false;
}

void Game::gameBuyDog(int index)
{
	m_player.buyDog(index);
	listeOwned.move(liste, index);
	liste.updateContentPosition();
	listeOwned.updateContentPosition();
	std::cout << "available list : ";
	std::cout << "size : " << liste.content.size();
	for (auto elem : liste.content) {
		std::cout << elem->content.at(0)->getText() << ", ";
	}
	std::cout << std::endl;
	std::cout << "owned list : ";
	for (auto elem : listeOwned.content) {
		std::cout << elem->content.at(0)->getText() << ", ";
	}
	std::cout << std::endl;
}

void Game::manageInput()
{
	if (Game::event.type == SDL_MOUSEBUTTONDOWN) {
		if (Game::event.button.button == SDL_BUTTON_LEFT) {
			/*if (gameClick(Game::startMenu, Game::event)) Game::isRunning = false;*/
			for (int i = 0; i < slotList.size(); i++) {
				if (gameClick(slotList.at(i).source, Game::event)) gameBuyDog(i);
			}
		}
	}
}


void Game::addEventSlot(ListEntry* source, int index, actionType action) {
	slotList.emplace_back(eventSlot());
	eventSlot* brandNew = &slotList.back();
	brandNew->action = action;
	brandNew->index = index;
	brandNew->source = source;
	/*std::cout << "ajout " << m_player.availDog.at(index).getName() << " a la position (" << source->getComponent<TransformComponent>().position.x << ", " << source->getComponent<TransformComponent>().position.y << std::endl;*/
}

void Game::makePannels() {
	for (int i = 0; i < m_player.availDog.size(); i++) {
		ListBox* addon = liste.addList();
		std::string path = "assets/" + m_player.availDog.at(i).getName() + ".png";
		assets->AddTexture(m_player.availDog.at(i).getName(), path.c_str());
		addon->addEntry("Name : " + m_player.availDog.at(i).getName());
		addon->addEntry("Breed : " + m_player.availDog.at(i).getRace());
		addon->addEntry("Price : " + std::to_string(m_player.availDog.at(i).getPrice()));
		addon->addEntry("Pay : " + std::to_string(m_player.availDog.at(i).getInc()) + "$/Sec");
		addon->addEntry(m_player.availDog.at(i).getName(), false);
		addon->addButton("Buy", "buy");
		ListEntry* btn = addon->content.back();
		addEventSlot(btn, i, buy);
	}

	liste.init();

	for (int i = 0; i < m_player.ownedDog.size(); i++) {
		ListBox* addon = listeOwned.addList();
		std::string path = "assets/" + m_player.ownedDog.at(i).getName() + ".png";
		assets->AddTexture(m_player.ownedDog.at(i).getName(), path.c_str());
		addon->addEntry("Name : " + m_player.ownedDog.at(i).getName());
		addon->addEntry("Breed : " + m_player.ownedDog.at(i).getRace());
		addon->addEntry("Pay : " + std::to_string(m_player.ownedDog.at(i).getInc()));
		//std::string name = m_player.availDog.at(i).getName();
		//std::string path = "assets/" + name + ".png";
		//assets->AddTexture(m_player.availDog.at(i).getName(), path.c_str() );
		//addon->addEntry(name, false);

		addon->addEntry(m_player.ownedDog.at(i).getName(), false);

	}
	listeOwned.init();
}


