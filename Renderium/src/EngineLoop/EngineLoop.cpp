#include "EngineLoop.h"

EngineLoop::EngineLoop(EngineState* state) {
	if (!EngineLoop::netLoops) {
		this->states.push(state);
		EngineLoop::netLoops++;
	}
	else {
		std::cout << "Sorry, you may only create one Engine Loop per program." << std::endl;
		exit(EXIT_FAILURE);

	}
}

void EngineLoop::run() {
	GLFWwindow* context = ClientDevice::getCurrentContext();
	while (!glfwWindowShouldClose(context)) {
		states.top()->input();
		states.top()->update();
		states.top()->render(context);
	}
}

int EngineLoop::netLoops = 0;