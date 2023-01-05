#include "import.h"
#include "Player.h"

namespace pkodev {

	CPlayer::CPlayer() :
		m_this(nullptr)
	{

	}

	CPlayer*& CPlayer::GetNextPlayer()
	{
		return import::GatePlayer__GetNextPlayer(this);
	}

	int CPlayer::getTeamLeaderID() const
	{
		if (m_this != nullptr) {
			return import::CPlayer__getTeamLeaderID(this);
		}
		return 0;
	}

	int CPlayer::GetID() const
	{
		if (m_this != nullptr) {
			return import::CPlayer__GetID(this);
		}
		return 0;
	}
}