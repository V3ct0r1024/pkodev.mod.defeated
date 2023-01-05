#include <Windows.h>
#include <detours.h>

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_set>

#include <loader.h>
#include <common.h>
#include <Settings.h>

#include "address.h"
#include "import.h"
#include "hook.h"
#include "structure.h"
#include "Utils.h"

#include "DefeatPanel.h"


pkodev::gui::DefeatPanel g_defeatPanel;

void DefeatPanelTest(unsigned int time);

struct Settings final : public pkodev::CSettings {
    using Panel = pkodev::gui::DefeatPanel;
    bool debug{ false };
    unsigned int hideTime{ 5000u };
    unsigned int maxItems{ 5u };
    int itemStep{ 24 };
    Panel::Point pos{ 8, 350 };
    Panel::Align align{ Panel::HorizontalAlign::Left, Panel::VerticalAlign::Top  };
    private:
        void ParseSettings(const json& data) override;
}
g_settings;

std::ostream& operator<<(std::ostream& out, const Settings& settings);

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    return TRUE;
}

void GetModInformation(mod_info& info)
{
    strcpy_s(info.name, TOSTRING(MOD_NAME));
    strcpy_s(info.version, TOSTRING(MOD_VERSION));
    strcpy_s(info.author, TOSTRING(MOD_AUTHOR));
    info.exe_version = MOD_EXE_VERSION;
}

void Start(const char* path)
{
    std::ostringstream ss;

    ss << path << '\\' << TOSTRING(MOD_NAME) << ".json";

    std::clog << '[' << TOSTRING(MOD_NAME) << "] Loading mod settings from file '"
        << ss.str() << "' . . ." << std::endl;

    if (g_settings.Load(ss.str()) == false) {
        std::cerr << '[' << TOSTRING(MOD_NAME) << "] Failed to load " << TOSTRING(MOD_NAME)
            << " settings" << " from file '" << ss.str() << "'!" << std::endl;
        std::clog << '[' << TOSTRING(MOD_NAME) << "] Using default settings: " << std::endl;
    }
    else {
        std::clog << '[' << TOSTRING(MOD_NAME) << "] Loaded settings:" << std::endl;
    }

    std::clog << g_settings << std::endl;

    g_defeatPanel.SetDebug(g_settings.debug);
    g_defeatPanel.SetHideTime(g_settings.hideTime);
    g_defeatPanel.SetMaxItems(g_settings.maxItems);
    g_defeatPanel.SetItemsStep(g_settings.itemStep);
    g_defeatPanel.SetPosition(g_settings.pos);
    g_defeatPanel.SetAlign(g_settings.align);

    DetourRestoreAfterWith();
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourAttach(&(PVOID&)pkodev::import::UIRender__SetScreen, pkodev::hook::UIRender__SetScreen);
    DetourAttach(&(PVOID&)pkodev::import::NetIF__HandlePacketMessage, pkodev::hook::NetIF__HandlePacketMessage);
    DetourAttach(&(PVOID&)pkodev::import::CWorldScene___FrameMove, pkodev::hook::CWorldScene___FrameMove);
    DetourAttach(&(PVOID&)pkodev::import::CWorldScene___Render, pkodev::hook::CWorldScene___Render);
    DetourTransactionCommit();
}

void Stop()
{
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourDetach(&(PVOID&)pkodev::import::UIRender__SetScreen, pkodev::hook::UIRender__SetScreen);
    DetourDetach(&(PVOID&)pkodev::import::NetIF__HandlePacketMessage, pkodev::hook::NetIF__HandlePacketMessage);
    DetourDetach(&(PVOID&)pkodev::import::CWorldScene___FrameMove, pkodev::hook::CWorldScene___FrameMove);
    DetourDetach(&(PVOID&)pkodev::import::CWorldScene___Render, pkodev::hook::CWorldScene___Render);
    DetourTransactionCommit();
}

void DefeatPanelTest(unsigned int time)
{
    using Color = pkodev::gui::CTextLabel::Colors;

    static unsigned int lastTime = 0u;
    static unsigned int currentStep = 0u;

    static std::vector<std::string> names = { "V3ct0r1024", "V3ct0r2048", "V3crt0r4092",
        "Toooooooo looooooong naaaaame", "Anooooother loooooong name", "I have long name",
        "PKODev.NET", "Player", "12345678901234567890" };

    static std::vector<Color> colors = { Color::Blue, Color::Green, Color::Orange,
        Color::Yellow, Color::White, Color::Red };

    static std::vector<std::string> icons = { "w0002", "w0092", "w0021", "w0265",
        "w0290", "w0093", "book", "n1216", "e0097", "e0119", "h0213", "n1175" };
   
    if ( (time - lastTime) > 1000u)
    {
        lastTime = time;

        std::srand(lastTime);

        const unsigned int atkerNameIdx = ( rand() % names.size() );
        const unsigned int deferNameIdx = ( rand() % names.size() );
        const unsigned int atkerColorIdx = ( rand() % colors.size() );
        const unsigned int deferColorIdx = ( rand() % colors.size() );
        const unsigned int iconIdx = ( rand() % icons.size() );

        switch (currentStep++)
        {
            case 2u: g_defeatPanel.SetMaxItems(g_defeatPanel.GetMaxItems() + 1u); break;
            case 4u: g_defeatPanel.SetMaxItems(g_defeatPanel.GetMaxItems() + 1u); break;
            case 6u: g_defeatPanel.SetItemsStep(32); break;
            case 14u: g_defeatPanel.SetMaxItems(g_defeatPanel.GetMaxItems() - 2u); break;
            case 17u: g_defeatPanel.SetItemsStep(24); break;
            default:
                g_defeatPanel.AddItem(  { names[atkerNameIdx], colors[atkerColorIdx] },
                    { names[deferNameIdx], colors[deferColorIdx] },  icons[iconIdx] );
        }
    }
}

void Settings::ParseSettings(const json& data)
{
    debug    = data["debug"]   .get<bool>();
    hideTime = data["hideTime"].get<unsigned int>();
    maxItems = data["maxItems"].get<unsigned int>();
    itemStep = data["itemStep"].get<int>();
    pos.x    = data["pos"]["x"].get<int>();
    pos.y    = data["pos"]["y"].get<int>();

    auto validateAlign = [](const std::string& align,
        const std::unordered_set<std::string>& valid) -> bool {
            if (valid.count(align) == 0u) {
                return false;
            }
            return true;
    };

    if ( validateAlign(data["align"]["x"], { "left", "right" }) == false ) {
        throw std::exception( "Invalid value for 'align:x' parameter!"
            " Should be 'left' or 'right'." );
    }

    if ( validateAlign(data["align"]["y"], { "top", "bottom" }) == false ) {
        throw std::exception( "Invalid value for 'align:y' parameter!"
            " Should be 'top' or 'bottom'." );
    }

    using hAlign = pkodev::gui::DefeatPanel::HorizontalAlign;
    using vAlign = pkodev::gui::DefeatPanel::VerticalAlign;

    align.first = ( (data["align"]["x"] == "left") ? hAlign::Left : hAlign::Right );
    align.second = ( (data["align"]["y"] == "top") ? vAlign::Top : vAlign::Bottom );
}

std::ostream& operator<<(std::ostream& out, const Settings& settings)
{
    using hAlign = pkodev::gui::DefeatPanel::HorizontalAlign;
    using vAlign = pkodev::gui::DefeatPanel::VerticalAlign;

    out << "* Defeat panel item hide time: " << settings.hideTime << " ms;" << std::endl;
    out << "* Defeat panel max items count: " << settings.maxItems << ";" << std::endl;
    out << "* Item step: " << settings.itemStep << ";" << std::endl;
    out << "* Position: (x: " << settings.pos.x << ", y: " << settings.pos.y << ");" << std::endl;
    out << "* Align: (x: " << ( (settings.align.first == hAlign::Left) ? "left" : "right" ) << "; y: " 
        << ( (settings.align.second == vAlign::Top) ? "top" : "bottom") << ")." << std::endl;
    
    return out;
}

void __fastcall pkodev::hook::UIRender__SetScreen(void* This, void*,
    int w, int h, bool isFull)
{
    import::UIRender__SetScreen(This, w, h, isFull);
    g_defeatPanel.SetResolution(
        { static_cast<unsigned int>(w), static_cast<unsigned int>(h) } );
}

bool __fastcall pkodev::hook::NetIF__HandlePacketMessage(void* This, void*,
    void* datasock, RPacket* pk)
{
    const unsigned short int id = pk->ReadCmd();

    if (id == CMD_MC_DEFEATED)
    {
        static CharacterSide atkerSide, deferSide;

        std::string atker, defer;
        int data = 0, guildId = 0;

        *pk >> atker >> defer >> data >> guildId >> atkerSide.partyId
            >> deferSide.partyId >> atkerSide.chaId >> deferSide.chaId;

        const short int id = (data & 0xFFFF);
        atkerSide.sideId = (data >> 16) & 0x0F;
        deferSide.sideId = (data >> 20) & 0x0F;
        atkerSide.guildId = (guildId & 0xFFFF);
        deferSide.guildId = ((guildId & 0xFFFF0000) >> 16);        

        std::string icon = "error";

        if (id != 0)
        {
            const bool defaultSkill = ((data & 0x80000000) >> 31);
            if (defaultSkill == true) {
                const CItemRecord* item = import::GetItemRecordInfo(id);
                if ((item != nullptr) && (std::strcmp(item->icon, "0") != 0)) {
                    icon = item->icon;
                }
            }
            else {
                if (id == 25) {
                    icon = "w0037";
                }
                else {
                    const CSkillRecord* skill = import::GetSkillRecordInfo(id);
                    if ((skill != nullptr) && (std::strcmp(skill->szIcon, "0") != 0)) {
                        icon = skill->szIcon;
                    }
                }
            }
        }

        using Color = gui::CTextLabel::Colors;
        const CharacterSide mySide = CCharacter::Main()->GetSide();
        const Color atkerColor = ( (mySide == atkerSide) ? Color::Green : Color::Red );
        const Color deferColor = ( (mySide == deferSide) ? Color::Green : Color::Red );

        g_defeatPanel.AddItem( { atker, atkerColor }, { defer, deferColor }, icon );

        return true;
    }

    return import::NetIF__HandlePacketMessage(This, datasock, pk);
}

void __fastcall pkodev::hook::CWorldScene___FrameMove(void* This, void*, DWORD dwTimeParam)
{
    import::CWorldScene___FrameMove(This, dwTimeParam);
    
    if (g_settings.debug == true) {
        DefeatPanelTest(static_cast<unsigned int>(dwTimeParam));
    }

    g_defeatPanel.Update(static_cast<unsigned int>(dwTimeParam));
}

void __fastcall pkodev::hook::CWorldScene___Render(void* This, void*)
{
    import::CWorldScene___Render(This);
    g_defeatPanel.Render();
}