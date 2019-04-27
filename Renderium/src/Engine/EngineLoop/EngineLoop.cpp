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

	double lastTime = glfwGetTime();

	while (!glfwWindowShouldClose(ContextDevice::getContext())) {

		if (pendingState != NULL) {
			states.push(this->pendingState);
			this->pendingState = NULL;
			break;
		}

		double current = glfwGetTime();
		elapsed = current - lastTime;

		states.top()->input();
		states.top()->update(elapsed);
		states.top()->render(ContextDevice::getContext());
		glfwSwapBuffers(ContextDevice::getContext());
		glfwPollEvents();

		lastTime = current;
	}
	if (!glfwWindowShouldClose(ContextDevice::getContext())) {
		glfwSwapBuffers(ContextDevice::getContext());
		glfwPollEvents();
		run();
	}
}

int EngineLoop::netLoops = 0;