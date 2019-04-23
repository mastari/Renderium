#include "EngineLoop.h"

EngineLoop::EngineLoop(EngineState* state) {
	if (!EngineLoop::netLoops) {
		this->states.push(state);
		EngineLoop::netLoops++;
		ContextDevice::initLoop(this);
		this->pendingState = NULL;
	}
	else {
		std::cout << "Sorry, you may only create one Engine Loop per program." << std::endl;
		exit(EXIT_FAILURE);

	}
}

void EngineLoop::pushState(EngineState* nstate) {
	this->pendingState = nstate;
}

void EngineLoop::run() {
	states.top()->init();
	while (!glfwWindowShouldClose(ContextDevice::getContext())) {
		states.top()->input();
		states.top()->update();
		states.top()->render(ContextDevice::getContext());
		if (pendingState != NULL) {
			states.push(this->pendingState);
			this->pendingState = NULL;
			states.top()->init();
		}
		glfwSwapBuffers(ContextDevice::getContext());
		glfwPollEvents();
	}
}

int EngineLoop::netLoops = 0;