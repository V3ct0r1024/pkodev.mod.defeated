#pragma once
#include <Windows.h>
#include <string>

#include "address.h"
#include "Utils.h"

namespace pkodev {

	template<typename T>
	struct Vector2D {
		T x;
		T y;
	};

	struct CSkillRecord final {
		const char nop0[0x324];
		const char szIcon[17];
	};

	struct CItemRecord final {
		const char nop0[0x04];
		const int id;
		const char name[72];
		const char nop1[0x70];
		const char icon[17];
	};

    struct CharacterSide final {
		int chaId{ 0 };
        int sideId{ 0 };
        int partyId{ 0 };
        int guildId{ 0 };

        bool operator==(const CharacterSide& rhs) const 
		{
			if (chaId == rhs.chaId) {
				return true;
			}

            if ( (partyId != 0) && (partyId == rhs.partyId) ) {
                return true;
            }

            if ( (sideId != 0) && (sideId == rhs.sideId) ) {
                return true;
            }

            if ( (guildId != 0) && (guildId == rhs.guildId) ) {
                return true;
            }

            return false;
        }

        bool operator!=(const CharacterSide& rhs) const 
		{
            return ( (*this == rhs) == false );
        }
    };

	struct CCharacter final {
		const char nop0[0xD4];
		const int hp;
		const char nop1[0x5c];
		const int unknown0;
		const char nop2[0x14];
		const int max_hp;
		const char nop3[0x02cc];
		const char name[0x21];
		const char nop4[0xA7];
		const int  guild_id;
		const int  guild_color;
		const char nop5[0x003c];
		const int  side_id;
		const char nop6[4];
		const void* pStateMgr;
		const char nop7[0x2c];
		const int area_type;
		const char nop8[0x03fa];
		const short int ring_id;
		const char nop9[0x01E4];
		const short int neck_id;
		const char nop10[0x0156];
		const int  party_id;
		const char nop11[0x0038];
		const int type;
		const char nop12[0x08];
		const int cha_id;

		static CCharacter* Main() {
			return Utils::Get<CCharacter*>(address::MOD_EXE_VERSION::CGameScene___pMainCha);
		}

		CharacterSide GetSide() const {
			return { cha_id, side_id, party_id, guild_id };
		}
	};

}