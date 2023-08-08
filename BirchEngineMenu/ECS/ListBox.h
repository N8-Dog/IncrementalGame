#pragma once
#include "Components.h"
#include "../Vector2D.h"

class ListEntry : public Entity {
public:


	ListEntry(Manager& _manager, std::string text, int posX, int posY, bool p_isText) : manager(_manager), text(text), x(posX), y(posY), Entity::Entity(manager), m_isText(p_isText) {

	}

	~ListEntry() {
	}

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

	void addEntry(std::string text, bool isText = true) {
		content.push_back(new ListEntry(manager, text, x + w + border, y + h + border, isText));
		
	}

	void init() {

		int newHeight = border;
		int newWidth = border;
		for (auto elem : content) {
			
				elem->asgY(newHeight + y);
				elem->asgX(border + x);
				if (elem->isText()) {
				elem->addComponent<UILabel>(elem->getX(), elem->getY(), elem->getText(), fontID, color);
				newWidth = std::max(elem->getComponent<UILabel>().getPosition().w + (border * 2), w);
				newHeight += elem->getComponent<UILabel>().getPosition().h + border;
				}
				else {
					elem->addComponent<TransformComponent>(x - 32 + newWidth/2, elem->getY(), 64,64,1);
					elem->addComponent<SpriteComponent>(elem->getText());
					newWidth = std::max(elem->getComponent<TransformComponent>().width + (border * 2), w);
					newHeight += elem->getComponent<TransformComponent>().height + border;
				}
				h = newHeight;
				w = newWidth;
			

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

