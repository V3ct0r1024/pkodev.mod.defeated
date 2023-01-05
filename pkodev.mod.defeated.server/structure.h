#pragma once
#include "Character.h"

namespace pkodev {

    struct CSkillRecord final {
        char nop0[0x04];
        short int sID;
    };

    struct CSkillTData final {
        char nop0[0x24];
        short int sStateParam[3];
    };

    struct SFireSrc final {
        char nop0[0x08];
        CCharacter* pCFightSrc;
        char nop1[0x18];
        CSkillRecord* pCSkillRecord;
        CSkillTData* pCSkillTData;
    };
}