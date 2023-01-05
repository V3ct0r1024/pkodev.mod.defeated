#pragma once
#include "structure.h"
#include "Character.h"

namespace pkodev { namespace hook {
	
	void* __cdecl GetCSkillStateRecordInfo(int nTypeID);
	void __fastcall CFightAble__SetDie(CCharacter* This, void*, CCharacter* pCSkillSrcCha);
	void __fastcall CFightAble__OnSkillState(CCharacter* This, void*, DWORD dwCurTick);
	void __fastcall CFightAble__SkillTarEffect(CCharacter* This, void*, SFireSrc* pSFireSrc);
	void __fastcall CFightAble__RangeEffect(CCharacter* This, void*, SFireSrc* pSFireSrc, void* pCMap, int* plRangeBParam);
	bool __fastcall CCharacter__AddSkillState(CCharacter* This, void*, unsigned char uchFightID, unsigned int ulSrcWorldID, int lSrcHandle, char chObjType, char chObjHabitat, char chEffType,
		 unsigned char uchStateID, unsigned char uchStateLv, int lOnTick, char chType, bool bNotice);
	void __fastcall SubMap__Add(const SubMap* This, void*, CCharacter* pCEnt);
	void __fastcall SubMap__Delete(const SubMap* This, void*, CCharacter* pCEnt);

}}