#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../../../Engine/Engine.h"
#include "../../../Utilities/Utilities.h"
#include "../../STB_Image/stb_image.h"

class TestState : virtual EngineState {
private:
	//All states require override:
	void init();
	void input();
	void update();
	void render(GLFWwindow* window);

	ShaderProgram* ourShader;
	unsigned int texture;
	unsigned int VBO, VAO, EBO;

};