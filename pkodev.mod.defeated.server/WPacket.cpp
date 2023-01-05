#include <memory>

#include "address.h"
#include "import.h"
#include "WPacket.h"

namespace pkodev {

	WPacket::WPacket(unsigned short int packetId) :
		m_this{0x00}
	{
		import::TcpCommApp__GetWPacket(
			reinterpret_cast<void*>(*reinterpret_cast<unsigned int*>(address::MOD_EXE_VERSION::TcpCommApp)),
			reinterpret_cast<void*>(m_this)
		);

		if (packetId != 0) {
			import::WPacket__WriteCmd(reinterpret_cast<void*>(m_this), packetId);
		}
	}

	WPacket::~WPacket()
	{
		import::WPacket__WPacketDtor(reinterpret_cast<void*>(m_this));
	}

	WPacket::WPacket(const WPacket& other) :
		m_this{ 0x00 }
	{
		import::WPacket__WPacketCopyCtor( reinterpret_cast<void*>(m_this),
			reinterpret_cast<void*>(other.m_this) );
	}

	WPacket::WPacket(WPacket&& other) noexcept
	{
		std::memcpy(reinterpret_cast<void*>(m_this),
			reinterpret_cast<const void*>(other.m_this), sizeof(m_this));
		std::memset(reinterpret_cast<void*>(other.m_this), 0x00, sizeof(other.m_this));
	}

	WPacket& WPacket::operator=(const WPacket& other)
	{
		if (this != &other) {
			import::WPacket__operator_equal( reinterpret_cast<void*>(m_this),
				reinterpret_cast<void*>(other.m_this) );
		}
		return *this;
	}

	WPacket& WPacket::operator=(WPacket&& other) noexcept
	{
		std::memcpy(reinterpret_cast<void*>(m_this),
			reinterpret_cast<const void*>(other.m_this), sizeof(m_this));
		std::memset(reinterpret_cast<void*>(other.m_this), 0x00, sizeof(other.m_this));

		return *this;
	}

	void WPacket::WriteCmd(unsigned short int packetId)
	{
		import::WPacket__WriteCmd(reinterpret_cast<void*>(m_this), packetId);
	}

	void WPacket::WriteLong(unsigned int value)
	{
		import::WPacket__WriteLong(reinterpret_cast<void*>(m_this), value);
	}

	void WPacket::WriteString(const std::string& str)
	{
		import::WPacket__WriteString(reinterpret_cast<void*>(m_this), str.c_str());
	}

	WPacket& WPacket::operator<<(unsigned int value)
	{
		import::WPacket__WriteLong(reinterpret_cast<void*>(m_this), value);
		return *this;
	}

	WPacket& WPacket::operator<<(const std::string& str)
	{
		import::WPacket__WriteString(reinterpret_cast<void*>(m_this), str.c_str());
		return *this;
	}

}