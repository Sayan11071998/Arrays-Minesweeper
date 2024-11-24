#pragma once
#include <SFML/Graphics.hpp>

namespace Gameplay
{
	namespace Cell
	{
		class CellView;
		class CellModel;
		enum class CellState;
		enum class CellValue;

		class CellController
		{
		public:
			CellController(int cell_index);
			~CellController();

			void initialize(float cell_width, float cell_height);
			void update();
			void render();

			CellState getCellState();
			CellValue getCellValue();
			int getCellIndex();
			sf::Vector2i getCellPosition();

			void reset();

		private:
			CellView* cell_view;
			CellModel* cell_model;

			void destroy();
		};
	}
}