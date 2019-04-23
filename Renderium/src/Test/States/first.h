#pragma once
#include "../../EngineState/EngineState.h"

class FirstState : virtual EngineState {
	void input();
	void update();
	void render(GLFWwindow* window);
};