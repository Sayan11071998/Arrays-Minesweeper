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

		float getRemainingTime();

	private:
		GameplayController* gameplay_controller;

		void destroy();
	};
}