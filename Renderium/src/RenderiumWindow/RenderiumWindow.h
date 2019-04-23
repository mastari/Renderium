#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "../ClientDevice/ClientDevice.h"

class RenderiumWindow {
public:
	RenderiumWindow(std::string name, GLint width, GLint height, bool resizable);
	GLFWwindow* getContext();
	GLint getWidth();
	GLint getHeight();
	std::string getTitle();
private:
	GLint windowWidth, windowHeight;
	std::string windowTitle;
	bool windowIsResizable;
	GLFWwindow* contextWindow;
	static int netWindows;
};
