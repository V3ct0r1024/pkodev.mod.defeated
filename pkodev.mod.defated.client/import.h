#pragma once
#include "structure.h"
#include "RPacket.h"

namespace pkodev {

	class import final
	{
		public:

			typedef void(__thiscall* UIRender__SetScreen__Ptr)(void*, int, int, bool);
			static UIRender__SetScreen__Ptr UIRender__SetScreen;

			typedef BOOL(__cdecl* RenderHintFrame__Ptr)(const RECT* rc, DWORD color);
			static RenderHintFrame__Ptr RenderHintFrame;

			typedef void(__thiscall* CGuiFont_BRender_Ptr)(void*, unsigned int, const char*, int, int, int, int);
			static CGuiFont_BRender_Ptr CGuiFont_BRender;

			typedef Vector2D<int>* (__thiscall* CMPFont__GetTextSize__Ptr)(void*, char*, Vector2D<unsigned int>*, float);
			static CMPFont__GetTextSize__Ptr CMPFont__GetTextSize;

			typedef void(__thiscall* CGuiPic__CGuiPic__Ptr)(void*, void*, unsigned int);
			static CGuiPic__CGuiPic__Ptr CGuiPic__CGuiPic;

			typedef bool(__thiscall* CGuiPic__LoadImage__Ptr)(void*, const char*, int, int, int, int, int, float, float);
			static CGuiPic__LoadImage__Ptr CGuiPic__LoadImage;

			typedef void(__thiscall* CGuiPic__Render__Ptr)(void*, int, int, int);
			static CGuiPic__Render__Ptr CGuiPic__Render;

			typedef void(__thiscall* CGuiPic__UnloadImage__Ptr)(void*, int);
			static CGuiPic__UnloadImage__Ptr CGuiPic__UnloadImage;

			typedef int(__cdecl* operator_delete_array_Ptr)(void*);
			static operator_delete_array_Ptr operator_delete_array;

			typedef void(__thiscall* CWorldScene___Render__Ptr)(void*);
			static CWorldScene___Render__Ptr CWorldScene___Render;

			typedef void(__thiscall* CWorldScene___FrameMove__Ptr)(void*, DWORD);
			static CWorldScene___FrameMove__Ptr CWorldScene___FrameMove;

			typedef bool(__thiscall* NetIF__HandlePacketMessage__Ptr)(void*, void*, const RPacket*);
			static NetIF__HandlePacketMessage__Ptr NetIF__HandlePacketMessage;

			typedef unsigned short int(__thiscall* RPacket__ReadCmd__Ptr)(const RPacket*);
			static RPacket__ReadCmd__Ptr RPacket__ReadCmd;
			
			typedef unsigned int(__thiscall* RPacket__ReadLong__Ptr)(const RPacket*);
			static RPacket__ReadLong__Ptr RPacket__ReadLong;

			typedef const char* (__thiscall* RPacket__ReadString__Ptr)(const RPacket*, unsigned short int*);
			static RPacket__ReadString__Ptr RPacket__ReadString;

			typedef CSkillRecord* (__cdecl* GetSkillRecordInfo__Ptr)(int);
			static GetSkillRecordInfo__Ptr GetSkillRecordInfo;

			typedef CItemRecord* (__cdecl* GetItemRecordInfo__Ptr)(int);
			static GetItemRecordInfo__Ptr GetItemRecordInfo;

	};

}

