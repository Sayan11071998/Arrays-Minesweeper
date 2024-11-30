#include "../../header/Gameplay/Board/BoardService.h"
#include "../../header/Gameplay/GameplayController.h"

namespace Gameplay
{
	namespace Board
	{
		using namespace Cell;
		using namespace UI;
		using namespace UI::UIElement;

		BoardService::BoardService()
		{
			board_controller = nullptr;
		}

		BoardService::~BoardService()
		{
			destroy();
		}

		void BoardService::initialize()
		{
			board_controller = new BoardController();
			board_controller->initialize();
		}

		void BoardService::update()
		{
			board_controller->update();
		}

		void BoardService::render()
		{
			board_controller->render();
		}

		void BoardService::resetBoard()
		{
			board_controller->reset();
		}

		void BoardService::processCellInput(Cell::CellController* cell_controller, UI::UIElement::ButtonType button_type)
		{
			board_controller->processCellInput(cell_controller, button_type);
		}

		int BoardService::getMinesCount()
		{
			return board_controller->getMinesCount();
			//return board_controller->mines_count;
		}

		BoardState BoardService::getBoardState()
		{
			return board_controller->getBoardState();
		}

		void BoardService::setBoardState(BoardState state)
		{
			board_controller->setBoardState(state);
		}

		void BoardService::showBoard()
		{
			board_controller->showBoard();
		}

		void BoardService::flagAllMines()
		{
			board_controller->flagAllMines();
		}

		void BoardService::destroy()
		{
			delete(board_controller);
		}
	}
}