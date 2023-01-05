#pragma once
#include <string>

#include "Player.h"
#include "SubMap.h"

namespace pkodev {

	struct SSkillGrid final {
		char chState{0};
		char chLv{0};
		short int sID{0};
	};

	struct SFightInit final {
		char nop0[0x04]{0x00};
		SSkillGrid* pSSkillGrid{nullptr};
	};

	struct SItemGrid final {
		short int sID;
	};

	class CCharacter final
	{
		public:
			CCharacter();
			~CCharacter() = default;

			std::string GetName() const;
			int GetAttr(int attrId) const;
			bool IsPlayerOwnCha() const;
			CPlayer* GetPlayer() const;

			const SFightInit& GetFightInit() const { return m_SFightInit; }
			const SItemGrid* GetEquipItem(short int id) const;

			int GetSideID() const;
			int GetGuildID() const;

			const SubMap* GetSubMap() const;

		private:
			mutable void* m_this;
			char m_nop0[0x23C]{ 0x00 };
			SFightInit m_SFightInit;
	};
}
