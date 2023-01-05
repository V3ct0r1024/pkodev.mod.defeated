#pragma once
#include <string>

namespace pkodev {

	class RPacket final
	{
		public:
			RPacket() = default;
			~RPacket() = default;

			unsigned short int ReadCmd() const;
			unsigned int ReadLong() const;
			std::string ReadString() const;

			const RPacket& operator>>(int& val) const;
			const RPacket& operator>>(unsigned int& val) const;
			const RPacket& operator>>(std::string& str) const;

		private:
			void* m_this;

	};

}

