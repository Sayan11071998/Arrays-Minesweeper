#pragma once
#include <SFML/Graphics.hpp>

namespace Gameplay
{
	namespace Cell
	{
		enum class CellState
		{
			HIDDEN,
			OPEN,
			FLAGGED
		};

		enum class CellValue
		{
			EMPTY,
			ONE,
			TWO,
			THREE,
			FOUR,
			FIVE,
			SIX,
			SEVEN,
			EIGHT,
			MINE
		};

		class CellModel
		{
		public:
			CellModel(int cell_index);
			~CellModel();

			CellState getCellState();
			void setCellState(CellState state);

			CellValue getCellValue();
			void setCellValue(CellValue value);

			int getCellIndex();

			sf::Vector2i getCellPosition();
			void setCellPosition(sf::Vector2i grid_position);

			void reset();

		private:
			CellState cell_state;
			CellValue cell_value;

			int cell_index;
			sf::Vector2i position;
		};
	}
}