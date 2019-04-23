#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../../../Engine/Engine.h"
#include "../../../Utilities/Utilities.h"

class TestState : virtual EngineState {
private:
	//All states require override:
	void init();
	void input();
	void update();
	void render(GLFWwindow* window);

	ShaderProgram* ourShader;
	float vertices[9] = {
		 0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  // bottom left
		 0.0f,  0.5f, 0.0f   // top 
	};
	unsigned int VBO, VAO;

};