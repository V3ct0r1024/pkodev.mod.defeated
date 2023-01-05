#pragma once

namespace pkodev
{
	namespace address
	{
        namespace GAMESERVER_136
        {
            // GameServerApp *g_gmsvr
            const unsigned int g_gmsvr = 0x0076D8FC;

            // bool GameServerApp::SendToClient(WPacket& pkt, GatePlayer* playerlist)
            const unsigned int GameServerApp__SendToClient = 0x00509DC0;

            // CSkillStateRecord* GetCSkillStateRecordInfo( int nTypeID )
            const unsigned int GetCSkillStateRecordInfo = 0x00492740;

            // void CFightAble::SetDie(CCharacter *pCSkillSrcCha)
            const unsigned int CFightAble__SetDie = 0x004FA6F0;

            // void CFightAble::OnSkillState(DWORD dwCurTick)
            const unsigned int CFightAble__OnSkillState = 0x00500370;

            // void CFightAble::SkillTarEffect(SFireUnit *pSFireSrc)
            const unsigned int CFightAble__SkillTarEffect = 0x004FA160;

            // void CFightAble::RangeEffect(SFireUnit *pSFireSrc, SubMap *pCMap, Long *plRangeBParam)
            const unsigned int CFightAble__RangeEffect = 0x004FD5E0;

            // bool CCharacter::AddSkillState(uChar uchFightID, uLong ulSrcWorldID, Long lSrcHandle, Char chObjType, Char chObjHabitat, Char chEffType,
            //    uChar uchStateID, uChar uchStateLv, Long lOnTick, dbc::Char chType, bool bNotice)
            const unsigned int CCharacter__AddSkillState = 0x004C9BD0;

            // dbc::Long CFightAble::getAttr(int nIdx)
            const unsigned int CFightAble__getAttr = 0x00401390;

            // char *__thiscall Entity::GetName(Entity *this)
            const unsigned int Entity__GetName = 0x0041F2E0;

            // bool CCharacter::IsPlayerOwnCha()
            const unsigned int CCharacter__IsPlayerOwnCha = 0x004BC6E0;

            // SItemGrid *__thiscall CCharacter::GetEquipItem(CCharacter *this, char chPart)
            const unsigned int CCharacter__GetEquipItem = 0x004BDB00;

            // dbc::Long CCharacter::GetSideID()
            const unsigned int CCharacter__GetSideID = 0x00419FD0;

            // DWORD CCharacter::GetGuildID()
            const unsigned int CCharacter__GetGuildID = 0x004CFF70;

            // DWORD CPlayer::getTeamLeaderID()
            const unsigned int CPlayer__getTeamLeaderID = 0x00414520;

            // SubMap *__thiscall Entity::GetSubMap(Entity *this)
            const unsigned int Entity__GetSubMap = 0x00416830;

            // dbc::Long CPlayer::GetID(void)
            const unsigned CPlayer__GetID = 0x00414630;

            // dbc::TcpCommApp
            const unsigned int TcpCommApp = 0x0076D8FC;

            // WPacket TcpCommApp::GetWPacket() const
            const unsigned int TcpCommApp__GetWPacket = 0x00520950;

            // WPacket::WPacket()
            const unsigned int WPacket__WPacketCopyCtor = 0x0041C950;

            // WPacket::~WPacket
            const unsigned int WPacket__WPacketDtor = 0x0041C9E0;

            // WPacket& operator=(const WPacket&)
            const unsigned int WPacket__operator_equal = 0x0051ACC0;

            // bool WPacket::WriteCmd(uShort cmd)
            const unsigned int WPacket__WriteCmd = 0x0051A6B0;

            // bool WPacket::WriteLong(uLong value)
            const unsigned int WPacket__WriteLong = 0x0051B8B0;

            // bool WPacket::WriteString(cChar *str)
            const unsigned int WPacket__WriteString = 0x0051BAD0;

            // void SubMap::Add(Entity* pCEnt)
            const unsigned int SubMap__Add = 0x004B5BB0;

            // void SubMap::Delete(Entity* pCEnt)
            const unsigned int SubMap__Delete = 0x004B61B0;

            // const char* SubMap::GetName(void)
            const unsigned int SubMap__GetName = 0x00416850;

            // CPlayer *__thiscall CAttachable::GetPlayer(CAttachable *this)
            const unsigned int CAttachable__GetPlayer = 0x00414410;

            // GatePlayer **__thiscall GatePlayer::GetNextPlayer(GatePlayer *this)
            const unsigned int GatePlayer__GetNextPlayer = 0x004B5640;
        }

        namespace GAMESERVER_138
        {
            // GameServerApp *g_gmsvr
            const unsigned int g_gmsvr = 0x0077984C;

            // bool GameServerApp::SendToClient(WPacket& pkt, GatePlayer* playerlist)
            const unsigned int GameServerApp__SendToClient = 0x00513070;

            // CSkillStateRecord* GetCSkillStateRecordInfo( int nTypeID )
            const unsigned int GetCSkillStateRecordInfo = 0x00499C20;

            // void CFightAble::SetDie(CCharacter *pCSkillSrcCha)
            const unsigned int CFightAble__SetDie = 0x005036E0;

            // void CFightAble::OnSkillState(DWORD dwCurTick)
            const unsigned int CFightAble__OnSkillState = 0x005093A0;

            // void CFightAble::SkillTarEffect(SFireUnit *pSFireSrc)
            const unsigned int CFightAble__SkillTarEffect = 0x00503150;

            // void CFightAble::RangeEffect(SFireUnit *pSFireSrc, SubMap *pCMap, Long *plRangeBParam)
            const unsigned int CFightAble__RangeEffect = 0x00506630;

            // bool CCharacter::AddSkillState(uChar uchFightID, uLong ulSrcWorldID, Long lSrcHandle, Char chObjType, Char chObjHabitat, Char chEffType,
            //    uChar uchStateID, uChar uchStateLv, Long lOnTick, dbc::Char chType, bool bNotice)
            const unsigned int CCharacter__AddSkillState = 0x004D1490;

            // dbc::Long CFightAble::getAttr(int nIdx)
            const unsigned int CFightAble__getAttr = 0x00401390;

            // char *__thiscall Entity::GetName(Entity *this)
            const unsigned int Entity__GetName = 0x00421600;

            // bool CCharacter::IsPlayerOwnCha()
            const unsigned int CCharacter__IsPlayerOwnCha = 0x004C3C70;

            // SItemGrid *__thiscall CCharacter::GetEquipItem(CCharacter *this, char chPart)
            const unsigned int CCharacter__GetEquipItem = 0x004C5090;

            // dbc::Long CCharacter::GetSideID()
            const unsigned int CCharacter__GetSideID = 0x0041B250;

            // DWORD CCharacter::GetGuildID()
            const unsigned int CCharacter__GetGuildID = 0x004D7BB0;

            // DWORD CPlayer::getTeamLeaderID()
            const unsigned int CPlayer__getTeamLeaderID = 0x00415740;

            // SubMap *__thiscall Entity::GetSubMap(Entity *this)
            const unsigned int Entity__GetSubMap = 0x00417A50;

            // dbc::Long CPlayer::GetID(void)
            const unsigned CPlayer__GetID = 0x00415850;
        
            // dbc::TcpCommApp
            const unsigned int TcpCommApp = 0x0077984C;

            // WPacket TcpCommApp::GetWPacket() const
            const unsigned int TcpCommApp__GetWPacket = 0x00529CE0;

            // WPacket::WPacket(const WPacket&)
            const unsigned int WPacket__WPacketCopyCtor = 0x0041DBD0;

            // WPacket::~WPacket
            const unsigned int WPacket__WPacketDtor = 0x0041DC60;

            // WPacket& operator=(const WPacket&)
            const unsigned int WPacket__operator_equal = 0x00524050;

            // bool WPacket::WriteCmd(uShort cmd)
            const unsigned int WPacket__WriteCmd = 0x00523A40;

            // bool WPacket::WriteLong(uLong value)
            const unsigned int WPacket__WriteLong = 0x00524C40;

            // bool WPacket::WriteString(cChar *str)
            const unsigned int WPacket__WriteString = 0x00524E60;

            // void SubMap::Add(Entity* pCEnt)
            const unsigned int SubMap__Add = 0x004BD130;

            // void SubMap::Delete(Entity* pCEnt)
            const unsigned int SubMap__Delete = 0x004BD730;

            // const char* SubMap::GetName(void)
            const unsigned int SubMap__GetName = 0x00417A70;

            // CPlayer *__thiscall CAttachable::GetPlayer(CAttachable *this)
            const unsigned int CAttachable__GetPlayer = 0x00415630;

            // GatePlayer *__thiscall GatePlayer::GetNextPlayer(GatePlayer *this)
            const unsigned int GatePlayer__GetNextPlayer = 0x004BCBB0;
        }
	}
}