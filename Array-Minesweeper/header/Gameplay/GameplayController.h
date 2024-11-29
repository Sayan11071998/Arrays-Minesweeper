#pragma once
#include "../../header/Gameplay/Board/BoardService.h"
#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/UI/UIElement/ButtonView.h"
#include <SFML/Graphics.hpp>

namespace Gameplay
{
	using namespace Gameplay::Board;

	enum class GameResult
	{
		NONE,
		WON,
		LOST
	};

	class GameplayController
	{
	public:
		GameplayController();
		~GameplayController();

		void initialize();
		void update();
		void render();
		void reset();
		
		float getRemainingTime();
		int getMinesCount();

		void endGame(GameResult result);

	private:
		const float max_duration = 301.f;
		float remaining_time;
		const float game_over_time = 11.f;
		GameResult game_result;
		BoardService* board_service;

		void updateRemainingTime();
		void gameWon();
		void gameLost();
		void beginGameOverTimer();
		void showCredits();
	};
}