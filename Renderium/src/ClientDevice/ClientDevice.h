#pragma once
#include "GLFW/glfw3.h"

class ClientDevice {
public:
	static void initClientDevice(GLFWwindow* window);
	static int getScreenWidth();
	static int getScreenHeight();
	static GLFWwindow* getCurrentContext();

private:
	static int screenWidth;
	static int screenHeight;
	static GLFWwindow* currentContext;
	ClientDevice();
};