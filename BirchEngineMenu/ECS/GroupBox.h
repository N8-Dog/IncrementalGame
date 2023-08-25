#pragma once
#include "Components.h"
#include "../Vector2D.h"

class GroupBox {
public:
	GroupBox(Manager& p_manager, int posX, int posY) : manager(p_manager), x(posX), y(posY)/*, bg(manager)*/ {
		fontID = "vgafix";
		color = { 255, 255, 255, 255 };

	}

	~GroupBox() {

		
	}

	ListBox* addList() {
		content.push_back(new ListBox(manager, x, y));
		return content.back();
	}

	void init() {

		int newHeight = border;
		int newWidth = border;
		for (auto elem : content) {
			elem->updatePosition(newWidth + x, y);
			std::cout << "update position ok" << std::endl;
			elem->init();
			std::cout << "elem init ok" << std::endl;
			newHeight = std::max(elem->h + (border * 2), h);
			//if (newWidth > w) {
			//	w = newWidth;
			//	std::cout << "old width : " << w << ", new width : " << newWidth << "(" << elem->getText() << ")" << std::endl;
			//}
			newWidth += elem->w + border;
			h = newHeight;
			w = newWidth;
		}

		//bg.init(static_cast<float>(x), static_cast<float>(y), h, w, sc);
	}

	void update() {
		for (auto elem : content) {

			elem->update();
		}

	}

	void updateContentPosition() {
		int newHeight = border;
		int newWidth = border;
		for (auto elem : content) {
			elem->updateContentPosition(newWidth + x, y);
			newHeight = std::max(elem->h + (border * 2), h);
			newWidth += elem->w + border;
			h = newHeight;
			w = newWidth;
		}
	}


	void draw() {
		//bg.draw();
		for (auto elem : content) {
			elem->draw();
		}

		//tag.draw();
	}

	void clear() {
<<<<<<< HEAD
		std::cout << "clear groupe taille : " << content.size() << std::endl;
		int i = content.size() - 1;
		while(!content.empty()){
			content.at(i)->clear();
			delete content.at(i);
			content.pop_back();
			i--;
=======


		for (auto elem: content){
			delete elem;
>>>>>>> refs/remotes/origin/main
		}

	}
	void reload() {
		clear();
		init();
	}

	void move(GroupBox& p_source, int index) {
		content.push_back(std::move(p_source.content.at(index)));
		p_source.content.erase(p_source.content.begin() + index);
	}


	int x;
	int y;
	int w = 0;
	int h = 0;
	int sc = 1;
	int border = 10;

	std::string fontID;
	Manager& manager;
	//ListBG bg;
	SDL_Color color;
	std::vector<ListBox*> content;


};

