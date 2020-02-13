#pragma once

#include <string>

class IXmlParser {
	virtual void load(const std::string& filePath) = 0;
};
