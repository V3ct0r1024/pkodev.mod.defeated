#include "import.h"
#include "Character.h"


namespace pkodev {

	CCharacter::CCharacter() :
		m_this(nullptr)
	{

	}

	std::string CCharacter::GetName() const
	{
		if (m_this != nullptr) {
			return import::Entity__GetName(this);
		}
		return { "" };
	}

	int CCharacter::GetAttr(int attrId) const
	{
		if (m_this != nullptr) {
			return import::CFightAble__getAttr(this, attrId);
		}
		return 0;
	}

	bool CCharacter::IsPlayerOwnCha() const
	{
		if (m_this != nullptr) {
			return import::CCharacter__IsPlayerOwnCha(this);
		}
		return false;
	}

	CPlayer* CCharacter::GetPlayer() const
	{
		if (m_this != nullptr) {
			return import::CAttachable__GetPlayer(this);
		}
		return nullptr;
	}

	const SItemGrid* CCharacter::GetEquipItem(short int id) const
	{
		if (m_this != nullptr) {
			return import::CCharacter__GetEquipItem(this, static_cast<char>(id));
		}
		return nullptr;
	}

	int CCharacter::GetSideID() const
	{
		if (m_this != nullptr) {
			return import::CCharacter__GetSideID(this);
		}
		return 0;
	}

	int CCharacter::GetGuildID() const
	{
		if (m_this != nullptr) {
			return import::CCharacter__GetGuildID(this);
		}
		return 0;
	}

	const SubMap* CCharacter::GetSubMap() const
	{
		if (m_this != nullptr) {
			return import::Entity__GetSubMap(this);
		}
		return nullptr;
	}

}