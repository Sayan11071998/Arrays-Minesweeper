#include "../../header/Gameplay/Cell/CellModel.h"

namespace Gameplay
{
	namespace Cell
	{
		CellModel::CellModel(int cell_index)
		{
			//reset();
			this->cell_index = cell_index;
		}

		CellModel::~CellModel() = default;

		CellState CellModel::getCellState()
		{
			return cell_state;
		}

		void CellModel::setCellState(CellState state)
		{
			cell_state = state;
		}

		CellValue CellModel::getCellValue()
		{
			return cell_value;
		}

		void CellModel::setCellValue(CellValue value)
		{
			cell_value = value;
		}

		int CellModel::getCellIndex()
		{
			return cell_index;
		}

		sf::Vector2i CellModel::getCellPosition()
		{
			return position;
		}

		void CellModel::setCellPosition(sf::Vector2i grid_position)
		{
			position = grid_position;
		}

		void CellModel::reset()
		{
			cell_state = CellState::HIDDEN;
			cell_value = CellValue::EMPTY;
		}
	}
}