#include "ContextDevice.h"

int ContextDevice::screenWidth = NULL;
int ContextDevice::screenHeight = NULL;
struct GLFWwindow* ContextDevice::currentContext = NULL;
class EngineLoop* ContextDevice::currentLoop = NULL;

void ContextDevice::initWindow(GLFWwindow* window) {
	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
	ContextDevice::currentContext = window;
}
void ContextDevice::initLoop(class EngineLoop* loop) {
	ContextDevice::currentLoop = loop;
}
int ContextDevice::getScreenWidth() {
	return ContextDevice::screenWidth;
}
int ContextDevice::getScreenHeight() {
	return ContextDevice::screenHeight;
}
struct GLFWwindow* ContextDevice::getContext() {
	return ContextDevice::currentContext;
}
class EngineLoop* ContextDevice::getLoop() {
	return ContextDevice::currentLoop;
}