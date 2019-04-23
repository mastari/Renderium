#pragma once
#include <GLFW/glfw3.h>
#include "../ClientDevice/ClientDevice.h"
#include "../EngineState/EngineState.h"
#include <iostream>
#include <stack>

class EngineLoop {
public:
	EngineLoop(EngineState* state);
	void run();
private:
	std::stack <EngineState*> states;

	static int netLoops;
};