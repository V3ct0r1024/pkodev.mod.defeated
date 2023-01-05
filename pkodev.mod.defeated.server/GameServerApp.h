#pragma once
#include "WPacket.h"

namespace pkodev {

	class GameServerApp final
	{
		public:
			static GameServerApp& Instance();
			bool SendToClient(const WPacket& pkt, void* playerlist);

		private:
			GameServerApp();
			~GameServerApp() = default;
			GameServerApp(const GameServerApp&) = delete;
			GameServerApp& operator= (const GameServerApp&) = delete;
			GameServerApp(GameServerApp&&) = delete;
			GameServerApp& operator=(GameServerApp&&) = delete;

			void* g_gmsvr;
	};

}
