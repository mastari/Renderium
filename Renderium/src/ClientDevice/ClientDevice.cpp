#include "ClientDevice.h"

void ClientDevice::initClientDevice(GLFWwindow* window) {
	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
}
int ClientDevice::getScreenWidth() {
	return ClientDevice::screenWidth;
}
int ClientDevice::getScreenHeight() {
	return ClientDevice::screenHeight;
}

int ClientDevice::screenWidth = NULL;
int ClientDevice::screenHeight = NULL;