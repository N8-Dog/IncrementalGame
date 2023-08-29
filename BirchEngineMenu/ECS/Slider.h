//#pragma once
//#include "Components.h"
//
//class SliderBG : public Entity {
//public:
//	SliderBG(Slider* parent, Manager& manager) : parent(parent), Entity::Entity(manager) {
//
//	}
//
//	void init(int x, int y, int w, int h) {
//		addComponent<TransformComponent>(x, y, w, h, 1);
//		addComponent<SpriteComponent>("JAUNE");
//	}
//
//
//	Slider* parent;
//
//};
//
//class SliderButton : public Entity {
//public:
//	SliderButton(Slider* parent, Manager& manager) : parent(parent), Entity::Entity(manager) {
//
//	}
//
//	void init(int x, int y, int w, int h) {
//		addComponent<TransformComponent>(x, y, w, h, 1);
//		addComponent<SpriteComponent>("MAUVE");
//	}
//
//
//	Slider* parent;
//
//};
//
//class Slider {
//public:
//	Slider(GroupBox* parent, bool horizontal) : horizon(horizontal), manager(parent->manager), btn(nullptr), bg(nullptr) {
//		x = parent->x;
//		y = parent->y;
//		if (horizon) {
//			w = parent->w;
//			h = 20;
//		}
//		else {
//			w = 20;
//			h = parent->h;
//		}
//	}
//	~Slider(){}
//
//	void init() {
//		btn = new SliderButton(this, manager);
//		bg = new SliderBG(this, manager);
//		btn->init(x, y, w, 20);
//		bg->init(x, y, 20, 20);
//	}
//
//	void update() {
//		bg->update();
//		btn->update();
//	}
//
//	void draw() {
//		bg->update();
//		btn->update();
//	}
//
//	int x;
//	int y;
//	int w;
//	int h;
//	bool horizon;
//	Manager& manager;
//	SliderButton* btn;
//	SliderBG* bg;
//};
//
