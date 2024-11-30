#pragma once
#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/UI/UIElement/ButtonView.h"

namespace Gameplay
{
	class GameplayController;

	class GameplayService
	{
	public:
		GameplayService();
		~GameplayService();

		void initialize();
		void update();
		void render();
		void startGame();
		void endGame(GameResult result);

		float getRemainingTime();
		int getMinesCount();

	private:
		GameplayController* gameplay_controller;

		void createController();
		void destroy();
	};
}