#pragma once
#include "../Game.h"
#include "ECS.h"
#include "Components.h"

class KeyboardController : public Component {
public:
	TransformComponent* transform;
	SpriteComponent* sprite;
	//std::vector<Button*> buttonsEffects;

	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();
		sprite = &entity->getComponent<SpriteComponent>();
	}

	void update() override {
		if (Game::event.type == SDL_KEYDOWN) {
			switch (Game::event.key.keysym.sym) {
			case SDLK_w:
				transform->velocity.y = -1;
				sprite->Play("Walk");
				break;
			case SDLK_a:
				transform->velocity.x = -1;
				sprite->Play("Walk");
				sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
				break;
			case SDLK_s:
				transform->velocity.y = 1;
				sprite->Play("Walk");
				break;
			case SDLK_d:
				transform->velocity.x = 1;
				sprite->Play("Walk");
				break;

			default:
				break;
			}
		}

		if (Game::event.type == SDL_KEYUP) {
			
				switch (Game::event.key.keysym.sym) {
				case SDLK_w:
					transform->velocity.y = 0;
					sprite->Play("Idle");
					break;
				case SDLK_a:
					transform->velocity.x = 0;
					sprite->Play("Idle");
					sprite->spriteFlip = SDL_FLIP_NONE;
					break;
				case SDLK_s:
					transform->velocity.y = 0;
					sprite->Play("Idle");
					break;
				case SDLK_d:
					transform->velocity.x = 0;
					sprite->Play("Idle");
					break;
				case SDLK_ESCAPE:
					Game::isRunning = false;
					break;

				default:
					break;
				}
			
		}

		if (Game::event.type == SDL_MOUSEBUTTONDOWN) {
			if (Game::event.button.button == SDL_BUTTON_LEFT) {
				if(Click(Game::startMenu, Game::event)) Game::isRunning = false;
			}
		}

	}
	bool Click(const SDL_Rect& recA, const SDL_Event& recB) {
		if (
			recA.x + recA.w >= recB.button.x &&
			recB.button.x >= recA.x &&
			recA.y + recA.h >= recB.button.y &&
			recB.button.y >= recA.y
			) {
			return true;
		}
		return false;
	}

	//void addButton(TransformComponent&) {
	//	SDL_Rect newRect;
	//	newRect.x = TransformComponent().position.x;
	//	newRect.y = TransformComponent().position.y;
	//	newRect.w = TransformComponent().width;
	//	newRect.h = TransformComponent().height;
	//	buttons.push_back(newRect);
	//	buttonsSource.push_back()
	//}

	//bool Click(const Entity* recA, const SDL_Event& recB) {
	//	if (
	//		recA.x + recA.w >= recB.button.x &&
	//		recB.button.x >= recA.x &&
	//		recA.y + recA.h >= recB.button.y &&
	//		recB.button.y >= recA.y
	//		) {
	//		return true;
	//	}
	//	return false;
	//}

};