#pragma once
#include <string>
#include "structure.h"

namespace pkodev { namespace gui {

	class CTextLabel final
	{
		public:

			enum class Colors : unsigned int {
				White = 0xFFFFFFFF,
				Black = 0xFF000000,
				Red = 0xFFFF0000,
				Green = 0xFF00FF00,
				Blue = 0xFF0000FF,
				Yellow = 0xFFFFFF00,
				Orange = 0xFFFF8000,
			};

			CTextLabel(const std::string& text = "", const Colors& color = Colors::White,
				 const Colors& background = Colors::Black);
			~CTextLabel() = default;

			void SetColor(const Colors& color) { m_color = color; }
			const Colors& GetColor() const { return m_color; }

			void SetBackgroundColor(const Colors& color) { m_background = color; }
			const Colors& GetBackgroundColor() const { return m_background; }

			void SetText(const std::string& text) { m_text = text; }
			const std::string& GetText() const { return m_text; }

			void Render(int x, int y, int font = 0) const;

			static void Render(const std::string& str, int x, int y, int font = 0,
				const Colors& color = Colors::White, const Colors& background = Colors::Black);
			
			static Vector2D<unsigned int> GetTextSize(const std::string& text);

		private:

			std::string m_text;
			Colors m_color;
			Colors m_background;

	};

}}

