#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "../ClientDevice/ClientDevice.h"

class RenderiumWindow {
public:
	RenderiumWindow(const char* name, GLint width, GLint height, bool resizable);
	GLFWwindow* getContext();
	GLint getWidth();
	GLint getHeight();
	const char* getTitle();
private:
	GLint windowWidth, windowHeight;
	const char* windowTitle;
	bool windowIsResizable;
	GLFWwindow* contextWindow;
	static int netWindows;
};
