#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Gameplay/Board/BoardService.h"
#include "../../header/Time/TimeService.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Main/GameService.h"

namespace Gameplay
{
	using namespace Global;
	using namespace Board;
	using namespace Time;
	using namespace Main;
	using namespace Cell;
	using namespace UI::UIElement;

	GameplayController::GameplayController()
	{
	}

	GameplayController::~GameplayController()
	{
	}

	void GameplayController::initialize()
	{
	}

	void GameplayController::update()
	{
		updateRemainingTime();
		if (isTimeOver())
			endGame(GameResult::LOST);
	}

	void GameplayController::render()
	{
	}

	void GameplayController::reset()
	{
		ServiceLocator::getInstance()->getBoardService()->resetBoard();
		remaining_time = max_duration;
	}

	float GameplayController::getRemainingTime()
	{
		return remaining_time;
	}

	int GameplayController::getMinesCount()
	{
		return ServiceLocator::getInstance()->getBoardService()->getMinesCount();
	}

	void GameplayController::endGame(GameResult result)
	{
		switch (result)
		{
		case GameResult::WON:
			gameWon();
			break;
		case GameResult::LOST:
			gameLost();
			break;
		default:
			break;
		}
	}

	void GameplayController::updateRemainingTime()
	{
		remaining_time -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}

	void GameplayController::gameWon()
	{
		game_result = GameResult::WON;
		board_service->flagAllMines();
		board_service->setBoardState(BoardState::COMPLETED);
		ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::GAME_WON);
	}

	void GameplayController::gameLost()
	{
		if (game_result == GameResult::NONE)
		{
			game_result = GameResult::LOST;
			beginGameOverTimer();
			board_service->showBoard();
			board_service->setBoardState(BoardState::COMPLETED);
		}
		else
		{
			showCredits();
		}
	}

	void GameplayController::beginGameOverTimer()
	{
		remaining_time = game_over_time;
	}

	void GameplayController::showCredits()
	{
		GameService::setGameState(GameState::CREDITS);
	}

	bool GameplayController::isTimeOver()
	{
		return (remaining_time <= 1);
	}
}