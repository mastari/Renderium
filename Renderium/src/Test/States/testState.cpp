#include "testState.h"

void TestState::init() {

}

void TestState::input() {
	glfwPollEvents();
}

void TestState::update() {

}

void TestState::render(GLFWwindow* context) {
	glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(context);
}