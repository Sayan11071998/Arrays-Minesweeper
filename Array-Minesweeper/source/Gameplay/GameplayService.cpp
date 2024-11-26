#include "../../header/Gameplay/GameplayService.h"
#include "../../header/Gameplay/GameplayController.h"

namespace Gameplay
{
	GameplayService::GameplayService()
	{
		gameplay_controller = nullptr;
		createController();
	}

	GameplayService::~GameplayService()
	{
		destroy();
	}

	void GameplayService::createController()
	{
		gameplay_controller = new GameplayController();
	}

	void GameplayService::initialize()
	{
		gameplay_controller->initialize();
	}

	void GameplayService::update()
	{
		gameplay_controller->update();
	}

	void GameplayService::render()
	{
		gameplay_controller->render();
	}

	void GameplayService::startGame()
	{
		gameplay_controller->reset();
	}

	float GameplayService::getRemainingTime()
	{
		return gameplay_controller->getRemainingTime();
	}

	int GameplayService::getMinesCount()
	{
		return gameplay_controller->getMinesCount();
	}

	void GameplayService::destroy()
	{
		delete(gameplay_controller);
	}
}