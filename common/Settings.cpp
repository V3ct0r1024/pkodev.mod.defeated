#include <iostream>
#include <fstream>

#include "Settings.h"

namespace pkodev {

	bool CSettings::Load(const std::string& path)
	{
        std::ifstream jsonFile(path);
        if (jsonFile.is_open() == false) {
            std::cerr << "> Can't open JSON file with settings '"
                << path << "'!" << std::endl;
            return false;
        }

        try {
            ParseSettings( json::parse(jsonFile) );
            return true;
        }
        catch (const json::exception& e) {
            std::cerr << "> Failed to parse JSON file with settings '"
                << path << "'!" << std::endl
                << "> Error message: '" << e.what() << "'" << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "> Invalid settings file '" << path << "'!"
                << std::endl << "> Error message: '" << e.what() << "'" << std::endl;
        }

        return false;
	}

}