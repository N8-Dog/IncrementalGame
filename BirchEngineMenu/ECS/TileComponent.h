//#pragma once
//
//
//#include "ECS.h"
//#include "TransformComponent.h"
//#include "SpriteComponent.h"
//#include "SDL.h"
//
//
//class TileComponent :public Component
//
//{
//public:
//
//	SDL_Texture* texture;
//	SDL_Rect srcRect, destRect;
//	Vector2D position;
//
//
//	TileComponent() = default;
//	~TileComponent()
//	{
//		SDL_DestroyTexture(texture);
//	}
//
//	TileComponent(int srcX, int srcY, int xpos, int ypos, int tsize, int tscale, std::string id) {
//		texture = Game::assets->GetTexture(id);
//
//		srcRect.x = srcX;
//		srcRect.y = srcY;
//
//		srcRect.w = srcRect.h = tsize;
//
//		position.x = static_cast<float>(xpos);
//		position.y = static_cast<float>(ypos);
//		
//		destRect.w = destRect.h = tsize * tscale;;
//	}
//
//
//	void draw() override {
//		TextureManager::Draw(texture, srcRect, destRect, SDL_FLIP_NONE);
//	}
//
//	void update() override {
//		destRect.x = position.x - static_cast<float>(Game::camera.x);
//		destRect.y = position.y - static_cast<float>(Game::camera.y);
//	}
//
//};
//
