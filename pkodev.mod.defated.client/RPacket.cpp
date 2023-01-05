#include "import.h"
#include "RPacket.h"

namespace pkodev {

	unsigned short int RPacket::ReadCmd() const
	{
		return import::RPacket__ReadCmd(this);
	}

	unsigned int RPacket::ReadLong() const
	{
		return import::RPacket__ReadLong(this);
	}

	std::string RPacket::ReadString() const
	{
		return import::RPacket__ReadString(this, nullptr);
	}

	const RPacket& RPacket::operator>>(int& val) const
	{
		val = static_cast<int>(import::RPacket__ReadLong(this));
		return *this;
	}

	const RPacket& RPacket::RPacket::operator>>(unsigned int& val) const
	{
		val = import::RPacket__ReadLong(this);
		return *this;
	}

	const RPacket& RPacket::operator>>(std::string& str) const
	{
		str = import::RPacket__ReadString(this, nullptr);
		return *this;
	}

}