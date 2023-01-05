#pragma once
#include <string>
#include <nlohmann/json.hpp>

namespace pkodev {

	class CSettings
	{
        public:
            CSettings() = default;
            ~CSettings() = default;
            bool Load(const std::string& path);

        protected:
            using json = nlohmann::json;
            virtual void ParseSettings(const json& data) = 0;
	};

}

