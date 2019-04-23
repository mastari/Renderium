#include "FileReader.h"
#pragma warning(disable : 4996)

const char* FileReader::readFromPath(std::string path) {
	std::ifstream ifs(path);
	std::string content((std::istreambuf_iterator<char>(ifs)),
		(std::istreambuf_iterator<char>()));
	char* convert = new char[content.size()];
	std::strncpy(convert, content.c_str(), content.size() + 1);
	return convert;
}