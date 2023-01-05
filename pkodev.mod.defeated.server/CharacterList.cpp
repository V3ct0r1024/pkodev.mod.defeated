#include "CharacterList.h"
#include "GameServerApp.h"

namespace pkodev {

	void CCharacterList::AddCharacter(const std::string& mapName, CCharacter* character)
	{
		m_characters[mapName].insert(character);
	}

	void CCharacterList::RemoveCharacter(const std::string& mapName, CCharacter* character)
	{
		m_characters[mapName].erase(character);
	}

	void CCharacterList::SendPacket(const std::string& mapName, const WPacket& pkt)
	{
		if (m_characters.count(mapName) == 0) {
			return;
		}

		if (m_characters[mapName].empty() == true) {
			return;
		}

		CPlayer* pHeadPlayer = nullptr, * pLastPlayer = nullptr;
		for (auto& ply : m_characters[mapName]) {
			if (pHeadPlayer == nullptr) {
				pHeadPlayer = ply->GetPlayer();
				pLastPlayer = pHeadPlayer;
			}
			else {
				pLastPlayer->GetNextPlayer() = ply->GetPlayer();
				pLastPlayer = pLastPlayer->GetNextPlayer();
			}
		}

		if (pLastPlayer != nullptr) {
			pLastPlayer->GetNextPlayer() = nullptr;
		}

		GameServerApp::Instance().SendToClient(pkt, pHeadPlayer);
	}

}