#pragma once

#include "ECS.h"
#include "../AssetManager.h"
#include "../Game.h"
#include "../TextureManager.h"
#include <SDL.h>

#include <string>

class UIButton : public Component
{
public:
	UIButton(std::string id, int xpos, int ypos)
	{
		setTex(id);
		position.x = xpos;
		position.y = ypos;
	}
	~UIButton()
	{}

	//void SetButtonText(std::string text, std::string font)
	//{
	//	SDL_Surface* surf = TTF_RenderText_Blended(Game::assets->GetFont(font), text.c_str(), textColour);
	//	texture = SDL_CreateTextureFromSurface(Game::renderer, surf);
	//	SDL_FreeSurface(surf);

	//	SDL_QueryTexture(texture, nullptr, nullptr, &position.w, &position.h);
	//}

	void draw() override
	{
		SDL_RenderCopy(Game::renderer, texture, nullptr, &position);
	}

	SDL_Rect getPosition() {
		return position;
	}

	SDL_Rect* getPositionPtr() {
		ptrpos = &position;
		return ptrpos;
	}

	void setTex(std::string id) {
		texture = Game::assets->GetTexture(id);
	}
	void init() override {
		




	}

private:
	SDL_Rect position;
	SDL_Rect* ptrpos;
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;
};