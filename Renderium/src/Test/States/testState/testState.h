#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../../../Engine/Engine.h"
#include "../../../Utilities/Utilities.h"
#include "../../STB_Image/stb_image.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../../../Engine/Entities/Entities.h"

class TestState : virtual EngineState {
private:
	//All states require override:
	void init();
	void input();
	void update(double dt);
	void render(GLFWwindow* window);
	ShaderProgram ourShader;
	EngineModel myModel;
	EngineEntity myEntity;
	unsigned int VBO, VAO, EBO;
	float rot = 1;
	float sca = 10;

	glm::mat4 model = glm::mat4(1.0f);
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection;

	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

};