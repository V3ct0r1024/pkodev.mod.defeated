#pragma once

namespace pkodev {

	class CPlayer
	{
		public:
			CPlayer();
			~CPlayer() = default;

			CPlayer*& GetNextPlayer();
			
			int getTeamLeaderID() const;
			int GetID() const;

		private:
			void* m_this;
	};

}

