#pragma once
#include <iostream>
#include <fstream>
#include <string>

class FileReader {
public:
	static const char* readFromPath(std::string path);
private:
	FileReader();
};