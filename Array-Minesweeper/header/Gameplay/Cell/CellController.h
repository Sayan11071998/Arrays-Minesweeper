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
			CellController(sf::Vector2i grid_position);
			~CellController();

			void initialize(float cell_width, float cell_height);
			void update();
			void render();

			void openCell();
			void flagCell();

			CellState getCellState();
			CellValue getCellValue();
			sf::Vector2i getCellPosition();
			//int getMinesAround();
			
			void reset();

		private:
			CellView* cell_view;
			CellModel* cell_model;

			void destroy();
		};
	}
}