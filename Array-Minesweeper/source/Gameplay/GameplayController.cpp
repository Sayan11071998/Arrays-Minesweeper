#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Main/GameService.h"
#include "../../header/Gameplay/Board/BoardService.h"

namespace Gameplay
{
	using namespace Global;
	using namespace Board;

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
	}

	void GameplayController::render()
	{
	}

	void GameplayController::reset()
	{
		ServiceLocator::getInstance()->getBoardService()->resetBoard();
	}
}