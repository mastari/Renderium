#include "ClientDevice.h"

void ClientDevice::initClientDevice(GLFWwindow* window) {
	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
	ClientDevice::currentContext = window;
}
int ClientDevice::getScreenWidth() {
	return ClientDevice::screenWidth;
}
int ClientDevice::getScreenHeight() {
	return ClientDevice::screenHeight;
}

GLFWwindow* ClientDevice::getCurrentContext() {
	return ClientDevice::currentContext;
}

int ClientDevice::screenWidth = NULL;
int ClientDevice::screenHeight = NULL;
GLFWwindow* ClientDevice::currentContext = NULL;