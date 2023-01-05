#include "address.h"
#include "import.h"
#include "GameServerApp.h"

namespace pkodev {

	GameServerApp& GameServerApp::Instance()
	{
		static GameServerApp app;
		return app;
	}

	GameServerApp::GameServerApp()
	{
		g_gmsvr = reinterpret_cast<void*>(
			*reinterpret_cast<unsigned int*>(address::MOD_EXE_VERSION::g_gmsvr)
		);
	}

	bool GameServerApp::SendToClient(const WPacket& pkt, void* playerlist)
	{
		return import::GameServerApp__SendToClient(g_gmsvr, pkt.m_this, playerlist);
	}

}