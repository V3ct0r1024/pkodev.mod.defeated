#pragma once
#include "structure.h"
#include "RPacket.h"

namespace pkodev { namespace hook {

	void __fastcall UIRender__SetScreen(void* This, void*, int w, int h, bool isFull);
	bool __fastcall NetIF__HandlePacketMessage(void* This, void*, void* datasock, RPacket* pk);
	void __fastcall CWorldScene___FrameMove(void* This, void*, DWORD dwTimeParam);
	void __fastcall CWorldScene___Render(void* This, void*);
	
}}