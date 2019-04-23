#pragma once
#include "GLFW/glfw3.h"

class EngineState {
public:
	virtual void input() = 0;
	virtual void update() = 0;
	virtual void render(GLFWwindow* window) = 0;
};