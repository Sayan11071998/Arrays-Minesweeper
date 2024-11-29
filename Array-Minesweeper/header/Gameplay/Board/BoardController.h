#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/UI/UIElement/ButtonView.h"
#include <random>

namespace Gameplay
{
	namespace Board
	{
		class BoardView;

		enum class BoardState
		{
			FIRST_CELL,
			PLAYING,
			COMPLETED
		};

		class BoardController
		{
		public:
			static const int number_of_rows = 9;
			static const int number_of_colums = 9;
			static const int mines_count = 8;

			BoardController();
			~BoardController();

			void initialize();
			void update();
			void render();
			
			void processCellInput(Cell::CellController* cell_controller, UI::UIElement::ButtonType button_type);

			int getMinesCount();

			BoardState getBoardState();
			void setBoardState(BoardState state);

			void reset();

		private:
			BoardView* board_view;
			Cell::CellController* board[number_of_rows][number_of_colums];
			int flagged_cells;
			BoardState board_state;
			std::default_random_engine random_engine;
			std::random_device random_device;

			void createBoard();
			void initializeCells();

			void openCell(sf::Vector2i cell_position);
			void flagCell(sf::Vector2i cell_position);
			void populateBoard(sf::Vector2i cell_position);
			void populateMines(sf::Vector2i cell_position);
			void pupulateCells();
			int countMinesAround(sf::Vector2i cell_position);
			bool isValidCellPosition(sf::Vector2i cell_position);
			void openAllCell();
			void processCellValue(sf::Vector2i cell_position);

			void destroy();
			void resetBoard();
			void deleteBoard();
		};
	}
}