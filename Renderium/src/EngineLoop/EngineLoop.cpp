#include "EngineLoop.h"

EngineLoop::EngineLoop(EngineState* state) {
	if (!EngineLoop::netLoops) {
		this->states.push(state);
		EngineLoop::netLoops++;
		ClientDevice::initLoop(this);
	}
	else {
		std::cout << "Sorry, you may only create one Engine Loop per program." << std::endl;
		exit(EXIT_FAILURE);

	}
}

void EngineLoop::run() {
	while (!glfwWindowShouldClose(ClientDevice::getContext())) {
		states.top()->input();
		states.top()->update();
		states.top()->render(ClientDevice::getContext());
	}
}

int EngineLoop::netLoops = 0;