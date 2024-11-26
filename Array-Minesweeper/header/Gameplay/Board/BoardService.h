#pragma once
#include "../../header/Gameplay/Board/BoardController.h"
#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/UI/UIElement/ButtonView.h"

namespace Gameplay
{
	namespace Board
	{
		class BoardService
		{
		public:
			BoardService();
			~BoardService();

			void initialize();
			void update();
			void render();
			void resetBoard();

			void processCellInput(Cell::CellController* cell_controller, UI::UIElement::ButtonType button_type);

			int getMinesCount();

		private:
			Board::BoardController* board_controller;

			void destroy();
		};

	}
}