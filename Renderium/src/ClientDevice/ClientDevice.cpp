#include "ClientDevice.h"

int ClientDevice::screenWidth = NULL;
int ClientDevice::screenHeight = NULL;
struct GLFWwindow* ClientDevice::currentContext = NULL;
class EngineLoop* ClientDevice::currentLoop = NULL;

void ClientDevice::initWindow(GLFWwindow* window) {
	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
	ClientDevice::currentContext = window;
}
void ClientDevice::initLoop(class EngineLoop* loop) {
	ClientDevice::currentLoop = loop;
}
int ClientDevice::getScreenWidth() {
	return ClientDevice::screenWidth;
}
int ClientDevice::getScreenHeight() {
	return ClientDevice::screenHeight;
}
struct GLFWwindow* ClientDevice::getContext() {
	return ClientDevice::currentContext;
}
class EngineLoop* ClientDevice::getLoop() {
	return ClientDevice::currentLoop;
}