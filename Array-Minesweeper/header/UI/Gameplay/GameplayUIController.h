#pragma once

#include "../../header/UI/Interface/IUIController.h"
#include "../../header/UI/UIElement/TextView.h"
#include "../../header/UI/UIElement/ButtonView.h"

namespace UI
{
	namespace GameplayUI
	{
		class GameplayUIController : public Interface::IUIController
		{
		public:
			GameplayUIController();
			~GameplayUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;

		private:
			const int font_size = 110;
			const sf::Color text_color = sf::Color::Red;

			const float time_text_top_offset = 65.f;
			const float time_text_left_offset = 1090.f;

			UIElement::TextView* time_text;

			void createTexts();
			void initializeTexts();
			void initializeTimetext();
			void updateTimeText();

			void destroy();
		};
	}
}