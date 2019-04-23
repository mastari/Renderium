#pragma once
#include "../../EngineState/EngineState.h"

class SecondState : virtual EngineState {
	void input();
	void update();
	void render(GLFWwindow* window);
};