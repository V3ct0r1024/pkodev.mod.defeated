#pragma once
#include <Windows.h>

#include "structure.h"

#include "Character.h"
#include "Player.h"
#include "SubMap.h"

namespace pkodev {

	class import final
	{
		public:

			typedef bool (__thiscall* GameServerApp__SendToClient__Ptr)(void*, void*, void*);
			static GameServerApp__SendToClient__Ptr GameServerApp__SendToClient;

			typedef void*(__cdecl* GetCSkillStateRecordInfo__Ptr)(int);
			static GetCSkillStateRecordInfo__Ptr GetCSkillStateRecordInfo;

			typedef void(__thiscall* CFightAble__SetDie__Ptr)(CCharacter*, CCharacter*);
			static CFightAble__SetDie__Ptr CFightAble__SetDie;

			typedef void(__thiscall* CFightAble__OnSkillState__Ptr)(CCharacter*, DWORD);
			static CFightAble__OnSkillState__Ptr CFightAble__OnSkillState;

			typedef void(__thiscall* CFightAble__SkillTarEffect__Ptr)(CCharacter*, SFireSrc*);
			static CFightAble__SkillTarEffect__Ptr CFightAble__SkillTarEffect;

			typedef void(__thiscall* CFightAble__RangeEffect__Ptr)(CCharacter*, SFireSrc*, void*, int*);
			static CFightAble__RangeEffect__Ptr CFightAble__RangeEffect;
			
			typedef bool(__thiscall* CCharacter__AddSkillState__Ptr)(CCharacter*, unsigned char, unsigned int,
				int, char, char, char, unsigned char, unsigned char, int, char, bool);
			static CCharacter__AddSkillState__Ptr CCharacter__AddSkillState;

			typedef int(__thiscall* CFightAble__getAttr__Ptr)(const CCharacter*, int);
			static CFightAble__getAttr__Ptr CFightAble__getAttr;

			typedef const char* (__thiscall* Entity__GetName__Ptr)(const CCharacter*);
			static Entity__GetName__Ptr Entity__GetName;

			typedef bool(__thiscall* CCharacter__IsPlayerOwnCha__Ptr)(const CCharacter*);
			static CCharacter__IsPlayerOwnCha__Ptr CCharacter__IsPlayerOwnCha;

			typedef SItemGrid* (__thiscall* CCharacter__GetEquipItem__Ptr)(const CCharacter*, char);
			static CCharacter__GetEquipItem__Ptr CCharacter__GetEquipItem;

			typedef int(__thiscall* CCharacter__GetSideID__Ptr)(const CCharacter*);
			static CCharacter__GetSideID__Ptr CCharacter__GetSideID;

			typedef int(__thiscall* CCharacter__GetGuildID__Ptr)(const CCharacter*);
			static CCharacter__GetGuildID__Ptr CCharacter__GetGuildID;

			typedef int(__thiscall* CPlayer__getTeamLeaderID__Ptr)(const CPlayer*);
			static CPlayer__getTeamLeaderID__Ptr CPlayer__getTeamLeaderID;

			typedef SubMap* (__thiscall* Entity__GetSubMap__Ptr)(const CCharacter*);
			static Entity__GetSubMap__Ptr Entity__GetSubMap;

			typedef int(__thiscall* CPlayer__GetID__Ptr)(const CPlayer*);
			static CPlayer__GetID__Ptr CPlayer__GetID;

			typedef int(__thiscall* TcpCommApp__GetWPacket__Ptr)(void*, void*);
			static TcpCommApp__GetWPacket__Ptr TcpCommApp__GetWPacket;
			
			typedef void(__thiscall* WPacket__WPacketCopyCtor__Ptr)(void*, void*);
			static WPacket__WPacketCopyCtor__Ptr WPacket__WPacketCopyCtor;

			typedef void* (__thiscall* WPacket__WPacketDtor__Ptr)(void*);
			static WPacket__WPacketDtor__Ptr WPacket__WPacketDtor;

			typedef void*(__thiscall* WPacket__operator_equal__Ptr)(void*, void*);
			static WPacket__operator_equal__Ptr WPacket__operator_equal;

			typedef bool(__thiscall* WPacket__WriteCmd__Ptr)(void*, unsigned short int);
			static WPacket__WriteCmd__Ptr WPacket__WriteCmd;

			typedef bool(__thiscall* WPacket__WriteLong__Ptr)(void*, unsigned int);
			static WPacket__WriteLong__Ptr WPacket__WriteLong;

			typedef bool(__thiscall* WPacket__WriteString__Ptr)(void*, const char*);
			static WPacket__WriteString__Ptr WPacket__WriteString;

			typedef void(__thiscall* SubMap__Add__Ptr)(const SubMap*, CCharacter*);
			static SubMap__Add__Ptr SubMap__Add;

			typedef void(__thiscall* SubMap__Delete__Ptr)(const SubMap*, CCharacter*);
			static SubMap__Delete__Ptr SubMap__Delete;

			typedef const char* (__thiscall* SubMap__GetName__Ptr)(const SubMap*);
			static SubMap__GetName__Ptr SubMap__GetName;

			typedef CPlayer* (__thiscall* CAttachable__GetPlayer__Ptr)(const CCharacter*);
			static CAttachable__GetPlayer__Ptr CAttachable__GetPlayer;

			typedef CPlayer*& (__thiscall* GatePlayer__GetNextPlayer__Ptr)(CPlayer*);
			static GatePlayer__GetNextPlayer__Ptr GatePlayer__GetNextPlayer;
	};

}

