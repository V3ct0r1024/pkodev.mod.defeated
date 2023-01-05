#include "address.h"
#include "import.h"

namespace pkodev {

	import::UIRender__SetScreen__Ptr import::UIRender__SetScreen = reinterpret_cast<import::UIRender__SetScreen__Ptr>(reinterpret_cast<unsigned int*>(address::MOD_EXE_VERSION::UIRender__SetScreen));
	import::RenderHintFrame__Ptr import::RenderHintFrame = reinterpret_cast<import::RenderHintFrame__Ptr>(reinterpret_cast<unsigned int*>(address::MOD_EXE_VERSION::RenderHintFrame));
	import::CGuiFont_BRender_Ptr import::CGuiFont_BRender = reinterpret_cast<import::CGuiFont_BRender_Ptr>(reinterpret_cast<void*>(address::MOD_EXE_VERSION::CGuiFont__BRender));
	import::CMPFont__GetTextSize__Ptr import::CMPFont__GetTextSize = reinterpret_cast<import::CMPFont__GetTextSize__Ptr>(*reinterpret_cast<unsigned int*>(address::MOD_EXE_VERSION::CMPFont__GetTextSize));
	import::CGuiPic__CGuiPic__Ptr import::CGuiPic__CGuiPic = reinterpret_cast<import::CGuiPic__CGuiPic__Ptr>(reinterpret_cast<void*>(address::MOD_EXE_VERSION::CGuiPic__CGuiPic));
	import::CGuiPic__LoadImage__Ptr import::CGuiPic__LoadImage = reinterpret_cast<import::CGuiPic__LoadImage__Ptr>(reinterpret_cast<void*>(address::MOD_EXE_VERSION::CGuiPic__LoadImage));
	import::CGuiPic__UnloadImage__Ptr import::CGuiPic__UnloadImage = reinterpret_cast<import::CGuiPic__UnloadImage__Ptr>(reinterpret_cast<void*>(address::MOD_EXE_VERSION::CGuiPic__UnloadImage));
	import::CGuiPic__Render__Ptr import::CGuiPic__Render = reinterpret_cast<import::CGuiPic__Render__Ptr>(reinterpret_cast<void*>(address::MOD_EXE_VERSION::CGuiPic__Render));
	import::operator_delete_array_Ptr import::operator_delete_array = reinterpret_cast<import::operator_delete_array_Ptr>(reinterpret_cast<void*>(address::MOD_EXE_VERSION::operator_delete_array));
	import::CWorldScene___Render__Ptr import::CWorldScene___Render = reinterpret_cast<import::CWorldScene___Render__Ptr>(reinterpret_cast<unsigned int*>(address::MOD_EXE_VERSION::CWorldScene___Render));
	import::CWorldScene___FrameMove__Ptr import::CWorldScene___FrameMove = reinterpret_cast<import::CWorldScene___FrameMove__Ptr>(reinterpret_cast<unsigned int*>(address::MOD_EXE_VERSION::CWorldScene___FrameMove));
	import::NetIF__HandlePacketMessage__Ptr import::NetIF__HandlePacketMessage = reinterpret_cast<import::NetIF__HandlePacketMessage__Ptr>(reinterpret_cast<unsigned int*>(address::MOD_EXE_VERSION::NetIF__HandlePacketMessage));
	import::RPacket__ReadCmd__Ptr import::RPacket__ReadCmd = reinterpret_cast<import::RPacket__ReadCmd__Ptr>(reinterpret_cast<void*>(address::MOD_EXE_VERSION::RPacket__ReadCmd));
	import::RPacket__ReadLong__Ptr import::RPacket__ReadLong = reinterpret_cast<import::RPacket__ReadLong__Ptr>(reinterpret_cast<void*>(address::MOD_EXE_VERSION::RPacket__ReadLong));
	import::RPacket__ReadString__Ptr import::RPacket__ReadString = reinterpret_cast<import::RPacket__ReadString__Ptr>(reinterpret_cast<void*>(address::MOD_EXE_VERSION::RPacket__ReadString));
	import::GetSkillRecordInfo__Ptr import::GetSkillRecordInfo = reinterpret_cast<import::GetSkillRecordInfo__Ptr>(reinterpret_cast<void*>(address::MOD_EXE_VERSION::GetSkillRecordInfo));
	import::GetItemRecordInfo__Ptr import::GetItemRecordInfo = reinterpret_cast<import::GetItemRecordInfo__Ptr>(reinterpret_cast<void*>(address::MOD_EXE_VERSION::GetItemRecordInfo));

}