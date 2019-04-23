#include "RenderiumWindow.h"

int RenderiumWindow::netWindows = 0;

RenderiumWindow::RenderiumWindow(const char* name, GLint width, GLint height, bool resizable) {
	if (RenderiumWindow::netWindows == NULL) {
		RenderiumWindow::netWindows++;
		//Init class values
		this->windowTitle = name;
		this->windowWidth = width;
		this->windowHeight = height;
		this->windowIsResizable = resizable;

		//Setup flags
		glfwInit();

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
		//Apply class values to physical context
		this->contextWindow = glfwCreateWindow(windowWidth, windowHeight, windowTitle, nullptr, nullptr);
		ClientDevice::initClientDevice(contextWindow);

		if (nullptr == this->contextWindow) {
			std::cout << "Failed to create window.\n";
			glfwTerminate();

			exit(EXIT_FAILURE);
		}

		glfwMakeContextCurrent(this->contextWindow);

		glewExperimental = GL_TRUE;

		if (GLEW_OK != glewInit()) {
			std::cout << "Failed to init GLEW\n";
			exit(EXIT_FAILURE);
		}

		glViewport(0, 0, ClientDevice::getScreenWidth(), ClientDevice::getScreenHeight());
	}
	else {
		std::cout << "Sorry, you may only create one window per program." << std::endl;
		exit(EXIT_FAILURE);
	}
}

GLFWwindow* RenderiumWindow::getContext() {
	return this->contextWindow;
}

GLint RenderiumWindow::getWidth() {
	return this->windowWidth;
}
GLint RenderiumWindow::getHeight() {
	return this->windowHeight;
}
const char* RenderiumWindow::getTitle() {
	return this->windowTitle;
}