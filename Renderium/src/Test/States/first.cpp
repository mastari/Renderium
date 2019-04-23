#include "first.h"

void FirstState::input() {
	glfwPollEvents();
}

void FirstState::update() {

}

void FirstState::render(GLFWwindow* context) {
	glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(context);
}