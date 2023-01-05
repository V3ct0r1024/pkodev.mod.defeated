#include "DefeatPanel.h"
#include "import.h"

namespace pkodev { namespace gui {

    DefeatPanel::DefeatPanel(const Point& pos, unsigned int maxItems,
        unsigned int hideTime, unsigned int step) :
        m_currentTime(0u),
        m_hideTime(hideTime),
        m_lastHideTime(0u),
        m_maxItems(maxItems),
        m_step(step),
        m_debug(false),
        m_position(pos),
        m_align{ HorizontalAlign::Left, VerticalAlign::Top },
        m_resolition{ 0u, 0u }
    {

    }

    void DefeatPanel::AddItem(const ItemText& atker, const ItemText& defer,
        const std::string& icon)
    {
        auto cutoff = [](const std::string& str, unsigned int maxLength) -> std::string {
            if (str.length() > maxLength) {
                return str.substr(0u, maxLength - 3u).append("...");
            }
            return str;
        };

        if (m_items.size() == m_maxItems) {
            m_items.pop_front();
        }

        DefeatItem item;
        item.time = m_currentTime;
        item.atker.SetText(cutoff(atker.first, maxNameLength));
        item.atker.SetColor(atker.second);
        item.defer.SetText(cutoff(defer.first, maxNameLength));
        item.defer.SetColor(defer.second);
        item.icon.Load(CGuiPic::GetIconFile(icon),
            32u, 32u, (iconSize / 32.0f), (iconSize / 32.0f) );

        m_items.push_back(std::move(item));
    }

    void DefeatPanel::Update(unsigned int timeParam)
    {
        m_currentTime = timeParam;

        if ( (m_currentTime - m_lastHideTime) >= 100u) 
        {
            m_lastHideTime = timeParam;
            if (m_items.empty() == false) {
                for (auto it = m_items.begin(); it != m_items.end();) {
                    if ( (m_currentTime - it->time) >= m_hideTime) {
                        it = m_items.erase(it);
                        continue;
                    }
                    break;
                }
            }
        }
    }

    void DefeatPanel::Render()
    {
        const unsigned int x0 = ( (m_align.first == HorizontalAlign::Left) ?
            m_position.x : m_resolition.x - m_position.x ) + margin;
        const unsigned int y0 = ( (m_align.second == VerticalAlign::Top) ?
            m_position.y : m_resolition.y - m_position.y ) + margin;

        static Point atker = { 0u, 0u }, defer = { 0u, 0u }, icon = { 0u, 0u };

        for (unsigned int i = 0; i < m_items.size(); ++i)
        {
            const DefeatItem& item = m_items[i];
            const unsigned int& x = x0;
            const unsigned int y = y0 + (i * m_step);
            const unsigned int atkerWidth = static_cast<unsigned int>(
                k * CTextLabel::GetTextSize(item.atker.GetText()).x );

            atker.x = x; 
            atker.y = y;

            icon.x = (atker.x + atkerWidth + space);
            icon.y = (y - (item.icon.GetHeight() / 4u));

            defer.x = (icon.x + iconSize + space);
            defer.y = y;

            item.atker.Render(atker.x, atker.y, 1);
            item.defer.Render(defer.x, defer.y, 1);
            item.icon.Render(icon.x, icon.y);
        }
        
        if (m_debug == true) {
            RECT rt;
            rt.left = (x0 - margin);
            rt.top = (y0 - margin);
            rt.right = (rt.left + GetWidth());
            rt.bottom = (rt.top + GetHeight());
            import::RenderHintFrame(&rt,
                static_cast<DWORD>(CTextLabel::Colors::Green) );
        }
    }

    void DefeatPanel::SetMaxItems(unsigned int max)
    {
        if (m_items.size() > max) {
            const unsigned int delta = m_items.size() - max;
            for (unsigned int i = 0; i < delta; ++i) {
                m_items.pop_front();
            }
        }
        m_maxItems = max;
    }

    unsigned int DefeatPanel::GetWidth() const
    {
        static const unsigned int charWidth = CTextLabel::GetTextSize("a").x;
        return iconSize +
            2u * (static_cast<unsigned int>((charWidth * maxNameLength) * k) + space + margin);
    }

    unsigned int DefeatPanel::GetHeight() const
    {
        static const unsigned int charHeight = CTextLabel::GetTextSize("a").y;
        return ( 2u * margin + m_step * (m_maxItems - 1u)
            + static_cast<unsigned int>(charHeight * k) );
    }

} }