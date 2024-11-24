#include "../../header/Gameplay/Board/BoardController.h"
#include "../../header/Gameplay/Board/BoardView.h"
#include "../../header/Gameplay/Cell/CellController.h"

namespace Gameplay
{
	namespace Board
	{
		using namespace Cell;

		BoardController::BoardController()
		{
			board_view = new BoardView(this);
			createBoard();
		}

		BoardController::~BoardController()
		{
			destroy();
		}

		void BoardController::initialize()
		{
			board_view->initialize();
			initializeCells();
		}

		void BoardController::update()
		{
			board_view->update();

			for (int row = 0; row < number_of_rows; row++)
			{
				for (int col = 0; col < number_of_colums; col++)
				{
					board[row][col]->update();
				}
			}
		}

		void BoardController::render()
		{
			board_view->render();

			for (int row = 0; row < number_of_rows; row++)
			{
				for (int col = 0; col < number_of_colums; col++)
				{
					board[row][col]->render();
				}
			}
		}

		void BoardController::createBoard()
		{
			for (int row = 0; row < number_of_rows; row++)
			{
				for (int col = 0; col < number_of_colums; col++)
				{
					board[row][col] = new CellController(sf::Vector2i(row, col));
				}
			}
		}

		void BoardController::initializeCells()
		{
			float cell_width = board_view->getCellWidth();
			float cell_height = board_view->getCellHeight();

			for (int row = 0; row < number_of_rows; row++)
			{
				for (int col = 0; col < number_of_colums; col++)
				{
					board[row][col]->initialize(cell_width, cell_height);
				}
			}
		}

		void BoardController::reset()
		{
			resetBoard();
		}

		void BoardController::resetBoard()
		{
			for (int row = 0; row < number_of_rows; row++)
			{
				for (int col = 0; col < number_of_colums; col++)
				{
					board[row][col]->reset();
				}
			}
		}

		void BoardController::deleteBoard()
		{
			for (int row = 0; row < number_of_rows; row++)
			{
				for (int col = 0; col < number_of_colums; col++)
				{
					delete board[row][col];
				}
			}
		}

		void BoardController::destroy()
		{
			deleteBoard();
			delete(board_view);
		}
	}
}