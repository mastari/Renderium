#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../../../Engine/Engine.h"
#include "../../../Utilities/Utilities.h"
#include "../../STB_Image/stb_image.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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

	glm::mat4 model = glm::mat4(1.0f);
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection;

};