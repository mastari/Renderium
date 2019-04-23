#include "second.h"

void SecondState::input() {
	glfwPollEvents();
}

void SecondState::update() {

}

void SecondState::render(GLFWwindow* context) {
	glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(context);
}