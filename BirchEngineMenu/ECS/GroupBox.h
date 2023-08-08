#pragma once
#include "Components.h"
#include "../Vector2D.h"

class GroupBox {
public:
	GroupBox(Manager& p_manager, int posX, int posY) : manager(p_manager), x(posX), y(posY)/*, bg(manager)*/ {
		fontID = "vgafix";
		color = { 255, 255, 255, 255 };

	}

	~GroupBox() {}

	ListBox* addList() {
		content.push_back(new ListBox(manager, x, y));
		return content.back();
	}

	void init() {

		int newHeight = border;
		int newWidth = border;
		for (auto elem : content) {
			elem->updatePosition(newWidth + x, y);
			elem->init();
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
		//bg.update();
		//tag.update();
	}


	void draw() {
		//bg.draw();
		for (auto elem : content) {
			elem->draw();
		}

		//tag.draw();
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

