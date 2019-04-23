#pragma once
#include "GLFW/glfw3.h"
#include "../EngineLoop/EngineLoop.h"


class ClientDevice {
public:
	static void initWindow(GLFWwindow* window);
	static void initLoop(class EngineLoop* loop);
	static int getScreenWidth();
	static int getScreenHeight();
	static struct GLFWwindow* getContext();
	static class EngineLoop* getLoop();

private:
	static int screenWidth;
	static int screenHeight;
	static struct GLFWwindow* currentContext;
	static class EngineLoop* currentLoop;
	ClientDevice();
};