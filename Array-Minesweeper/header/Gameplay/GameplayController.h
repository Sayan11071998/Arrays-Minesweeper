#pragma once

namespace Gameplay
{
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

	private:
		const float max_duration = 301.f;
		float remaining_time;

		void updateRemainingTime();
	};
}