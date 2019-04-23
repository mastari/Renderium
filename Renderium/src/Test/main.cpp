#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../RenderiumWindow/RenderiumWindow.h";

int main() {

	RenderiumWindow window("Sim1.0", 800, 600, true);

	while (!glfwWindowShouldClose(window.getContext())) {
		glfwPollEvents();
		//Inputs

		glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//Logic

		//Draw

		glfwSwapBuffers(window.getContext());
	}

	return EXIT_SUCCESS;
}