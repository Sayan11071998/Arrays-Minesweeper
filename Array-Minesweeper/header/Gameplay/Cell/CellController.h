#pragma once
#include <SFML/Graphics.hpp>

namespace Gameplay
{
	namespace Cell
	{
		class CellView;

		class CellController
		{
		public:
			CellController();
			~CellController();

			void initialize();
			void update();
			void render();
			void reset();

		private:
			CellView* cell_view;

			void destroy();
		};
	}
}