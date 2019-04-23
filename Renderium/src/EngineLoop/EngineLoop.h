#pragma once
#include <GLFW/glfw3.h>
#include "../ClientDevice/ClientDevice.h"
#include "../EngineState/EngineState.h"
#include <iostream>
#include <stack>

class EngineLoop {
public:
	EngineLoop(class EngineState* state);
	void run();
	void pushState(class EngineState* nstate);
private:
	std::stack <class EngineState*> states;

	static int netLoops;
};