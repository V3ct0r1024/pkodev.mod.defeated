#pragma once

namespace pkodev {

	class WPacket final
	{
		friend class GameServerApp;
		friend class GroupServerApp;

		public:
			WPacket(unsigned short int packetId = 0);
			~WPacket();

			WPacket(const WPacket& other);
			WPacket(WPacket&& other) noexcept;
			WPacket& operator=(const WPacket& other);
			WPacket& operator=(WPacket&& other) noexcept;

			void WriteCmd(unsigned short int packetId);
			void WriteLong(unsigned int value);
			void WriteString(const std::string& str);

			WPacket& operator<<(unsigned int value);
			WPacket& operator<<(const std::string& str);

		private:
			mutable char m_this[0x38];
	};

}

