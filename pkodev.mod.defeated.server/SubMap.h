#pragma once
#include <string>

namespace pkodev {

	class SubMap final
	{
		public:
			SubMap();
			~SubMap() = default;

			std::string GetName() const;

		private:
			void* m_this;
	};

}

