#pragma once
#include "../../../Engine/OpenGL/OpenGL.h"
#include "../../../External Libraries/STB_Image/stb_image.h"
#include <iostream>

class Texture {
public:
	Texture();
	Texture(const char* path, int wrap, int filter);
	void bind();
	void unbind();
	unsigned int getID();

private:
	unsigned int ID;
	int width, height, nrChannels;
};