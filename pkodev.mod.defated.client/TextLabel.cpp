#include "address.h"
#include "import.h"
#include "Utils.h"
#include "TextLabel.h"

namespace pkodev { namespace gui {

	Vector2D<unsigned int> CTextLabel::GetTextSize(const std::string& text)
	{
		Vector2D<unsigned int> size{ 0, 0 };

		import::CMPFont__GetTextSize( Utils::Get<void*>(address::MOD_EXE_VERSION::CMPFont),
			const_cast<char*>(text.c_str()), &size, 1.0f );

		return size;
	}

	CTextLabel::CTextLabel(const std::string& text, const Colors& color,
			const Colors& background) :
		m_text{ text },
		m_color{ color },
		m_background{ background }
	{

	}

	void CTextLabel::Render(int x, int y, int font) const
	{
		import::CGuiFont_BRender( reinterpret_cast<void*>(pkodev::address::MOD_EXE_VERSION::CGuiFont),
			font, m_text.c_str(), x, y, static_cast<int>(m_color), static_cast<int>(m_background) );
	}

	void CTextLabel::Render(const std::string& str, int x, int y, int font,
		const Colors& color, const Colors& background)
	{
		import::CGuiFont_BRender( reinterpret_cast<void*>(pkodev::address::MOD_EXE_VERSION::CGuiFont),
			font, str.c_str(), x, y, static_cast<int>(color), static_cast<int>(background));
	}

}}