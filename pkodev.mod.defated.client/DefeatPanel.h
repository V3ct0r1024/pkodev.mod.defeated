#pragma once
#include <deque>
#include "structure.h"
#include "GuiPic.h"
#include "TextLabel.h"

namespace pkodev { namespace gui {

    struct DefeatItem final {
        unsigned int time{ 0u };
        CTextLabel atker;
        CTextLabel defer;
        CGuiPic icon;
    };

	class DefeatPanel final
	{
        public:

            enum class HorizontalAlign : unsigned int { Left, Right };
            enum class VerticalAlign : unsigned int { Top,  Bottom };

            using Point = Vector2D<int>;
            using Size = Vector2D<unsigned int>;
            using ItemText = std::pair<std::string, CTextLabel::Colors>;
            using Align = std::pair<HorizontalAlign, VerticalAlign>;

            DefeatPanel(const Point& pos = {8, 250}, unsigned int maxItems = 5u,
                unsigned int hideTime = 5000u, unsigned int step = 24u);
            ~DefeatPanel() = default;

            void AddItem(const ItemText& atker, const ItemText& defer,
                const std::string& icon);
            void Clear() { m_items.clear(); };
            void Update(unsigned int timeParam);
            void Render();

            unsigned int GetItemsCount() const { return m_items.size(); }
            bool Empty() const { return m_items.empty(); }

            void SetHideTime(unsigned int time) { m_hideTime = time; }
            unsigned int GetHideTime() const { return m_hideTime; }

            void SetMaxItems(unsigned int max) { m_maxItems = max; }
            unsigned int GetMaxItems() const { return m_maxItems; }

            void SetItemsStep(int step) { m_step = step; };
            int GetItemsStep() const { return m_step; }

            void SetPosition(const Point& pos) { m_position = pos; };
            const Point& GetPosition() const { return m_position; }

            void SetAlign(const Align& align) { m_align = align; }
            const Align& GetAlign() const { return m_align; }

            unsigned int GetWidth() const;
            unsigned int GetHeight() const;

            void SetResolution(const Size& resolution) { m_resolition = resolution; }

            void SetDebug(bool draw) { m_debug = draw; }
            bool IsDebugEnabled() const { return m_debug; }
            
        private:

            using Items = std::deque<DefeatItem>;

            const unsigned int maxNameLength = 20u;
            const float k = 0.85f;
            const unsigned int margin = 8u;
            const unsigned int iconSize = 18u;
            const unsigned int space = 16u;

            unsigned int m_currentTime;
            unsigned int m_hideTime;
            unsigned int m_lastHideTime;
            unsigned int m_maxItems;
            int m_step;
            bool m_debug;
            Point m_position;
            Align m_align;
            Size m_resolition;
            Items m_items;
	};

} }
