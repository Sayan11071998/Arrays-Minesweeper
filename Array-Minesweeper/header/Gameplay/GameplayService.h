#pragma once

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

	private:
		GameplayController* gameplay_controller;

		void destroy();
	};
}