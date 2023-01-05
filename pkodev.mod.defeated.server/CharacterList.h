#pragma once
#include <string>
#include <unordered_set>
#include <unordered_map>

#include "Character.h"
#include "WPacket.h"

namespace pkodev {

	class CCharacterList
	{
		public:

			using Characters = std::unordered_set<CCharacter*>;
			using MapToCharacters = std::unordered_map<std::string, Characters>;
			

			CCharacterList() = default;
			~CCharacterList() = default;

			void AddCharacter(const std::string& mapName, CCharacter* character);
			void RemoveCharacter(const std::string& mapName, CCharacter* character);

			void SendPacket(const std::string& mapName, const WPacket& pkt);

		private:
			MapToCharacters m_characters;
	};

}

