#pragma once
#include "Components.h"
#include "../Vector2D.h"

class ButtonText : public Entity {
public:


	ButtonText(Manager& _manager) : manager(_manager), Entity::Entity(manager) {

	}

	~ButtonText() {
	}

	void init(SDL_Color color, int posX, int posY, std::string text, std::string font) {
		SDL_Color white = { 255, 255, 255, 255 };
		this->addComponent<UILabel>(posX, posY, text, font, color);
	}



private:
	int x;
	int y;
	Manager& manager;

};

class ButtonBG : public Entity {
public:
	ButtonBG(Manager& _manager) : manager(_manager), Entity::Entity(manager) {

	}
	~ButtonBG() {

	}

	void init(SDL_Rect position/*, std::string background*/) {
		addComponent<TransformComponent>(position);
		addComponent<SpriteComponent>("PurpleKush");

	}

	Manager& manager;
	SDL_Texture* texture;

};

class Button {
public:
	Button(Manager& p_manager,int posX, int posY, std::string text) : Bmanager(p_manager), x(posX), y(posY), text(text), bg(Bmanager), tag(Bmanager) {
		fontID = "vgafix";
		color = { 255, 255, 255, 255 };

	}

	~Button(){}

	void init() {
		tag.init(color, x, y, text, fontID);
		bg.init(tag.getComponent<UILabel>().getPosition());
	
	}

	void update() {
		bg.update();
		tag.update();
	}

	void draw() {
		bg.draw();
		tag.draw();
	}


	int x;
	int y;
	std::string text;
	std::string fontID;
	Manager& Bmanager;
	ButtonText tag;
	ButtonBG bg;
	SDL_Color color;
	
	
};

