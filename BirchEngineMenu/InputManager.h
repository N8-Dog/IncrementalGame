/*
#pragma once
class TransformComponant;

enum actionType {
	buy,
	quit
};

class SlotManager {
public:



	struct eventSlot {
		TransformComponent* source;
		int index;
		actionType action;
		eventSlot(TransformComponent* source, int index, actionType action) : source(source), index(index), action(action) {}
	};

	SlotManager() {}
	~SlotManager() {}

	void addSlot(TransformComponent* source, int index, actionType action = buy) {
		slotList.push_back(new eventSlot(source, index, action));
	}

	std::vector<eventSlot*> slotList;
};

class InputManager {
public:
	Game* i_game;
	SlotManager i_manager;
	InputManager(Game* p_game = nullptr) : i_game(p_game) {
		i_manager = SlotManager();
	}

	void linkGame(Game* p_game) {
		i_game = p_game;
	}

	void init()
	{


	}

	void update() {
		if (Game::event.type == SDL_MOUSEBUTTONDOWN) {
			if (Game::event.button.button == SDL_BUTTON_LEFT) {
				for (int i = 0; i < i_manager.slotList.size(); i++) {
					if (Click(i_manager.slotList.at(i)->source, Game::event)) {
						switch (i_manager.slotList.at(i)->action) {
						case buy:
							i_game->m_player.buyDog(i_manager.slotList.at(i)->index);
							break;
						case quit:
							Game::isRunning = false;
							break;
						default:
							break;
						}
					}
				}

			}
		}

	}
	bool Click(const TransformComponent* recA, const SDL_Event& recB) {
		if (
			recA->position.x + recA->width >= recB.button.x &&
			recB.button.x >= recA->position.x &&
			recA->position.y + recA->height >= recB.button.y &&
			recB.button.y >= recA->position.y
			) {
			return true;
		}
		return false;
	}

};
*/