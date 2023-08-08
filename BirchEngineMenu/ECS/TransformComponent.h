#pragma once
#include "Components.h"
#include "../Vector2D.h"

class TransformComponent : public Component
{
public:
	Vector2D position;
	Vector2D velocity;

	int height = 32;
	int width = 32;
	int scale = 1;

	int speed = 3;

	bool blocked = false;

	TransformComponent()
	{
		position.Zero();
	}

	TransformComponent(int sc)
	{
		position.x = 400;
		position.y = 320;
		scale = sc;
	}

	TransformComponent(float x, float y)
	{
		position.Zero();
	}

	TransformComponent(float x, float y, int h, int w, int sc)
	{
		position.x = x;
		position.y = y;
		height = h;
		width = w;
		scale = sc;
		
	}
	TransformComponent(int x, int y, int h, int w, int sc)
	{
		position.x = static_cast<float>(x);
		position.y = static_cast<float>(y);
		height = h;
		width = w;
		scale = sc;

	}

	TransformComponent(SDL_Rect labPos)
	{
		position.x = labPos.x - 5.0f;
		position.y = labPos.y - 5.0f;
		height = labPos.h +10;
		width = labPos.w + 10;
		scale = 1;
	}

	void init() override
	{
		velocity.Zero();
	}
	void update() override
	{
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}


};