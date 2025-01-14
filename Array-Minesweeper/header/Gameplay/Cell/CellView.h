#pragma once
#include "../../header/UI/UIElement/ButtonView.h"

namespace Gameplay
{
	namespace Cell
	{
		class CellController;

		class CellView
		{
		public:
			CellView(CellController* controller);
			~CellView();

			void initialize(float width, float height);
			void update();
			void render();

		private:
			UI::UIElement::ButtonView* cell_button;
			CellController* cell_controller;

			const int tile_size = 32;
			const int slice_count = 12;

			const float cell_top_offset = 274.f;
			const float cell_left_offset = 583.f;

			const float cell_texture_width = 384.f;
			const float cell_texture_height = 32.f;


			void initializeButtonImage(float width, float height);
			void setCellTexture();
			sf::Vector2f getCellScreenPosition(float width, float height);
			void registerButtonCallback();
			void cellButtonCallback(UI::UIElement::ButtonType button_type);
		};
	}
}