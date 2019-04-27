#pragma once
#include "../Engine.h"
#include "../../ContextDevice/ContextDevice.h"
#include <iostream>
#include <stack>

class EngineLoop {
public:
	EngineLoop(class EngineState* state);
	void run();
	void pushState(class EngineState* nstate);

	static double elapsed;
private:
	std::stack <class EngineState*> states;
	class EngineState* pendingState;

	static int netLoops;
};