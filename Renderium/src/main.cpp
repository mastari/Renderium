#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

const GLint WIDTH = 800, HEIGHT = 600;

int main() {
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Window", nullptr, nullptr);

	int screenW, screenH;
	glfwGetFramebufferSize(window, &screenW, &screenH);

	if (nullptr == window) {
		std::cout << "Failed to create window.\n";
		glfwTerminate();

		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;

	if (GLEW_OK != glewInit()) {
		std::cout << "Failed to init GLEW\n";
		return EXIT_FAILURE;
	}

	glViewport(0, 0, screenW, screenH);

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
		//Inputs

		glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//Logic

		//Draw

		glfwSwapBuffers(window);
	}

	return EXIT_SUCCESS;
}