#include "import.h"
#include "SubMap.h"

namespace pkodev {

	SubMap::SubMap() :
		m_this(nullptr)
	{

	}

	std::string SubMap::GetName() const
	{
		if (m_this != nullptr) {
			return import::SubMap__GetName(this);
		}
		return { "" };
	}

}