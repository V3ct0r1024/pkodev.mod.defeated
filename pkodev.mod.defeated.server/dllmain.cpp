#include <Windows.h>
#include <detours.h>

#include <iostream>
#include <sstream>
#include <unordered_set>

#include <loader.h>
#include <common.h>
#include <Settings.h>

#include "address.h"
#include "import.h"
#include "hook.h"
#include "structure.h"

#include "WPacket.h"
#include "GameServerApp.h"
#include "Character.h"
#include "Player.h"
#include "SubMap.h"

#include "SkillTable.h"
#include "Flag.h"
#include "CharacterList.h"


pkodev::CSkillTable g_table;
pkodev::Flag<int> g_lastEffectId;
pkodev::Flag<std::pair<int, int>> g_lastJobAndSkillId;
pkodev::CCharacterList g_charactersOnMap;

std::unordered_set<short int> g_defaultSkills = { 28, 29, 30, 31, 32, 34, 36, 38 };

/*
    ID: 28 - Меч
    ID: 29 - Большой меч
    ID: 30 - Лук
    ID: 31 - Мушкет
    ID: 32 - Клинок
    ID: 34 - Кинжал
    ID: 36 - Короткий посох
    ID: 38 - Двуручное оружие
*/

struct Settings final : public pkodev::CSettings  {
    std::unordered_set<std::string> allowedMaps;
    private:
        void ParseSettings(const json& data) override;
}
g_settings;

std::ostream& operator<<(std::ostream& os, const Settings& settings);

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
            << " settings"  << " from file '" << ss.str() << "'!" << std::endl;
    }
    else {
        std::clog << '[' << TOSTRING(MOD_NAME) << "] Loaded settings:" << std::endl;
        std::clog << '[' << TOSTRING(MOD_NAME) << "] " << g_settings << std::endl;
    }

    DetourRestoreAfterWith();
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourAttach(&(PVOID&)pkodev::import::GetCSkillStateRecordInfo, pkodev::hook::GetCSkillStateRecordInfo);
    DetourAttach(&(PVOID&)pkodev::import::CFightAble__SetDie, pkodev::hook::CFightAble__SetDie);
    DetourAttach(&(PVOID&)pkodev::import::CFightAble__OnSkillState, pkodev::hook::CFightAble__OnSkillState);
    DetourAttach(&(PVOID&)pkodev::import::CFightAble__SkillTarEffect, pkodev::hook::CFightAble__SkillTarEffect);
    DetourAttach(&(PVOID&)pkodev::import::CCharacter__AddSkillState, pkodev::hook::CCharacter__AddSkillState);
    DetourAttach(&(PVOID&)pkodev::import::CFightAble__RangeEffect, pkodev::hook::CFightAble__RangeEffect);
    DetourAttach(&(PVOID&)pkodev::import::SubMap__Add, pkodev::hook::SubMap__Add);
    DetourAttach(&(PVOID&)pkodev::import::SubMap__Delete, pkodev::hook::SubMap__Delete);
    DetourTransactionCommit();
}

void Stop()
{
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourDetach(&(PVOID&)pkodev::import::GetCSkillStateRecordInfo, pkodev::hook::GetCSkillStateRecordInfo);
    DetourDetach(&(PVOID&)pkodev::import::CFightAble__SetDie, pkodev::hook::CFightAble__SetDie);
    DetourDetach(&(PVOID&)pkodev::import::CFightAble__OnSkillState, pkodev::hook::CFightAble__OnSkillState);
    DetourDetach(&(PVOID&)pkodev::import::CFightAble__SkillTarEffect, pkodev::hook::CFightAble__SkillTarEffect);
    DetourDetach(&(PVOID&)pkodev::import::CFightAble__RangeEffect, pkodev::hook::CFightAble__RangeEffect);
    DetourDetach(&(PVOID&)pkodev::import::CCharacter__AddSkillState, pkodev::hook::CCharacter__AddSkillState);
    DetourDetach(&(PVOID&)pkodev::import::SubMap__Add, pkodev::hook::SubMap__Add);
    DetourDetach(&(PVOID&)pkodev::import::SubMap__Delete, pkodev::hook::SubMap__Delete);
    DetourTransactionCommit();
}

void Settings::ParseSettings(const json& data)
{
    allowedMaps = data["maps"].get<decltype(allowedMaps)>();
}

std::ostream& operator<<(std::ostream& os, const Settings& settings)
{
    bool first = true;
    std::clog << "Maps: ";
    for (const std::string& map : settings.allowedMaps) {
        if (first == false) {
            std::clog << ", ";
        }
        first = false;
        std::clog << map;
    }
    std::clog << '.';
    return os;
}

void __fastcall pkodev::hook::CFightAble__SetDie(CCharacter* This, void*, CCharacter* pCSkillSrcCha)
{
    const CCharacter* atker = pCSkillSrcCha;
    const CCharacter* defer = This;

    if ( (atker->IsPlayerOwnCha() == true) && (defer->IsPlayerOwnCha() == true) )
    {
        const std::string atkerMapName = atker->GetSubMap()->GetName();
        if (g_settings.allowedMaps.count(atkerMapName) == 0) {
            import::CFightAble__SetDie(This, pCSkillSrcCha);
            return;
        }

        short int id = 0;
        bool defaultSkill = false;

        if (g_lastEffectId.state == false) {
            id = atker->GetFightInit().pSSkillGrid->sID;
            defaultSkill = (g_defaultSkills.count(id) == 1);
            if (defaultSkill == true) {
                const SItemGrid* rhand = atker->GetEquipItem(9);
                if (rhand != nullptr) {
                    id = rhand->sID;
                }
                else {
                    const SItemGrid* lhand = atker->GetEquipItem(6);
                    if (lhand != nullptr) {
                        id = lhand->sID;
                    }
                    else {
                        id = 0;
                    }
                }
            }
        }
        else {
            const auto opt = g_table.GetSkill(atker->GetAttr(4), g_lastEffectId.data);
            if (opt.has_value() == true) {
                id = opt.value();
            }
        }

        const int data = (
            (defaultSkill                << 31) |
            ((atker->GetSideID() & 0x0F) << 16) |
            ((defer->GetSideID() & 0x0F) << 20) |
            id
        );

        const int guildId = (
            ((defer->GetGuildID() & 0xFFFF) << 16) |
            ( atker->GetGuildID() & 0xFFFF       )
        );

        const CPlayer* atkerPlayer = atker->GetPlayer();
        const CPlayer* deferPlayer = defer->GetPlayer();

        WPacket pkt(CMD_MC_DEFEATED);
        pkt << atker->GetName() << defer->GetName() << data << guildId
                << atkerPlayer->getTeamLeaderID() << deferPlayer->getTeamLeaderID()
                << atkerPlayer->GetID() << deferPlayer->GetID();

        g_charactersOnMap.SendPacket(atkerMapName, pkt);
    }

    import::CFightAble__SetDie(This, pCSkillSrcCha);
}

void __fastcall pkodev::hook::CFightAble__OnSkillState(CCharacter* This, void*, DWORD dwCurTick)
{
    if (This->IsPlayerOwnCha() == true) {
        const auto onSkillState = g_lastEffectId.Spawn();
        import::CFightAble__OnSkillState(This, dwCurTick);
    }
    else {
        import::CFightAble__OnSkillState(This, dwCurTick);
    }
}

void* __cdecl pkodev::hook::GetCSkillStateRecordInfo(int nTypeID)
{
    if (g_lastEffectId.state == true) { g_lastEffectId.data = nTypeID; }
    return import::GetCSkillStateRecordInfo(nTypeID);
}

void __fastcall pkodev::hook::CFightAble__SkillTarEffect(CCharacter* This, void*, SFireSrc* pSFireSrc)
{
    if (pSFireSrc->pCFightSrc->IsPlayerOwnCha() == true) {
        const auto SkillTarEffect = g_lastJobAndSkillId.Spawn();
        g_lastJobAndSkillId.data.first = pSFireSrc->pCFightSrc->GetAttr(4);
        g_lastJobAndSkillId.data.second = pSFireSrc->pCSkillRecord->sID;;
        import::CFightAble__SkillTarEffect(This, pSFireSrc);
    }
    else {
        import::CFightAble__SkillTarEffect(This, pSFireSrc);
    }
}

void __fastcall pkodev::hook::CFightAble__RangeEffect(CCharacter* This, void*, SFireSrc* pSFireSrc,
    void* pCMap, int* plRangeBParam)
{
    if (pSFireSrc->pCFightSrc->IsPlayerOwnCha() == true) {
        g_table.SetSkill(pSFireSrc->pCFightSrc->GetAttr(4),
            pSFireSrc->pCSkillTData->sStateParam[0], pSFireSrc->pCSkillRecord->sID);
    }

    import::CFightAble__RangeEffect(This, pSFireSrc, pCMap, plRangeBParam);
}

bool __fastcall pkodev::hook::CCharacter__AddSkillState(CCharacter* This, void*, unsigned char uchFightID,
    unsigned int ulSrcWorldID, int lSrcHandle, char chObjType, char chObjHabitat, char chEffType,
    unsigned char uchStateID, unsigned char uchStateLv, int lOnTick, char chType, bool bNotice)
{
    const bool ret = import::CCharacter__AddSkillState(This, uchFightID, ulSrcWorldID, lSrcHandle,
        chObjType, chObjHabitat, chEffType, uchStateID, uchStateLv, lOnTick, chType, bNotice);

    if ( (g_lastJobAndSkillId.state == true) && (ret == true) ) {
        g_table.SetSkill(g_lastJobAndSkillId.data.first,
            static_cast<short int>(uchStateID), g_lastJobAndSkillId.data.second);
    }

    return ret;
}

void __fastcall pkodev::hook::SubMap__Add(const SubMap* This, void*, CCharacter* pCEnt)
{
    if (pCEnt->IsPlayerOwnCha() == true) {
        if (g_settings.allowedMaps.count(This->GetName()) != 0) {
            g_charactersOnMap.AddCharacter(This->GetName(), pCEnt);
        }
    }

    import::SubMap__Add(This, pCEnt);
}

void __fastcall pkodev::hook::SubMap__Delete(const SubMap* This, void*, CCharacter* pCEnt)
{
    if (pCEnt->IsPlayerOwnCha() == true) {
        if (g_settings.allowedMaps.count(This->GetName()) != 0) {
            g_charactersOnMap.RemoveCharacter(This->GetName(), pCEnt);
        }
    }

    import::SubMap__Delete(This, pCEnt);
}
