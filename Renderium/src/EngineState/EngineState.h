#pragma once
#include "GLFW/glfw3.h"
#include "../ClientDevice/ClientDevice.h"

class EngineState {
public:
	virtual void init() = 0;
	virtual void input() = 0;
	virtual void update() = 0;
	virtual void render(GLFWwindow* window) = 0;
};