#pragma once
#include "GLFW/glfw3.h"

class ClientDevice {
public:
	static void initClientDevice(GLFWwindow* window);
	static int getScreenWidth();
	static int getScreenHeight();

private:
	static int screenWidth;
	static int screenHeight;
	ClientDevice();
};