#include "address.h"
#include "import.h"

namespace pkodev {
	
	import::GameServerApp__SendToClient__Ptr import::GameServerApp__SendToClient = reinterpret_cast<import::GameServerApp__SendToClient__Ptr>(reinterpret_cast<unsigned int*>(address::MOD_EXE_VERSION::GameServerApp__SendToClient));
	import::GetCSkillStateRecordInfo__Ptr import::GetCSkillStateRecordInfo = reinterpret_cast<import::GetCSkillStateRecordInfo__Ptr>(reinterpret_cast<unsigned int*>(address::MOD_EXE_VERSION::GetCSkillStateRecordInfo));
	import::CFightAble__SetDie__Ptr import::CFightAble__SetDie = reinterpret_cast<import::CFightAble__SetDie__Ptr>(reinterpret_cast<unsigned int*>(address::MOD_EXE_VERSION::CFightAble__SetDie));
	import::CFightAble__OnSkillState__Ptr import::CFightAble__OnSkillState = reinterpret_cast<import::CFightAble__OnSkillState__Ptr>(reinterpret_cast<unsigned int*>(address::MOD_EXE_VERSION::CFightAble__OnSkillState));
	import::CFightAble__SkillTarEffect__Ptr import::CFightAble__SkillTarEffect = reinterpret_cast<import::CFightAble__SkillTarEffect__Ptr>(reinterpret_cast<unsigned int*>(address::MOD_EXE_VERSION::CFightAble__SkillTarEffect));
	import::CFightAble__RangeEffect__Ptr import::CFightAble__RangeEffect = reinterpret_cast<import::CFightAble__RangeEffect__Ptr>(reinterpret_cast<unsigned int*>(address::MOD_EXE_VERSION::CFightAble__RangeEffect));
	import::CCharacter__AddSkillState__Ptr import::CCharacter__AddSkillState = reinterpret_cast<import::CCharacter__AddSkillState__Ptr>(reinterpret_cast<unsigned int*>(address::MOD_EXE_VERSION::CCharacter__AddSkillState));
	import::CFightAble__getAttr__Ptr import::CFightAble__getAttr = reinterpret_cast<import::CFightAble__getAttr__Ptr>(reinterpret_cast<unsigned int*>(address::MOD_EXE_VERSION::CFightAble__getAttr));
	import::Entity__GetName__Ptr import::Entity__GetName = reinterpret_cast<import::Entity__GetName__Ptr>(reinterpret_cast<unsigned int*>(address::MOD_EXE_VERSION::Entity__GetName));
	import::CCharacter__IsPlayerOwnCha__Ptr import::CCharacter__IsPlayerOwnCha = reinterpret_cast<import::CCharacter__IsPlayerOwnCha__Ptr>(reinterpret_cast<unsigned int*>(address::MOD_EXE_VERSION::CCharacter__IsPlayerOwnCha));
	import::CCharacter__GetEquipItem__Ptr import::CCharacter__GetEquipItem = reinterpret_cast<import::CCharacter__GetEquipItem__Ptr>(reinterpret_cast<unsigned int*>(address::MOD_EXE_VERSION::CCharacter__GetEquipItem));
	import::CCharacter__GetSideID__Ptr import::CCharacter__GetSideID = reinterpret_cast<import::CCharacter__GetSideID__Ptr>(reinterpret_cast<unsigned int*>(address::MOD_EXE_VERSION::CCharacter__GetSideID));
	import::CCharacter__GetGuildID__Ptr import::CCharacter__GetGuildID = reinterpret_cast<import::CCharacter__GetGuildID__Ptr>(reinterpret_cast<unsigned int*>(address::MOD_EXE_VERSION::CCharacter__GetGuildID));
	import::CPlayer__getTeamLeaderID__Ptr import::CPlayer__getTeamLeaderID = reinterpret_cast<import::CPlayer__getTeamLeaderID__Ptr>(reinterpret_cast<unsigned int*>(address::MOD_EXE_VERSION::CPlayer__getTeamLeaderID));
	import::Entity__GetSubMap__Ptr import::Entity__GetSubMap = reinterpret_cast<import::Entity__GetSubMap__Ptr>(reinterpret_cast<unsigned int*>(address::MOD_EXE_VERSION::Entity__GetSubMap));
	import::CPlayer__GetID__Ptr import::CPlayer__GetID = reinterpret_cast<import::CPlayer__GetID__Ptr>(reinterpret_cast<unsigned int*>(address::MOD_EXE_VERSION::CPlayer__GetID));
	import::TcpCommApp__GetWPacket__Ptr import::TcpCommApp__GetWPacket = reinterpret_cast<import::TcpCommApp__GetWPacket__Ptr>(reinterpret_cast<unsigned int*>(address::MOD_EXE_VERSION::TcpCommApp__GetWPacket));
	import::WPacket__WPacketCopyCtor__Ptr import::WPacket__WPacketCopyCtor = reinterpret_cast<import::WPacket__WPacketCopyCtor__Ptr>(reinterpret_cast<unsigned int*>(address::MOD_EXE_VERSION::WPacket__WPacketCopyCtor));
	import::WPacket__WPacketDtor__Ptr import::WPacket__WPacketDtor = reinterpret_cast<import::WPacket__WPacketDtor__Ptr>(reinterpret_cast<unsigned int*>(address::MOD_EXE_VERSION::WPacket__WPacketDtor));
	import::WPacket__operator_equal__Ptr import::WPacket__operator_equal = reinterpret_cast<import::WPacket__operator_equal__Ptr>(reinterpret_cast<unsigned int*>(address::MOD_EXE_VERSION::WPacket__operator_equal));
	import::WPacket__WriteCmd__Ptr import::WPacket__WriteCmd = reinterpret_cast<import::WPacket__WriteCmd__Ptr>(reinterpret_cast<unsigned int*>(address::MOD_EXE_VERSION::WPacket__WriteCmd));
	import::WPacket__WriteLong__Ptr import::WPacket__WriteLong = reinterpret_cast<import::WPacket__WriteLong__Ptr>(reinterpret_cast<unsigned int*>(address::MOD_EXE_VERSION::WPacket__WriteLong));
	import::WPacket__WriteString__Ptr import::WPacket__WriteString = reinterpret_cast<import::WPacket__WriteString__Ptr>(reinterpret_cast<unsigned int*>(address::MOD_EXE_VERSION::WPacket__WriteString));
	import::SubMap__Add__Ptr import::SubMap__Add = reinterpret_cast<import::SubMap__Add__Ptr>(reinterpret_cast<unsigned int*>(address::MOD_EXE_VERSION::SubMap__Add));
	import::SubMap__Delete__Ptr import::SubMap__Delete = reinterpret_cast<import::SubMap__Delete__Ptr>(reinterpret_cast<unsigned int*>(address::MOD_EXE_VERSION::SubMap__Delete));
	import::SubMap__GetName__Ptr import::SubMap__GetName = reinterpret_cast<import::SubMap__GetName__Ptr>(reinterpret_cast<unsigned int*>(address::MOD_EXE_VERSION::SubMap__GetName));
	import::CAttachable__GetPlayer__Ptr import::CAttachable__GetPlayer = reinterpret_cast<import::CAttachable__GetPlayer__Ptr>(reinterpret_cast<unsigned int*>(address::MOD_EXE_VERSION::CAttachable__GetPlayer));
	import::GatePlayer__GetNextPlayer__Ptr import::GatePlayer__GetNextPlayer = reinterpret_cast<import::GatePlayer__GetNextPlayer__Ptr>(reinterpret_cast<unsigned int*>(address::MOD_EXE_VERSION::GatePlayer__GetNextPlayer));

}