#pragma once
#include "Components.h"
#include "Game.h"
#include "../Vector2D.h"

class ListEntry : public Entity {
public:


	ListEntry(Manager& _manager, std::string text, int posX, int posY, bool p_isText) : manager(_manager), text(text), x(posX), y(posY), Entity::Entity(manager), m_isText(p_isText), linkTo(nullptr) {

	}

	//~ListEntry() {
	//}

	void init(SDL_Color color, int posX, int posY, std::string text, std::string font) {
		//if (isText) {
		//	SDL_Color white = { 255, 255, 255, 255 };
		//	this->addComponent<UILabel>(posX, posY, text, font, color);
		//}

		//else {
		//	this->addComponent<TransformComponent>(x, y, 32, 32, 1);
		//	this->addComponent<SpriteComponent>(text);
		//	std::cout << "J'AI CHIÉ LOL" << std::endl;
		//}

	}

	int getX() {
		return x;
	}

	int getY() {
		return y;
	}

	std::string getText() {
		return text;
	}

	void asgY(int posY) {
		y = posY;
	}

	void asgX(int posX) {
		x = posX;
	}

	bool isText() {
		return m_isText;
	}

	ListEntry* linkTo;
private:
	int x;
	int y;
	Manager& manager;
	std::string text;
	bool m_isText;
	
};

class ListBG : public Entity {
public:
	ListBG(Manager& _manager) : manager(_manager), Entity::Entity(manager) {

	}
	~ListBG() {

	}

	void init(float x, float y, int h, int w, int sc) {
		addComponent<TransformComponent>(x,y,h,w,sc);
		addComponent<SpriteComponent>("PurpleKush");

	}

	Manager& manager;
	SDL_Texture* texture;

};




class ListBox {
public:
	ListBox(Manager& p_manager, int posX, int posY) : manager(p_manager), x(posX), y(posY), bg(manager) {
		fontID = "vgafix";
		color = { 255, 255, 255, 255 };

	}

	~ListBox() {}

	void addEntry(std::string text, bool isText = true, ListEntry* linkTo =nullptr) {
		content.push_back(new ListEntry(manager, text, x + w + border, y + h + border, isText));
		
	}

	//void addEntry(ListBox* source) {
	//	content.emplace_back(std::move(source));
	//}

	void addButton(std::string text, std::string action) {
		addEntry(text);
		ListEntry* tmp = content.back();
		addEntry("Jaune", false);
		content.back()->linkTo = tmp;
		/*Game::addEventSlot<Dog>(content.back()->getComponent<TransformComponent>().position, target, action);*/
		
	}

	void init() {

		int newHeight = border;
		int newWidth = border;
		int index = 0;
		for (auto elem : content) {
			
				elem->asgY(newHeight + y);
				elem->asgX(border + x);
				if (elem->isText()) {
				elem->addComponent<UILabel>(elem->getX(), elem->getY(), elem->getText(), fontID, color);
				newWidth = std::max(elem->getComponent<UILabel>().getPosition().w + (border * 2), w);
				newHeight += elem->getComponent<UILabel>().getPosition().h + border;
				}
				else {
					if (elem->linkTo == nullptr) {
						elem->addComponent<TransformComponent>(x - 32 + newWidth / 2, elem->getY(), 64, 64, 1);
						elem->addComponent<SpriteComponent>(elem->getText());
						newWidth = std::max(elem->getComponent<TransformComponent>().width + (border * 2), w);
						newHeight += elem->getComponent<TransformComponent>().height + border;
					}
					else {
						elem->addComponent<TransformComponent>(elem->linkTo->getComponent<UILabel>().getPosition());
						elem->addComponent<SpriteComponent>(elem->getText());
						std::cout << "LOLOLOL" << elem->getText() << std::endl;

						std::iter_swap(content.begin() + (index - 1), content.begin() + index);

					}
					 
				}
				h = newHeight;
				w = newWidth;
				index++;
		}
		
		bg.init(static_cast<float>(x), static_cast<float>(y), h, w, sc);
	}

	void update() {
		for (auto elem : content) {
			elem->update();
		}
		bg.update();
		//tag.update();
	}

	void reload() {
		clear();
		init();
	}

	void draw() {
		bg.draw();
		for (auto elem : content) {
			elem->draw();
		}
		
		//tag.draw();
	}

	void updatePosition(int posX, int posY) {
		x = posX;
		y = posY;
	}

	void clear() {

		for (auto elem : content) {
			elem->destroy();
		}
			content.clear();
		
	}


	int x;
	int y;
	int w = 0;
	int h = 0;
	int sc = 1;
	int border = 10;

	std::string fontID;
	Manager& manager;
	ListBG bg;
	SDL_Color color;
	std::vector<ListEntry*> content;

};

